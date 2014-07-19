#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>

class MainWindow : public QLabel
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动触发
    void mousePressEvent(QMouseEvent *event);//鼠标点击触发
    void mouseReleaseEvent(QMouseEvent *event);//鼠标点击离开触发
};

#endif // MAINWINDOW_H
