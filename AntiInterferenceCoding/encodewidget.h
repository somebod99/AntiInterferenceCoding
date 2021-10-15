#ifndef ENCODEWIDGET_H
#define ENCODEWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class EncodeWidget;
}
QT_END_NAMESPACE


class EncodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EncodeWidget(QWidget *parent = nullptr);
    ~EncodeWidget();

public slots:
    void slotOnClickFileBrows();
    void slotOnClickEncodeButton();
    void slotOnClickChangeButton();

private:
    Ui::EncodeWidget *ui;
};

#endif // ENCODEWIDGET_H
