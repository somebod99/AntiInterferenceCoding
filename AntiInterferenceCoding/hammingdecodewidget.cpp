#include "hammingdecodewidget.h"
#include "ui_hammingdecodewidget.h"

#include "HammingAlgorithm.h"

#include <fstream>
#include <sstream>

#include <QFileDialog>
#include <QMessageBox>

HammingDecodeWidget::HammingDecodeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HammingDecodeWidget)
{
    ui->setupUi(this);

    connect(ui->alphPushButton, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->gMatrixPushButton, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->seqPushButton, SIGNAL(clicked()), this, SLOT(slotOnClickFileBrows()));
    connect(ui->decodePushButton, SIGNAL(clicked()), this, SLOT(slotOnClickDecodeButton()));
}

HammingDecodeWidget::~HammingDecodeWidget()
{
    delete ui;
}

void HammingDecodeWidget::slotOnClickFileBrows()
{
    if(sender()->objectName() == "alphPushButton")
        ui->alphLineEdit->setText(QFileDialog::getOpenFileName(this, "Files"));
    else if(sender()->objectName() == "gMatrixPushButton")
        ui->gMatrixLineEdit->setText(QFileDialog::getOpenFileName(this, "Files"));
    else
        ui->seqLineEdit->setText(QFileDialog::getOpenFileName(this, "Files"));
}

void HammingDecodeWidget::slotOnClickDecodeButton()
{
    try
    {
        if(ui->alphLineEdit->text() == "")
            throw "Error: enter the path to the file with the alphabet";
        if(ui->gMatrixLineEdit->text() == "")
            throw "Error: enter the path to the file with G matrix";
        if(ui->seqLineEdit->text() == "")
            throw "Error: enter the path to the file with the encoded sequence";

        HammingDecoder decoder(ui->gMatrixLineEdit->text().toStdString(), ui->alphLineEdit->text().toStdString());
        auto decoding_seq = ReadFromBinaryFile(ui->seqLineEdit->text().toStdString());
        std::string errors;
        std::string res = decoder.DecodeBinarySequence(decoding_seq, errors);

        std::stringstream str_stream;

        for(const auto& bit : decoding_seq)
            str_stream << bit;

        ui->decodingTextBrowser->setText(QString::fromStdString(str_stream.str()));
        ui->decodedTextBrowser->setText(QString::fromStdString(res));

        if(errors.size())
            QMessageBox::warning(this, "", errors.c_str());
        else
            QMessageBox::information(this, "", "Sequence decoded successfully");
    }
    catch (const char* er)
    {
        QMessageBox::critical(this,"ERROR", er);
    }
}
