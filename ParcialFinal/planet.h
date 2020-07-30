#ifndef PLANET_H
#define PLANET_H

#include <QLabel>

class Planet : public QLabel
{
private:
    const int spanX = 436;
    const int spanY = 526;
    double X,Y;
    double relX = 0.02857;
    double relY = 0.02857;

public:
    Planet(QWidget *parent = nullptr, int x=0, int y=0, int m=100, int r=100);
    //Planet(QLabel *a, int x, int y, int m=100, int r=100);
    QLabel *imagen;
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
    void setPosY(int value);
    int getPosX() const;
    void setPosX(int value);
    int getCentroY() const;
    void setCentroY(int value);
    int getCentroX() const;
    void setCentroX(int value);
    void setPos(int x, int y);
    double getX() const;
    void setX(double value);
    double getY() const;
    void setY(double value);
};

#endif // PLANET_H
