#ifndef HAMMINGENCODEWIDGET_H
#define HAMMINGENCODEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class HammingEncodeWidget;
}
QT_END_NAMESPACE


class HammingEncodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HammingEncodeWidget(QWidget *parent = nullptr);
    ~HammingEncodeWidget();

public slots:
    void slotOnClickFileBrows();
    void slotOnClickEncodeButton();
    void slotOnClickChangeButton();

private:
    Ui::HammingEncodeWidget *ui;
};

#endif // HAMMINGENCODEWIDGET_H
