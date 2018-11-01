#include "scene.h"
#include <QPointF>

Scene::Scene(QObject* parent) : QGraphicsScene(parent) {
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);

    int sceneX=1280;
    int sceneY=720;

    this->installEventFilter(this);
    this->setSceneRect(0,0,sceneX,sceneY);
    this->setBackgroundBrush(Qt::white);
    background.load("background.png");

    scoreP1=0;
    scoreP2=0;
    dispScoreP1 = this->addText(QString::number(scoreP1));
    dispScoreP1->setPos(sceneX/2 - dispScoreP1->boundingRect().width()*8 - 100,100);
    dispScoreP1->setDefaultTextColor(QColor(Qt::white));
    dispScoreP1->setScale(8);

    dispScoreP2 = this->addText(QString::number(scoreP2));
    dispScoreP2->setPos(sceneX/2 + 100,100);
    dispScoreP2->setDefaultTextColor(QColor(Qt::white));
    dispScoreP2->setScale(8);

    ball = new Ball(width(), height(), 48, QColor(Qt::white));
    this->addItem(ball);

    barP1 = new Bar(10,10,25,150, QColor(Qt::white));
    barP2 = new Bar(1280-25-10,10,25,150, QColor(Qt::white));

    this->addItem(barP1);
    this->addItem(barP2);
}

void Scene::update() {
    ball->move();

    if(ball->getX() > 1280 - ball->getRadius()) {
        ball->resetBallPos(1);
        scoreP2++;
    }

    if(ball->getX() < 0 + ball->getRadius()) {
        ball->resetBallPos(-1);
        scoreP1++;
    }

    dispScoreP1->setPlainText(QString::number(scoreP1));
    dispScoreP2->setPlainText(QString::number(scoreP2));

    if(ball->getY() < 0 + ball->getRadius())
        ball->setAngle(-ball->getAngle());

    if(ball->getY() > 720 - ball->getRadius())
        ball->setAngle(-ball->getAngle());


    int bestDist=1000;
    for(int i=4; i<=barP1->getHeight()+10; i++) {
        if(pow(ball->getX() + 1 - barP1->getX() - barP1->getWidth(), 2) + pow(ball->getY() - barP1->getY() - i, 2) < pow(ball->getRadius(), 2))
            bestDist=std::min(bestDist, i);
    }
    for(int i=4; i<=barP2->getHeight()+10; i++) {
        if(pow(ball->getX() - barP2->getX() - 1, 2) + pow(ball->getY() - barP2->getY() - i, 2) < pow(ball->getRadius(), 2))
            bestDist=std::min(bestDist, i);
    }

    if(bestDist!=1000) {
        ball->setBrush(QBrush(Qt::red, Qt::SolidPattern));
        ball->setAngle(PI - ball->getAngle());
    } else {
        ball->setBrush(QBrush(Qt::green, Qt::SolidPattern));
    }
}


bool Scene::eventFilter(QObject *object, QEvent *event) {
    Q_UNUSED(object);

    if(event->type()==QEvent::KeyPress) {
        pressedKeys += ((QKeyEvent*) event)->key();

        if(pressedKeys.contains(Qt::Key_Z))
            barP1->moveBar(-5);
        if(pressedKeys.contains(Qt::Key_S))
            barP1->moveBar(5);

        if(pressedKeys.contains(Qt::Key_P))
            barP2->moveBar(-5);
        if(pressedKeys.contains(Qt::Key_M))
            barP2->moveBar(5);

    } else if(event->type()==QEvent::KeyRelease) {
        pressedKeys -= ((QKeyEvent*) event)->key();
    }

    return false;
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);
    painter->drawPixmap(QPointF(0,0), background, sceneRect());
}
