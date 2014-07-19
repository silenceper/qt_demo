#include "mainwindow.h"
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QLabel(parent)
{
    setWindowTitle("测试事件性质");
    resize(200,200);
    setStyleSheet("font-weight:bold;");
    setMouseTracking(true);
}

MainWindow::~MainWindow()
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *event){
    this->setText(QString("<center>move:(x:%1,y:%2)</center>").arg(event->x()).arg(event->y()));
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    this->setText(QString("<center>press:(x:%1,y:%2)</center>").arg(event->x()).arg(event->y()));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event){
    this->setText(QString("<center>Release:(x:%1,y:%2)</center>").arg(event->x()).arg(event->y()));
}

