#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsView>
#include <QLayout>
#include "scene.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public:
    QWidget* mainWidget;
    Scene* scene;
    QGraphicsView* view;

signals:

public slots:
};

#endif // MAINWINDOW_H
