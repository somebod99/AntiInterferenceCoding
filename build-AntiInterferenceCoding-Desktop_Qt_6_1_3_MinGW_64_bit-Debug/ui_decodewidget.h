/********************************************************************************
** Form generated from reading UI file 'decodewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECODEWIDGET_H
#define UI_DECODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DecodeWidget
{
public:
    QLabel *encode_seq_label;
    QPushButton *decode_button;
    QLineEdit *alphabet_edit;
    QLabel *alphabet_label;
    QLineEdit *encode_seq_edit;
    QPushButton *encode_seq_file_dialog_button;
    QLabel *decode_label;
    QPushButton *alphabet_file_dialog_button;
    QTextBrowser *decodeTextBrowser;
    QTextBrowser *errorsTextBrowser;
    QLabel *decodeSeqLabel;
    QLabel *errorsLabel;

    void setupUi(QWidget *DecodeWidget)
    {
        if (DecodeWidget->objectName().isEmpty())
            DecodeWidget->setObjectName(QString::fromUtf8("DecodeWidget"));
        DecodeWidget->resize(807, 681);
        encode_seq_label = new QLabel(DecodeWidget);
        encode_seq_label->setObjectName(QString::fromUtf8("encode_seq_label"));
        encode_seq_label->setGeometry(QRect(20, 170, 511, 31));
        QFont font;
        font.setPointSize(12);
        encode_seq_label->setFont(font);
        decode_button = new QPushButton(DecodeWidget);
        decode_button->setObjectName(QString::fromUtf8("decode_button"));
        decode_button->setGeometry(QRect(330, 630, 171, 41));
        decode_button->setFont(font);
        alphabet_edit = new QLineEdit(DecodeWidget);
        alphabet_edit->setObjectName(QString::fromUtf8("alphabet_edit"));
        alphabet_edit->setGeometry(QRect(20, 100, 651, 31));
        alphabet_edit->setFont(font);
        alphabet_label = new QLabel(DecodeWidget);
        alphabet_label->setObjectName(QString::fromUtf8("alphabet_label"));
        alphabet_label->setGeometry(QRect(20, 60, 261, 31));
        alphabet_label->setFont(font);
        encode_seq_edit = new QLineEdit(DecodeWidget);
        encode_seq_edit->setObjectName(QString::fromUtf8("encode_seq_edit"));
        encode_seq_edit->setGeometry(QRect(20, 210, 651, 31));
        encode_seq_edit->setFont(font);
        encode_seq_file_dialog_button = new QPushButton(DecodeWidget);
        encode_seq_file_dialog_button->setObjectName(QString::fromUtf8("encode_seq_file_dialog_button"));
        encode_seq_file_dialog_button->setGeometry(QRect(690, 210, 81, 31));
        encode_seq_file_dialog_button->setFont(font);
        decode_label = new QLabel(DecodeWidget);
        decode_label->setObjectName(QString::fromUtf8("decode_label"));
        decode_label->setGeometry(QRect(300, 0, 201, 51));
        QFont font1;
        font1.setPointSize(16);
        decode_label->setFont(font1);
        decode_label->setAlignment(Qt::AlignCenter);
        alphabet_file_dialog_button = new QPushButton(DecodeWidget);
        alphabet_file_dialog_button->setObjectName(QString::fromUtf8("alphabet_file_dialog_button"));
        alphabet_file_dialog_button->setGeometry(QRect(690, 100, 81, 31));
        alphabet_file_dialog_button->setFont(font);
        decodeTextBrowser = new QTextBrowser(DecodeWidget);
        decodeTextBrowser->setObjectName(QString::fromUtf8("decodeTextBrowser"));
        decodeTextBrowser->setGeometry(QRect(20, 310, 371, 241));
        QFont font2;
        font2.setPointSize(14);
        decodeTextBrowser->setFont(font2);
        errorsTextBrowser = new QTextBrowser(DecodeWidget);
        errorsTextBrowser->setObjectName(QString::fromUtf8("errorsTextBrowser"));
        errorsTextBrowser->setGeometry(QRect(410, 310, 371, 241));
        errorsTextBrowser->setFont(font2);
        decodeSeqLabel = new QLabel(DecodeWidget);
        decodeSeqLabel->setObjectName(QString::fromUtf8("decodeSeqLabel"));
        decodeSeqLabel->setGeometry(QRect(20, 270, 371, 31));
        decodeSeqLabel->setFont(font);
        decodeSeqLabel->setAlignment(Qt::AlignCenter);
        errorsLabel = new QLabel(DecodeWidget);
        errorsLabel->setObjectName(QString::fromUtf8("errorsLabel"));
        errorsLabel->setGeometry(QRect(410, 280, 371, 20));
        errorsLabel->setFont(font);
        errorsLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(DecodeWidget);

        QMetaObject::connectSlotsByName(DecodeWidget);
    } // setupUi

    void retranslateUi(QWidget *DecodeWidget)
    {
        DecodeWidget->setWindowTitle(QCoreApplication::translate("DecodeWidget", "Form", nullptr));
        encode_seq_label->setText(QCoreApplication::translate("DecodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\201 \320\267\320\260\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\276\320\271 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214\321\216", nullptr));
        decode_button->setText(QCoreApplication::translate("DecodeWidget", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        alphabet_label->setText(QCoreApplication::translate("DecodeWidget", "\320\237\321\203\321\201\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\201 \320\260\320\273\321\204\320\260\320\262\320\270\321\202\320\276\320\274", nullptr));
        encode_seq_file_dialog_button->setText(QCoreApplication::translate("DecodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        decode_label->setText(QCoreApplication::translate("DecodeWidget", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        alphabet_file_dialog_button->setText(QCoreApplication::translate("DecodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        decodeSeqLabel->setText(QCoreApplication::translate("DecodeWidget", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\321\203\320\265\320\274\320\260\321\217 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        errorsLabel->setText(QCoreApplication::translate("DecodeWidget", "\320\236\321\210\320\270\320\261\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DecodeWidget: public Ui_DecodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECODEWIDGET_H
