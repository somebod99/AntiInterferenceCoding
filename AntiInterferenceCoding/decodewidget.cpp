#include "decodewidget.h"
#include "ui_decodewidget.h"

#include "GilberMoorParityCheck.h"
#include <fstream>

#include <QFileDialog>
#include <QMessageBox>

DecodeWidget::DecodeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DecodeWidget)
{
    ui->setupUi(this);

    connect(ui->alphabet_file_dialog_button, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->encode_seq_file_dialog_button, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->decode_button, SIGNAL(clicked()), this, SLOT(slotOnClickDecodeButton()));
}

DecodeWidget::~DecodeWidget()
{
    delete ui;
}

void DecodeWidget::slotOnClickFileBrows()
{
    if(sender()->objectName() == "alphabet_file_dialog_button")
        ui->alphabet_edit->setText(QFileDialog::getOpenFileName(this, "Files"));
    else
        ui->encode_seq_edit->setText(QFileDialog::getOpenFileName(this, "Files"));
}

void DecodeWidget::slotOnClickDecodeButton()
{
    try
    {
        if(ui->alphabet_edit->text() == "")
            throw "Error: enter the path to the file with the alphabet";
        if(ui->encode_seq_edit->text() == "")
            throw "Error: enter the path to the file with the encoded sequence";

        GilberMoorDecoder decoder(ui->alphabet_edit->text().toStdString());
        std::string errors;
        std::string res = decoder.DecodeFromBinaryFileWithParityCheck(ui->encode_seq_edit->text().toStdString(), errors);

        ui->decodeTextBrowser->setText(QString::fromStdString(res));
        ui->errorsTextBrowser->setText(QString::fromStdString(errors));

        QMessageBox::information(this, "", "Sequence decoded successfully");

        std::ofstream file("out.txt");
        file << res;
        file.close();
    }
    catch (const char* er)
    {
        QMessageBox::critical(this,"ERROR", er);
    }
}
