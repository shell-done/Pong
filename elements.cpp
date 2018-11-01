#include "elements.h"
#include <QDebug>

Ball::Ball(int sceneX, int sceneY, int size, QColor color) : QGraphicsEllipseItem(sceneX/2 - size, sceneY/2 - size, size, size){

    posX=sceneX/2;
    posY=sceneY/2;
    this->sceneX=sceneX;
    this->sceneY=sceneY;
    speed=8;

    qsrand(QTime::currentTime().msec());
    float temp=qrand();

    while(temp>PI)
        temp-=(float)(2*PI);

    if(temp<PI/2)
        angle=temp-PI/4;
    else
        angle=temp+PI/2;

    radius=size/2;

    this->setBrush(QBrush(color, Qt::SolidPattern));
}

float Ball::getX() const {return posX;}
float Ball::getY() const {return posY;}
float Ball::getAngle() const {return angle;}
int Ball::getRadius() const {return radius;}
void Ball::setAngle(float ang) {
    angle=ang;
    while(angle>=2*PI) {
        angle-=(float)PI*2;
    }
    if(cos(angle) > 0 && cos(angle) < 0.2 && sin(angle) > 0)
        angle=acos(0.2);
    if(cos(angle) < 0 && cos(angle) > -0.2 && sin(angle) > 0)
        angle=acos(-0.2);
    if(cos(angle) > 0 && cos(angle) < 0.2 && sin(angle) < 0)
        angle=PI-acos(0.2);
    if(cos(angle) < 0 && cos(angle) > -0.2 && sin(angle) < 0)
        angle=PI-acos(-0.2);
}

void Ball::resetBallPos(int dir) {
    posX=sceneX/2;
    posY=sceneY/2;

    float temp=qrand();
    while(temp>=PI) {
        temp-=(float)PI*2;
    }
    angle=temp - PI/2;

    if(dir == -1)
        angle+=PI;
}

void Ball::move() {
    posX += (float)speed*cos(angle);
    posY += (float)speed*sin(angle);

    this->setRect(posX - radius, posY - radius, radius*2, radius*2);
}



Bar::Bar(int posX, int posY, int w, int h, QColor color) : QGraphicsRectItem(posX, posY, w, h) {
    this->posX=posX;
    this->posY=posY;

    this->width=w;
    this->height=h;

    this->setBrush(QBrush(color, Qt::SolidPattern));
}

int Bar::getX() const {return posX;}
int Bar::getY() const {return posY;}
int Bar::getWidth() const {return width;}
int Bar::getHeight() const {return height;}
void Bar::setPosY(int y) {posY=y; this->setY(posY);}
void Bar::moveBar(int y) {
    posY+=y;
    if(posY < 0)
        posY=0;
    if(posY + height > 700)
        posY= 700 - height;

    this->setY(posY);
}
