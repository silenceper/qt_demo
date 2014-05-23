#include "mainwindow.h"
#include <QPushButton>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QPushButton quit("Quit");   //1
    QWidget window; //2
    quit.setParent(&window);
    //以上这段代码会出错  因为按照按照创建对象的顺序 折构的调用时最先创建的最晚调用
    //首先会调用window的折构 而在调用window折构的同时间属于window的子对象一并折构，所以quit也被折构了
    //而当quit再折构的时候  已经是第二次折构  程序出错
    //当改变 1 2的顺序  则正常   或者 QWidget window;QPushButton quit("Quit", &window);
}

MainWindow::~MainWindow()
{

}
