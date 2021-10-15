/********************************************************************************
** Form generated from reading UI file 'encodewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENCODEWIDGET_H
#define UI_ENCODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EncodeWidget
{
public:
    QPushButton *alphabet_file_dialog_button;
    QPushButton *encode_button;
    QLabel *encode_label;
    QLineEdit *encode_seq_edit;
    QPushButton *encode_seq_file_dialog_button;
    QLineEdit *alphabet_edit;
    QTextBrowser *codesTextBrowser;
    QLabel *alphabet_label;
    QLabel *sencode_seq_label;
    QTextEdit *encodedTextEdit;
    QPushButton *changePushButton;
    QLabel *symbolsAndCodeslabel;
    QLabel *encodedLabel;

    void setupUi(QWidget *EncodeWidget)
    {
        if (EncodeWidget->objectName().isEmpty())
            EncodeWidget->setObjectName(QString::fromUtf8("EncodeWidget"));
        EncodeWidget->resize(807, 681);
        alphabet_file_dialog_button = new QPushButton(EncodeWidget);
        alphabet_file_dialog_button->setObjectName(QString::fromUtf8("alphabet_file_dialog_button"));
        alphabet_file_dialog_button->setGeometry(QRect(690, 100, 81, 31));
        QFont font;
        font.setPointSize(12);
        alphabet_file_dialog_button->setFont(font);
        encode_button = new QPushButton(EncodeWidget);
        encode_button->setObjectName(QString::fromUtf8("encode_button"));
        encode_button->setGeometry(QRect(330, 630, 171, 41));
        encode_button->setFont(font);
        encode_label = new QLabel(EncodeWidget);
        encode_label->setObjectName(QString::fromUtf8("encode_label"));
        encode_label->setGeometry(QRect(320, 0, 181, 51));
        QFont font1;
        font1.setPointSize(16);
        encode_label->setFont(font1);
        encode_label->setAlignment(Qt::AlignCenter);
        encode_seq_edit = new QLineEdit(EncodeWidget);
        encode_seq_edit->setObjectName(QString::fromUtf8("encode_seq_edit"));
        encode_seq_edit->setGeometry(QRect(20, 210, 651, 31));
        encode_seq_edit->setFont(font);
        encode_seq_file_dialog_button = new QPushButton(EncodeWidget);
        encode_seq_file_dialog_button->setObjectName(QString::fromUtf8("encode_seq_file_dialog_button"));
        encode_seq_file_dialog_button->setGeometry(QRect(690, 210, 81, 31));
        encode_seq_file_dialog_button->setFont(font);
        alphabet_edit = new QLineEdit(EncodeWidget);
        alphabet_edit->setObjectName(QString::fromUtf8("alphabet_edit"));
        alphabet_edit->setGeometry(QRect(20, 100, 651, 31));
        alphabet_edit->setFont(font);
        codesTextBrowser = new QTextBrowser(EncodeWidget);
        codesTextBrowser->setObjectName(QString::fromUtf8("codesTextBrowser"));
        codesTextBrowser->setEnabled(true);
        codesTextBrowser->setGeometry(QRect(20, 310, 371, 231));
        QFont font2;
        font2.setPointSize(14);
        codesTextBrowser->setFont(font2);
        alphabet_label = new QLabel(EncodeWidget);
        alphabet_label->setObjectName(QString::fromUtf8("alphabet_label"));
        alphabet_label->setGeometry(QRect(20, 60, 251, 31));
        alphabet_label->setFont(font);
        sencode_seq_label = new QLabel(EncodeWidget);
        sencode_seq_label->setObjectName(QString::fromUtf8("sencode_seq_label"));
        sencode_seq_label->setGeometry(QRect(20, 170, 591, 31));
        sencode_seq_label->setFont(font);
        encodedTextEdit = new QTextEdit(EncodeWidget);
        encodedTextEdit->setObjectName(QString::fromUtf8("encodedTextEdit"));
        encodedTextEdit->setGeometry(QRect(410, 310, 371, 231));
        encodedTextEdit->setFont(font2);
        changePushButton = new QPushButton(EncodeWidget);
        changePushButton->setObjectName(QString::fromUtf8("changePushButton"));
        changePushButton->setGeometry(QRect(530, 540, 121, 31));
        changePushButton->setFont(font);
        symbolsAndCodeslabel = new QLabel(EncodeWidget);
        symbolsAndCodeslabel->setObjectName(QString::fromUtf8("symbolsAndCodeslabel"));
        symbolsAndCodeslabel->setGeometry(QRect(20, 280, 371, 16));
        symbolsAndCodeslabel->setFont(font);
        symbolsAndCodeslabel->setAlignment(Qt::AlignCenter);
        encodedLabel = new QLabel(EncodeWidget);
        encodedLabel->setObjectName(QString::fromUtf8("encodedLabel"));
        encodedLabel->setGeometry(QRect(414, 280, 361, 20));
        encodedLabel->setFont(font);
        encodedLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(EncodeWidget);

        QMetaObject::connectSlotsByName(EncodeWidget);
    } // setupUi

    void retranslateUi(QWidget *EncodeWidget)
    {
        EncodeWidget->setWindowTitle(QCoreApplication::translate("EncodeWidget", "Form", nullptr));
        alphabet_file_dialog_button->setText(QCoreApplication::translate("EncodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        encode_button->setText(QCoreApplication::translate("EncodeWidget", "\320\227\320\260\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        encode_label->setText(QCoreApplication::translate("EncodeWidget", "\320\232\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        encode_seq_file_dialog_button->setText(QCoreApplication::translate("EncodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        alphabet_label->setText(QCoreApplication::translate("EncodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\201 \320\260\320\273\321\204\320\260\320\262\320\270\321\202\320\276\320\274", nullptr));
        sencode_seq_label->setText(QCoreApplication::translate("EncodeWidget", "\320\237\321\203\321\201\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\201 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214\321\216 \320\264\320\273\321\217 \320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        changePushButton->setText(QCoreApplication::translate("EncodeWidget", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        symbolsAndCodeslabel->setText(QCoreApplication::translate("EncodeWidget", "\320\241\320\270\320\274\320\262\320\276\320\273\321\213 \320\270 \320\270\321\205 \320\272\320\276\320\264\321\213", nullptr));
        encodedLabel->setText(QCoreApplication::translate("EncodeWidget", "\320\227\320\260\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\260\321\217 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EncodeWidget: public Ui_EncodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENCODEWIDGET_H
