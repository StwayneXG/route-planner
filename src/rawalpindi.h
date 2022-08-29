#ifndef RAWALPINDI_H
#define RAWALPINDI_H

#include <QDialog>
#include "Algorithm.h"

namespace Ui {
class Rawalpindi;
}

class Rawalpindi : public QDialog
{
    Q_OBJECT

public:
    explicit Rawalpindi(QWidget *parent = nullptr);
    ~Rawalpindi();

private slots:
    void on_ButtonFIND_clicked();

    void on_ButtonBACK_clicked();

private:
    Ui::Rawalpindi *ui;
    map<string, list<Node>> RawalpindiGraph;
    QWidget *Parent;
};

#endif // RAWALPINDI_H
