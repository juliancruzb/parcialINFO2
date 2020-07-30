#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
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
    Planet *aleatorios[10];
    int alCont = 0;
    bool randomEnable = true;

    void updateRamdoms();

public slots:


private slots:
    void updatePlanets();
    void on_startSimulate_clicked();
    void on_stopSimulate_clicked();

    void on_randomPlanet_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *t;
    double T=1.0, G=1, R;
    QGraphicsScene *scene;
    void configInitial();
};
#endif // MAINWINDOW_H
