#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "decodewidget.h"
#include "encodewidget.h"
#include "hammingdecodewidget.h"
#include "hammingencodewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget = new EncodeWidget(this);
    ui->centralwidget->setGeometry(0, this->menuBar()->geometry().height(), this->geometry().width(), this->geometry().height());

    connect(ui->GilberMoorEncode, SIGNAL(triggered()), this, SLOT(slotSetWidget()));
    connect(ui->GilberMoorDecode, SIGNAL(triggered()), this, SLOT(slotSetWidget()));
    connect(ui->HammingEncode, SIGNAL(triggered()), this, SLOT(slotSetWidget()));
    connect(ui->HammingDecode, SIGNAL(triggered()), this, SLOT(slotSetWidget()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotSetWidget()
{
    delete this->ui->centralwidget;

    if(sender()->objectName() == "GilberMoorEncode")
        this->ui->centralwidget = new EncodeWidget(this);
    else if(sender()->objectName() == "GilberMoorDecode")
        this->ui->centralwidget = new DecodeWidget(this);
    else if(sender()->objectName() == "HammingEncode")
        this->ui->centralwidget = new HammingEncodeWidget(this);
    else if(sender()->objectName() == "HammingDecode")
        this->ui->centralwidget = new HammingDecodeWidget(this);

    this->ui->centralwidget->setGeometry(0, this->menuBar()->geometry().height(), this->geometry().width(), this->geometry().height());
    this->ui->centralwidget->show();
}
