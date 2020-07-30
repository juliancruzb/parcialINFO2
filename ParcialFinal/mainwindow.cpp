#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    configInitial();
    //Se configura el timer.
    t = new QTimer;
    connect(t,&QTimer::timeout,this,&MainWindow::updatePlanets);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePlanets() {
    double r = 0;
    double ax = 0;
    double ay = 0;
    double x = 0;
    double y = 0;
    for (int i=0; i<5; i++) {
        ax=0;
        ay=0;
        x = p[i]->getX();
        y = p[i]->getY();
        for (int j=0; j<5; j++){
            if (j==i) {
                continue;
            }
            //Calcular distancia
            r = sqrt(pow((p[j]->getX()-p[i]->getX()),2)+pow((p[j]->getY()-p[i]->getY()),2));
            //Calcular angulo del vector de direccion
            //angulo = atan((p[j]->getY()-p[i]->getY())/(p[j]->getX()-p[i]->getX()));
            //Calcular aceleracion x
            ax += (G * p[j]->getMasa() * (p[j]->getX()-p[i]->getX()))/pow(r,3);
            //Calcular aceleracion y
            ay += (G * p[j]->getMasa() * (p[j]->getY()-p[i]->getY()))/pow(r,3);
        }
        p[i]->velocidadX += (ax * T);
        p[i]->velocidadY += (ay * T);
        x+=((p[i]->velocidadX*T)+(ax*pow(T,2)/2));
        y+=((p[i]->velocidadY*T)+(ay*pow(T,2)/2));
        p[i]->setPosX(x);
        p[i]->setPosY(y);
    }
    updateRamdoms();

}

void MainWindow::updateRamdoms() {
    double newColor = ((rand() % 101)+10)*0.01;

    for (int i=0; i<alCont; i++) {
        aleatorios[i]->setPosY(aleatorios[i]->getY()-100);

        QList<QGraphicsItem *> colliding_items = aleatorios[i]->collidingItems();
        for(int i=0;i<colliding_items.size();i++) {
            qDebug() << "Colisiono";
            if (typeid(*colliding_items[i])==typeid(Planet)) {
                colliding_items[i]->setOpacity(newColor);
                scene->removeItem(aleatorios[i]);
            }
        }
    }
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
    //Se configura la escena y se agrega a la vista
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,500);
    ui->universo->setScene(scene);
    // Se inicializan los planetas.
    for (int i=0; i<5; i++) {
        p[i] = new Planet(QString::number(i));
        scene->addItem(p[i]);
    }

}


void MainWindow::on_startSimulate_clicked()
{
    qDebug() << "Se dio clic a boton";
    // Se desabilita el boton y se activa el de detener la simulación.
    ui->startSimulate->setEnabled(false);    
    ui->stopSimulate->setEnabled(true);
    ui->randomPlanet->setEnabled(true);
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
                    p[i]->X = valInt;
                break;
                case 2:
                    valInt = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setY(valInt);
                    p[i]->Y = valInt;
                break;
                case 3:
                    valInt = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setMasa(valInt);
                break;
                case 4:
                    valInt = static_cast<QSpinBox*>(ui->tableWidget->cellWidget(i,j))->value();
                    p[i]->setRadio(valInt);
                    if (valInt > 0) {
                        p[i]->setVisible(true);
                        //p[i]->imagen->setVisible(true);
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
    ui->randomPlanet->setEnabled(false);
    ui->tableWidget->setEnabled(true);
    t->stop();
}


void MainWindow::on_randomPlanet_clicked()
{
    if (randomEnable) {
    int numero = (rand() % 20000)-10000;
    aleatorios[alCont] = new Planet("1",numero,9000);
    aleatorios[alCont]->setVisible(true);
    scene->addItem(aleatorios[alCont]);
    alCont ++;
    if (alCont>9) randomEnable =false;
    }
}

