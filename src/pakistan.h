#ifndef PAKISTAN_H
#define PAKISTAN_H

#include <QDialog>
#include "Algorithm.h"

namespace Ui {
class Pakistan;
}

class Pakistan : public QDialog
{
    Q_OBJECT

public:
    explicit Pakistan(QWidget *parent = nullptr);
    ~Pakistan();

private slots:
    void on_ButtonFIND_clicked();

    void on_ButtonBACK_clicked();

private:
    Ui::Pakistan *ui;
    map<string, list<Node>> PakistanGraph;
    QWidget *Parent;
};

#endif // PAKISTAN_H
