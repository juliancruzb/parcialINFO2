#include "planet.h"


Planet::Planet(QGraphicsItem * parent, QString color, int x, int y, int m, int r)
{    
    setVisible(false);
    imagePath = ":/planetas/" + color;
    X = x;
    Y = y;
    tam = 30 * (r/100);
    setPixmap(QPixmap(imagePath).scaled(tam,tam));
    posX = spanX + (x * relX) - (tam/2);
    posY = spanY - (y * relY) - (tam/2);
    masa = m;
    setRadio(r);
}

double Planet::getX() const
{
    return X;
}

void Planet::setPosX(double value)
{
    double a=0;
    X = value;
    a=value*relX;
    setX(spanX + a - (tam/2));
}

double Planet::getY() const
{
    return Y;
}

void Planet::setPosY(double value)
{
    double a=0;
    Y = value;
    a=value*relY;
    //setY(QReal(value));
    setY(spanY - a - (tam/2));
}
double Planet::getVelocidadX() const
{
    return velocidadX;
}

void Planet::setVelocidadX(double value)
{
    velocidadX = value;
}

double Planet::getRadio() const
{
    return radio;
}

void Planet::setRadio(double value)
{
    radio = value;
    tam = 30 * (radio/100);
    setPixmap(QPixmap(imagePath).scaled(tam,tam));
}

double Planet::getMasa() const
{
    return masa;
}

void Planet::setMasa(double value)
{
    masa = value;
}

int Planet::getPosX() const
{
    return posX;
}

int Planet::getPosY() const
{
    return posY;
}

int Planet::getCentroY() const
{
    return centroY;
}

void Planet::setCentroY(int value)
{
    centroY = value;
}

int Planet::getCentroX() const
{
    return centroX;
}

void Planet::setCentroX(int value)
{
    centroX = value;
}

double Planet::getVelocidadY() const
{
    return velocidadY;
}

void Planet::setVelocidadY(double value)
{
    velocidadY = value;
}
