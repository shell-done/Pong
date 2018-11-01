#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    mainWidget = new QWidget;

    QHBoxLayout *generalLayout = new QHBoxLayout;
    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(generalLayout);

    scene = new Scene(this);
    view = new QGraphicsView(scene, this);

    generalLayout->addWidget(view);
}
