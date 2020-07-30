#include "planet.h"


Planet::Planet(QWidget *parent, int x, int y, int m, int r)
{
    setParent(parent);
    setVisible(false);
    X = x;
    Y = y;
    tam = 30 * (r/100);
    posX = spanX + (x * relX) - (tam/2);
    posY = spanY - (y * relY) - (tam/2);
    masa = m;
    setRadio(r);
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
    imagen->setGeometry(posX,posY,tam,tam);
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

void Planet::setPosX(int value)
{
    posX = value;
    imagen->setGeometry(posX,posY,tam,tam);
}

void Planet::setPosY(int value)
{
    posY = value;
    imagen->setGeometry(posX,posY,tam,tam);
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
