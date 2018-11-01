#ifndef SCENE_H
#define SCENE_H

#include <QtWidgets>
#include <QTimer>
#include <QKeyEvent>
#include "elements.h"

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    Scene(QObject* parent);


private:
    QTimer* timer;
    Ball* ball;
    Bar *barP1, *barP2;
    int scoreP1, scoreP2;
    QGraphicsTextItem *dispScoreP1, *dispScoreP2;
    QSet<int> pressedKeys;
    QPixmap background;

protected:
    bool eventFilter(QObject *object, QEvent *event);
    void drawBackground(QPainter* painter, const QRectF &rect);

public slots:
    void update();
};

#endif // SCENE_H;
