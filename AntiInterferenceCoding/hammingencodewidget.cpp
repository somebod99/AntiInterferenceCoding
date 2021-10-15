#include "hammingencodewidget.h"
#include "ui_hammingencodewidget.h"

#include "HammingAlgorithm.h"

#include <fstream>
#include <sstream>

#include <QFileDialog>
#include <QMessageBox>

HammingEncodeWidget::HammingEncodeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HammingEncodeWidget)
{
    ui->setupUi(this);

    connect(ui->alphPushButton, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->gMatrixPushButton, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->seqPushButton, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->encodePushButton, SIGNAL(clicked()), this, SLOT(slotOnClickEncodeButton()));
    connect(ui->ChangePushButton, SIGNAL(clicked()), this, SLOT(slotOnClickChangeButton()));
}

HammingEncodeWidget::~HammingEncodeWidget()
{
    delete ui;
}

void HammingEncodeWidget::slotOnClickFileBrows()
{
    if(sender()->objectName() == "alphPushButton")
        ui->alphLineEdit->setText(QFileDialog::getOpenFileName(this, "Files"));
    else if(sender()->objectName() == "gMatrixPushButton")
        ui->gMatrixLineEdit->setText(QFileDialog::getOpenFileName(this, "Files"));
    else
        ui->seqLineEdit->setText(QFileDialog::getOpenFileName(this, "Files"));
}

void HammingEncodeWidget::slotOnClickEncodeButton()
{
    try
    {
        if(ui->alphLineEdit->text() == "")
            throw "Error: enter the path to the file with the alphabet";
        if(ui->gMatrixLineEdit->text() == "")
            throw "Error: enter the path to the file with G matrix";
        if(ui->seqLineEdit->text() == "")
            throw "Error: enter the path to the file with the encoded sequence";

        HammingEncoder encoder(ui->gMatrixLineEdit->text().toStdString(), ui->alphLineEdit->text().toStdString());
        std::string encoding_str = ReadFromTxtFile(ui->seqLineEdit->text().toStdString());
        auto res = encoder.EncodeString(encoding_str);
        WriteToBinaryFile("out.bin", res);

        ui->encodingTextBrowser->setText(QString::fromStdString(encoding_str));

        std::stringstream str_stream;

        for(const auto& bit : res)
            str_stream << bit;

        ui->encodedTextEdit->setText(QString::fromStdString(str_stream.str()));

        QMessageBox::information(this, "", "Sequence encoded successfully");
    }
    catch (const char* er)
    {
        QMessageBox::critical(this,"ERROR", er);
    }
}

void HammingEncodeWidget::slotOnClickChangeButton()
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
