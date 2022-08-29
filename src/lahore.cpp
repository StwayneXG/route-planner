#include "lahore.h"
#include "ui_lahore.h"
#include <QThread>

Lahore::Lahore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lahore)
{
    ui->setupUi(this);
    ReadFile("D:\\Temp\\Dijktra\\Lahore_Map.txt", LahoreGraph);
    Parent = parent;
}

Lahore::~Lahore()
{
    delete ui;
}

void Lahore::on_ButtonFIND_clicked()
{
    string Start = ui->ComboBoxSTART->currentText().toStdString();
    string End = ui->ComboBoxEND->currentText().toStdString();

    ui->textPath->setText(QString::fromStdString(DijkstasAlgorithm(LahoreGraph,Start,End)));
}


void Lahore::on_ButtonBACK_clicked()
{
    this->hide();
    QThread::msleep(200);
    Parent->show();
}

