/********************************************************************************
** Form generated from reading UI file 'hammingencodewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAMMINGENCODEWIDGET_H
#define UI_HAMMINGENCODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HammingEncodeWidget
{
public:
    QLabel *tittleLabel;
    QPushButton *alphPushButton;
    QPushButton *seqPushButton;
    QLineEdit *alphLineEdit;
    QLineEdit *seqLineEdit;
    QLabel *alphLabel;
    QLabel *seqLabel;
    QTextBrowser *encodingTextBrowser;
    QTextEdit *encodedTextEdit;
    QPushButton *encodePushButton;
    QPushButton *ChangePushButton;
    QLabel *gMatrixLabel;
    QPushButton *gMatrixPushButton;
    QLineEdit *gMatrixLineEdit;
    QLabel *encodeLabel;
    QLabel *encodedLabel;

    void setupUi(QWidget *HammingEncodeWidget)
    {
        if (HammingEncodeWidget->objectName().isEmpty())
            HammingEncodeWidget->setObjectName(QString::fromUtf8("HammingEncodeWidget"));
        HammingEncodeWidget->resize(807, 681);
        QFont font;
        font.setPointSize(20);
        HammingEncodeWidget->setFont(font);
        tittleLabel = new QLabel(HammingEncodeWidget);
        tittleLabel->setObjectName(QString::fromUtf8("tittleLabel"));
        tittleLabel->setGeometry(QRect(320, 0, 181, 51));
        QFont font1;
        font1.setPointSize(14);
        tittleLabel->setFont(font1);
        tittleLabel->setAlignment(Qt::AlignCenter);
        alphPushButton = new QPushButton(HammingEncodeWidget);
        alphPushButton->setObjectName(QString::fromUtf8("alphPushButton"));
        alphPushButton->setGeometry(QRect(690, 100, 81, 31));
        QFont font2;
        font2.setPointSize(12);
        alphPushButton->setFont(font2);
        seqPushButton = new QPushButton(HammingEncodeWidget);
        seqPushButton->setObjectName(QString::fromUtf8("seqPushButton"));
        seqPushButton->setGeometry(QRect(690, 320, 81, 31));
        seqPushButton->setFont(font2);
        alphLineEdit = new QLineEdit(HammingEncodeWidget);
        alphLineEdit->setObjectName(QString::fromUtf8("alphLineEdit"));
        alphLineEdit->setGeometry(QRect(20, 100, 651, 31));
        alphLineEdit->setFont(font2);
        seqLineEdit = new QLineEdit(HammingEncodeWidget);
        seqLineEdit->setObjectName(QString::fromUtf8("seqLineEdit"));
        seqLineEdit->setGeometry(QRect(20, 320, 651, 31));
        seqLineEdit->setFont(font2);
        alphLabel = new QLabel(HammingEncodeWidget);
        alphLabel->setObjectName(QString::fromUtf8("alphLabel"));
        alphLabel->setGeometry(QRect(20, 60, 341, 31));
        alphLabel->setFont(font2);
        seqLabel = new QLabel(HammingEncodeWidget);
        seqLabel->setObjectName(QString::fromUtf8("seqLabel"));
        seqLabel->setGeometry(QRect(20, 280, 611, 31));
        seqLabel->setFont(font2);
        encodingTextBrowser = new QTextBrowser(HammingEncodeWidget);
        encodingTextBrowser->setObjectName(QString::fromUtf8("encodingTextBrowser"));
        encodingTextBrowser->setGeometry(QRect(20, 450, 361, 131));
        encodingTextBrowser->setFont(font1);
        encodedTextEdit = new QTextEdit(HammingEncodeWidget);
        encodedTextEdit->setObjectName(QString::fromUtf8("encodedTextEdit"));
        encodedTextEdit->setGeometry(QRect(410, 450, 361, 131));
        encodedTextEdit->setFont(font1);
        encodePushButton = new QPushButton(HammingEncodeWidget);
        encodePushButton->setObjectName(QString::fromUtf8("encodePushButton"));
        encodePushButton->setGeometry(QRect(330, 630, 171, 41));
        encodePushButton->setFont(font2);
        ChangePushButton = new QPushButton(HammingEncodeWidget);
        ChangePushButton->setObjectName(QString::fromUtf8("ChangePushButton"));
        ChangePushButton->setGeometry(QRect(520, 580, 121, 31));
        ChangePushButton->setFont(font2);
        gMatrixLabel = new QLabel(HammingEncodeWidget);
        gMatrixLabel->setObjectName(QString::fromUtf8("gMatrixLabel"));
        gMatrixLabel->setGeometry(QRect(20, 170, 481, 31));
        gMatrixLabel->setFont(font2);
        gMatrixPushButton = new QPushButton(HammingEncodeWidget);
        gMatrixPushButton->setObjectName(QString::fromUtf8("gMatrixPushButton"));
        gMatrixPushButton->setGeometry(QRect(690, 210, 81, 31));
        gMatrixPushButton->setFont(font2);
        gMatrixLineEdit = new QLineEdit(HammingEncodeWidget);
        gMatrixLineEdit->setObjectName(QString::fromUtf8("gMatrixLineEdit"));
        gMatrixLineEdit->setGeometry(QRect(20, 210, 651, 31));
        gMatrixLineEdit->setFont(font2);
        encodeLabel = new QLabel(HammingEncodeWidget);
        encodeLabel->setObjectName(QString::fromUtf8("encodeLabel"));
        encodeLabel->setGeometry(QRect(20, 430, 361, 20));
        encodeLabel->setFont(font2);
        encodeLabel->setAlignment(Qt::AlignCenter);
        encodedLabel = new QLabel(HammingEncodeWidget);
        encodedLabel->setObjectName(QString::fromUtf8("encodedLabel"));
        encodedLabel->setGeometry(QRect(410, 430, 361, 20));
        encodedLabel->setFont(font2);
        encodedLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(HammingEncodeWidget);

        QMetaObject::connectSlotsByName(HammingEncodeWidget);
    } // setupUi

    void retranslateUi(QWidget *HammingEncodeWidget)
    {
        HammingEncodeWidget->setWindowTitle(QCoreApplication::translate("HammingEncodeWidget", "Form", nullptr));
        tittleLabel->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\232\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        alphPushButton->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        seqPushButton->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        seqLineEdit->setText(QString());
        alphLabel->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\201 \320\260\320\273\321\204\320\260\320\262\320\270\321\202\320\276\320\274", nullptr));
        seqLabel->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\273\321\203 \321\201 \320\272\320\276\320\264\320\270\321\200\321\203\320\265\320\274\320\276\320\271 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214\321\216", nullptr));
        encodePushButton->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\227\320\260\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        ChangePushButton->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        gMatrixLabel->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\273\321\203 \321\201 \320\277\320\276\321\200\320\260\320\266\320\264\320\260\321\216\321\211\320\265\320\271 \320\274\320\260\321\202\321\200\320\270\321\206\320\265\320\271", nullptr));
        gMatrixPushButton->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        gMatrixLineEdit->setText(QString());
        encodeLabel->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\272\320\276\320\264\320\270\321\200\321\203\320\265\320\274\320\260\321\217 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        encodedLabel->setText(QCoreApplication::translate("HammingEncodeWidget", "\320\267\320\260\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\260\321\217 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HammingEncodeWidget: public Ui_HammingEncodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAMMINGENCODEWIDGET_H
