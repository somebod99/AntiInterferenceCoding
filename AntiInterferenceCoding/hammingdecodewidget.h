#ifndef HAMMINGDECODEWIDGET_H
#define HAMMINGDECODEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class HammingDecodeWidget;
}
QT_END_NAMESPACE


class HammingDecodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HammingDecodeWidget(QWidget *parent = nullptr);
    ~HammingDecodeWidget();

public slots:
    void slotOnClickFileBrows();
    void slotOnClickDecodeButton();

private:
    Ui::HammingDecodeWidget *ui;
};

#endif // HAMMINGDECODEWIDGET_H
