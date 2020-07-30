#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Se configura el timer.
    t = new QTimer;
    connect(t,SIGNAL(timeout()),this,SLOT(updatePlanets()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configInitial()
{
    // Se configura tabla de datos
    ui->tableWidget->setCellWidget(0,1,ui->posX0);
    ui->tableWidget->setCellWidget(1,1,ui->posX1);
    ui->tableWidget->setCellWidget(2,1,ui->posX2);
    ui->tableWidget->setCellWidget(3,1,ui->posX3);
    ui->tableWidget->setCellWidget(4,1,ui->posX4);
    ui->tableWidget->setCellWidget(0,2,ui->posY0);
    ui->tableWidget->setCellWidget(1,2,ui->posY1);
    ui->tableWidget->setCellWidget(2,2,ui->posY2);
    ui->tableWidget->setCellWidget(3,2,ui->posY3);
    ui->tableWidget->setCellWidget(4,2,ui->posY4);
    ui->tableWidget->setCellWidget(0,3,ui->masa0);
    ui->tableWidget->setCellWidget(1,3,ui->masa1);
    ui->tableWidget->setCellWidget(2,3,ui->masa2);
    ui->tableWidget->setCellWidget(3,3,ui->masa3);
    ui->tableWidget->setCellWidget(4,3,ui->masa4);
    ui->tableWidget->setCellWidget(0,4,ui->radio0);
    ui->tableWidget->setCellWidget(1,4,ui->radio1);
    ui->tableWidget->setCellWidget(2,4,ui->radio2);
    ui->tableWidget->setCellWidget(3,4,ui->radio3);
    ui->tableWidget->setCellWidget(4,4,ui->radio4);
    ui->tableWidget->setCellWidget(0,5,ui->vx0);
    ui->tableWidget->setCellWidget(1,5,ui->vx1);
    ui->tableWidget->setCellWidget(2,5,ui->vx2);
    ui->tableWidget->setCellWidget(3,5,ui->vx3);
    ui->tableWidget->setCellWidget(4,5,ui->vx4);
    ui->tableWidget->setCellWidget(0,6,ui->vy0);
    ui->tableWidget->setCellWidget(1,6,ui->vy1);
    ui->tableWidget->setCellWidget(2,6,ui->vy2);
    ui->tableWidget->setCellWidget(3,6,ui->vy3);
    ui->tableWidget->setCellWidget(4,6,ui->vy4);
    // Se crean planetas
    // Se inicializan los planetas.
    for (int i=0; i<5; i++) {
        p[i] = new Planet(this);
    }
}


void MainWindow::on_startSimulate_clicked()
{
    // Se desabilita el boton y se activa el de detener la simulación.
    ui->startSimulate->setEnabled(false);
    ui->stopSimulate->setEnabled(true);
    ui->tableWidget->setEnabled(false);
    // Se configuran los planetas con los valores ingresados
    int valInt=0;
    double valDou=0.00;
    for(int i=0; i<5; i++) {
        for(int j=1; j<7; j++){
            switch (j) {
                case 1:
                    valInt = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setX(valInt);
                break;
                case 2:
                    valInt = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setY(valInt);
                break;
                case 3:
                    valInt = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setMasa(valInt);
                break;
                case 4:
                    valInt = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setRadio(valInt);
                    if (valInt > 0) {
                        p[i]->imagen->setVisible(true);
                    }
                break;
                case 5:
                    valDou = static_cast<QDoubleSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setVelocidadX(valDou);
                break;
                case 6:
                    valDou = static_cast<QDoubleSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setVelocidadY(valDou);
                break;
            }
        }
    }
    // Se inicializa el timer
    t->start(int(5));

}

void MainWindow::on_stopSimulate_clicked()
{
    ui->startSimulate->setEnabled(true);
    ui->stopSimulate->setEnabled(false);
    ui->tableWidget->setEnabled(true);
    t->stop();
}

