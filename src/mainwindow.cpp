#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isTextHidden(true)
{
    ui->setupUi(this);
    ui->label->hide();
    QObject::connect(ui->pushButton, &QAbstractButton::pressed,
                     this, &MainWindow::toggleText);
    showMaximized();
}

void MainWindow::toggleText()
{
    isTextHidden = !isTextHidden;
    if (isTextHidden)
        ui->label->hide();
    else
        ui->label->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

