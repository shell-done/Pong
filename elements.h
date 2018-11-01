#ifndef BALL_H
#define BALL_H

#define PI 3.14
#include <cmath>
#include <QGraphicsItem>
#include <QColor>
#include <QBrush>
#include <QRandomGenerator>
#include <QTime>

class Bar;

class Ball : public QGraphicsEllipseItem {
public:
    Ball(int sceneX, int sceneY, int size, QColor color);
    float getX() const;
    float getY() const;
    float getAngle() const;
    int getRadius() const;

    void setAngle(float ang);
    void resetBallPos(int dir);
    void move();

private:
    float posX, posY;
    float speed;
    float angle;

    int radius;
    int sceneX, sceneY;
};


class Bar : public QGraphicsRectItem {
public:
    Bar(int posX, int posY, int w, int h, QColor color);
    int getX() const;
    int getY() const;
    int getWidth() const;
    int getHeight() const;
    void setPosY(int y);
    void moveBar(int y);

private:
    int posX,posY;
    int width, height;
};

#endif // BALL_H
