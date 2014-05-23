#include "mainwindow.h"
#include <Qt>
#include <QAction>
#include <QIcon>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QFont>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("动作测试");
    resize(200,400);
    //设置action
    openAction=new QAction(QIcon(":/images/doc-open"),tr("&打开"),this);//最后一个传入的this表示在MainWindow折构的时候，所有以其为parent的对象都会折构不需要手动delete
    openAction->setShortcuts(QKeySequence::Open);//设置快捷键  跨平台
    openAction->setStatusTip(tr("打开一个已有的文件"));//设置status bar中显示的文字信息
    connect(openAction, &QAction::triggered, this, &MainWindow::open);//信号槽

    //将action加入menubar中
    QMenu *file = menuBar()->addMenu(tr("&文件"));  //加了&符号只是起个说明作用在第一个字符前面加下划线
    file->addAction(openAction);

    //将action加入toolbar中
    QToolBar *toolBar = addToolBar(tr("&文件"));
    toolBar->addAction(openAction);

    statusBar() ;
}

MainWindow::~MainWindow()
{

}

void MainWindow::open(){
    //QMessageBox::information(this, tr("弹出信息"), tr("打开"));
    QDialog *qDialog=new QDialog(this);//加上this表示属于父类在任务栏中位置不同
    qDialog->setAttribute(Qt::WA_DeleteOnClose);//setAttribute()函数设置对话框关闭时，自动销毁对话框
    qDialog->setWindowTitle(tr("Hello Dislog!"));
    //qDialog.exec(); 会阻塞
    qDialog->show();
}

