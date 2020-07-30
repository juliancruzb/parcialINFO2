#ifndef PLANET_H
#define PLANET_H

#include <QGraphicsPixmapItem>

class Planet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    const int spanX = 436;
    const int spanY = 526;
    double X,Y;
    double relX = 0.02857;
    double relY = 0.02857;

public:
    Planet(QGraphicsItem * parent = 0, QString color="0", int x=0, int y=0, int m=100, int r=100);
    //Planet(QLabel *a, int x, int y, int m=100, int r=100);    
    QString imagePath;
    int centroX;
    int centroY;
    int posX;
    int posY;
    double masa;
    double radio;
    int tam;
    double velocidadX;
    double velocidadY;
    double getVelocidadY() const;
    void setVelocidadY(double value);
    double getVelocidadX() const;
    void setVelocidadX(double value);
    double getRadio() const;
    void setRadio(double value);
    double getMasa() const;
    void setMasa(double value);
    int getPosY() const;
    void setPosY(double value);
    int getPosX() const;
    void setPosX(double value);
    int getCentroY() const;
    void setCentroY(int value);
    int getCentroX() const;
    void setCentroX(int value);
    void setPos(int x, int y);
    double getX() const;

    double getY() const;

};

#endif // PLANET_H
