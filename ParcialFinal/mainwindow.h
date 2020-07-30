#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "planet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Planet *p[5];



private slots:
    void updatePlanets();
    void on_startSimulate_clicked();
    void on_stopSimulate_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *t;
    void configInitial();
};
#endif // MAINWINDOW_H
