#ifndef LAHORE_H
#define LAHORE_H

#include <QDialog>
#include "Algorithm.h"

namespace Ui {
class Lahore;
}

class Lahore : public QDialog
{
    Q_OBJECT

public:
    explicit Lahore(QWidget *parent = nullptr);
    ~Lahore();

private slots:
    void on_ButtonFIND_clicked();

    void on_ButtonBACK_clicked();

private:
    Ui::Lahore *ui;
    map<string, list<Node>> LahoreGraph;
    QWidget *Parent;
};

#endif // LAHORE_H
