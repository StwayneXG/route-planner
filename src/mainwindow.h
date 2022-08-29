#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rawalpindi.h"
#include "lahore.h"
#include "pakistan.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonRWP_clicked();

    void on_ButtonLHR_clicked();

    void on_ButtonPAK_clicked();

private:
    Ui::MainWindow *ui;
    Rawalpindi *rwp = NULL;
    Lahore *lhr = NULL;
    Pakistan *pak = NULL;
};
#endif // MAINWINDOW_H
