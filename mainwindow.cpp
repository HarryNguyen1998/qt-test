#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPoint buttonHalfSize = QPoint(ui->pushButton->geometry().width() / 2,
                                   ui->pushButton->geometry().height() / 2);

    ui->label->hide();
    QObject::connect(ui->pushButton, &QAbstractButton::pressed,
                     this, &MainWindow::showText);
    ui->pushButton->move(geometry().center()
                         - buttonHalfSize);

}

void MainWindow::showText()
{
    ui->label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

