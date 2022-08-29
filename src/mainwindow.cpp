#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ButtonRWP_clicked()
{
    this->hide();
    if(!rwp)
        rwp = new Rawalpindi(this);
    rwp->show();
}


void MainWindow::on_ButtonLHR_clicked()
{
    this->hide();
    if(!lhr)
        lhr = new Lahore(this);
    lhr->show();
}


void MainWindow::on_ButtonPAK_clicked()
{
    this->hide();
    if(!pak)
        pak = new Pakistan(this);
    pak->show();
}

