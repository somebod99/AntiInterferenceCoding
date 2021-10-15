#ifndef DECODEWIDGET_H
#define DECODEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class DecodeWidget;
}
QT_END_NAMESPACE


class DecodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DecodeWidget(QWidget *parent = nullptr);
    ~DecodeWidget();

public slots:
    void slotOnClickFileBrows();
    void slotOnClickDecodeButton();

private:
    Ui::DecodeWidget *ui;
};

#endif // DECODEWIDGET_H
