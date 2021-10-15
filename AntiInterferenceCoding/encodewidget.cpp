#include "encodewidget.h"
#include "ui_encodewidget.h"

#include "GilberMoorParityCheck.h"
#include <sstream>

#include <QFileDialog>
#include <QMessageBox>

EncodeWidget::EncodeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EncodeWidget)
{
    ui->setupUi(this);

    connect(ui->alphabet_file_dialog_button, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->encode_seq_file_dialog_button, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->encode_button, SIGNAL(clicked()), this, SLOT(slotOnClickEncodeButton()));
    connect(ui->changePushButton, SIGNAL(clicked()), this, SLOT(slotOnClickChangeButton()));
}

EncodeWidget::~EncodeWidget()
{
    delete ui;
}

void EncodeWidget::slotOnClickFileBrows()
{
    if(sender()->objectName() == "alphabet_file_dialog_button")
        ui->alphabet_edit->setText(QFileDialog::getOpenFileName(this, "Files"));
    else
        ui->encode_seq_edit->setText(QFileDialog::getOpenFileName(this, "Files"));
}

void EncodeWidget::slotOnClickEncodeButton()
{
    try
    {
        if(ui->alphabet_edit->text() == "")
            throw "Error: enter the path to the file with the alphabet";
        if(ui->encode_seq_edit->text() == "")
            throw "Error: enter the path to the file with the sequence to encode";

        GilberMoorEncoder encoder(ui->alphabet_edit->text().toStdString());
        std::vector<bool> res = encoder.EncodeFromTxtFileWithParityCheck(ui->encode_seq_edit->text().toStdString());
        WriteToBinaryFile("out.bin", res);

        std::map<std::string, std::vector<bool>> codes = encoder.getCodes();
        std::stringstream str_stream;

        for(const auto& key_value : codes)
        {
            str_stream << key_value.first << ": ";

            for(const auto& bit : key_value.second)
            {
                str_stream << bit;
            }

            str_stream << '\n';
        }

        ui->codesTextBrowser->setText(QString::fromStdString(str_stream.str()));

        std::stringstream ss;

        for(const auto& bit : res)
            ss << bit;

        ui->encodedTextEdit->setText(QString::fromStdString(ss.str()));

        QMessageBox::information(this, "", "Sequence encoded successfully");
    }
    catch(const char* er)
    {
        QMessageBox::critical(this,"ERROR", er);
    }
}

void EncodeWidget::slotOnClickChangeButton()
{
    std::vector<bool> res;

    try
    {
        for(const auto& symbol : ui->encodedTextEdit->toPlainText())
        {
            if(symbol == '0')
                res.push_back(false);
            else if(symbol == '1')
                res.push_back(true);
            else
                throw "Incorrect symbol in encoded seaquence";
        }

        WriteToBinaryFile("out.bin", res);
    }
    catch (const char* er)
    {
        QMessageBox::critical(this,"ERROR", er);
    }
}
