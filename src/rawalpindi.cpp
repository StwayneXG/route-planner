#include "rawalpindi.h"
#include "ui_rawalpindi.h"
#include "Algorithm.h"
#include <QThread>

Rawalpindi::Rawalpindi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rawalpindi)
{
    ReadFile("D:\\Temp\\Dijktra\\Rawalpindi_Map.txt", RawalpindiGraph);
    Parent = parent;
    ui->setupUi(this);
}

Rawalpindi::~Rawalpindi()
{
    delete ui;
}

void Rawalpindi::on_ButtonFIND_clicked()
{
    string Start = ui->ComboBoxSTART->currentText().toStdString();
    string End = ui->ComboBoxEND->currentText().toStdString();

    ui->textPath->setText(QString::fromStdString(DijkstasAlgorithm(RawalpindiGraph,Start,End)));
}


void Rawalpindi::on_ButtonBACK_clicked()
{
    this->hide();
    QThread::msleep(200);
    Parent->show();
}

