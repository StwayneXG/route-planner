#include "pakistan.h"
#include "ui_pakistan.h"
#include <QThread>

Pakistan::Pakistan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pakistan)
{
    ReadFile("D:\\Temp\\Dijktra\\Pakistan_Map.txt", PakistanGraph);
    Parent = parent;
    ui->setupUi(this);
}

Pakistan::~Pakistan()
{
    delete ui;
}

void Pakistan::on_ButtonFIND_clicked()
{
    string Start = ui->ComboBoxSTART->currentText().toStdString();
    string End = ui->ComboBoxEND->currentText().toStdString();

    ui->textPath->setText(QString::fromStdString(DijkstasAlgorithm(PakistanGraph,Start,End)));
}


void Pakistan::on_ButtonBACK_clicked()
{
    this->hide();
    QThread::msleep(200);
    Parent->show();
}

