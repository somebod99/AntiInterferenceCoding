/********************************************************************************
** Form generated from reading UI file 'hammingdecodewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAMMINGDECODEWIDGET_H
#define UI_HAMMINGDECODEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HammingDecodeWidget
{
public:
    QLabel *alphLabel;
    QLabel *seqLabel;
    QPushButton *alphPushButton;
    QLineEdit *alphLineEdit;
    QTextBrowser *decodingTextBrowser;
    QPushButton *seqPushButton;
    QLineEdit *seqLineEdit;
    QLabel *tittleLabel;
    QPushButton *decodePushButton;
    QPushButton *gMatrixPushButton;
    QLineEdit *gMatrixLineEdit;
    QLabel *gMatrixLabel;
    QLabel *decodeLabel;
    QLabel *decodedLabel;
    QTextBrowser *decodedTextBrowser;

    void setupUi(QWidget *HammingDecodeWidget)
    {
        if (HammingDecodeWidget->objectName().isEmpty())
            HammingDecodeWidget->setObjectName(QString::fromUtf8("HammingDecodeWidget"));
        HammingDecodeWidget->resize(807, 681);
        alphLabel = new QLabel(HammingDecodeWidget);
        alphLabel->setObjectName(QString::fromUtf8("alphLabel"));
        alphLabel->setGeometry(QRect(20, 60, 341, 31));
        QFont font;
        font.setPointSize(12);
        alphLabel->setFont(font);
        seqLabel = new QLabel(HammingDecodeWidget);
        seqLabel->setObjectName(QString::fromUtf8("seqLabel"));
        seqLabel->setGeometry(QRect(20, 280, 651, 31));
        seqLabel->setFont(font);
        alphPushButton = new QPushButton(HammingDecodeWidget);
        alphPushButton->setObjectName(QString::fromUtf8("alphPushButton"));
        alphPushButton->setGeometry(QRect(690, 100, 81, 31));
        alphPushButton->setFont(font);
        alphLineEdit = new QLineEdit(HammingDecodeWidget);
        alphLineEdit->setObjectName(QString::fromUtf8("alphLineEdit"));
        alphLineEdit->setGeometry(QRect(20, 100, 651, 31));
        alphLineEdit->setFont(font);
        decodingTextBrowser = new QTextBrowser(HammingDecodeWidget);
        decodingTextBrowser->setObjectName(QString::fromUtf8("decodingTextBrowser"));
        decodingTextBrowser->setGeometry(QRect(20, 450, 361, 131));
        QFont font1;
        font1.setPointSize(14);
        decodingTextBrowser->setFont(font1);
        seqPushButton = new QPushButton(HammingDecodeWidget);
        seqPushButton->setObjectName(QString::fromUtf8("seqPushButton"));
        seqPushButton->setGeometry(QRect(690, 320, 81, 31));
        seqPushButton->setFont(font);
        seqLineEdit = new QLineEdit(HammingDecodeWidget);
        seqLineEdit->setObjectName(QString::fromUtf8("seqLineEdit"));
        seqLineEdit->setGeometry(QRect(20, 320, 651, 31));
        seqLineEdit->setFont(font);
        tittleLabel = new QLabel(HammingDecodeWidget);
        tittleLabel->setObjectName(QString::fromUtf8("tittleLabel"));
        tittleLabel->setGeometry(QRect(300, 0, 201, 51));
        QFont font2;
        font2.setPointSize(16);
        tittleLabel->setFont(font2);
        tittleLabel->setAlignment(Qt::AlignCenter);
        decodePushButton = new QPushButton(HammingDecodeWidget);
        decodePushButton->setObjectName(QString::fromUtf8("decodePushButton"));
        decodePushButton->setGeometry(QRect(330, 630, 171, 41));
        decodePushButton->setFont(font);
        gMatrixPushButton = new QPushButton(HammingDecodeWidget);
        gMatrixPushButton->setObjectName(QString::fromUtf8("gMatrixPushButton"));
        gMatrixPushButton->setGeometry(QRect(690, 210, 81, 31));
        gMatrixPushButton->setFont(font);
        gMatrixLineEdit = new QLineEdit(HammingDecodeWidget);
        gMatrixLineEdit->setObjectName(QString::fromUtf8("gMatrixLineEdit"));
        gMatrixLineEdit->setGeometry(QRect(20, 210, 651, 31));
        gMatrixLineEdit->setFont(font);
        gMatrixLabel = new QLabel(HammingDecodeWidget);
        gMatrixLabel->setObjectName(QString::fromUtf8("gMatrixLabel"));
        gMatrixLabel->setGeometry(QRect(20, 170, 481, 31));
        gMatrixLabel->setFont(font);
        decodeLabel = new QLabel(HammingDecodeWidget);
        decodeLabel->setObjectName(QString::fromUtf8("decodeLabel"));
        decodeLabel->setGeometry(QRect(20, 430, 361, 20));
        decodeLabel->setFont(font);
        decodeLabel->setAlignment(Qt::AlignCenter);
        decodedLabel = new QLabel(HammingDecodeWidget);
        decodedLabel->setObjectName(QString::fromUtf8("decodedLabel"));
        decodedLabel->setGeometry(QRect(410, 430, 361, 20));
        decodedLabel->setFont(font);
        decodedLabel->setAlignment(Qt::AlignCenter);
        decodedTextBrowser = new QTextBrowser(HammingDecodeWidget);
        decodedTextBrowser->setObjectName(QString::fromUtf8("decodedTextBrowser"));
        decodedTextBrowser->setGeometry(QRect(410, 450, 361, 131));
        decodedTextBrowser->setFont(font1);

        retranslateUi(HammingDecodeWidget);

        QMetaObject::connectSlotsByName(HammingDecodeWidget);
    } // setupUi

    void retranslateUi(QWidget *HammingDecodeWidget)
    {
        HammingDecodeWidget->setWindowTitle(QCoreApplication::translate("HammingDecodeWidget", "Form", nullptr));
        alphLabel->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \321\201 \320\260\320\273\321\204\320\260\320\262\320\270\321\202\320\276\320\274", nullptr));
        seqLabel->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\273\321\203 \321\201 \320\264\320\265\320\272\320\276\320\264\320\270\321\200\321\203\320\265\320\274\320\276\320\271 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214\321\216", nullptr));
        alphPushButton->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        seqPushButton->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        seqLineEdit->setText(QString());
        tittleLabel->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        decodePushButton->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\224\320\265\320\272\320\276\320\264\320\270\321\200\320\276\320\260\321\202\321\214", nullptr));
        gMatrixPushButton->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        gMatrixLineEdit->setText(QString());
        gMatrixLabel->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\273\321\203 \321\201 \320\277\320\276\321\200\320\260\320\266\320\264\320\260\321\216\321\211\320\265\320\271 \320\274\320\260\321\202\321\200\320\270\321\206\320\265\320\271", nullptr));
        decodeLabel->setText(QCoreApplication::translate("HammingDecodeWidget", "\320\264\320\265\320\272\320\276\320\264\320\270\321\200\321\203\320\265\320\274\320\260\321\217 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        decodedLabel->setText(QCoreApplication::translate("HammingDecodeWidget", "\321\200\320\260\321\201\320\272\320\276\320\264\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\260\321\217 \320\277\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HammingDecodeWidget: public Ui_HammingDecodeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAMMINGDECODEWIDGET_H
