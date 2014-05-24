#include "mainwindow.h"
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QAction>
#include <QWidget>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QProgressDialog>
#include <QFileDialog>
#include <QFont>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    setAutoFillBackground(true);
    resize(500,500);
    setObjectName("mainWindow");
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground, true);//设置 窗体标题栏不透明,背景透明
    setStyleSheet("MainWindow#mainWindow{ border-image:url(:/images/bg)}");
    setAnimated(true);
    QWidget *widget=new QWidget(this);
    QHBoxLayout *layout=new QHBoxLayout();//注意这里 其实可以不用闯入parent 因为后面一句setLayout了会自动判断
    //第一个按钮
    QPushButton *button=new QPushButton(tr("question"),widget);
    //button->setFlat(true); //设置透明
    //button->resize(75, 30);  //不起作用
    //button->setFixedSize(QSize(30,30)); //设置大小
    button->setStyleSheet("background-color:#FF0000");
    button->setFont(QFont("Times", 18, QFont::Bold));
    connect(button,&QPushButton::clicked,this,&MainWindow::open);
    layout->addWidget(button);
    //第二个按钮
    QPushButton *button2=new QPushButton(tr("color"),widget);
    connect(button2,&QPushButton::clicked,this,&MainWindow::open2);
    layout->addWidget(button2);

    widget->setLayout(layout);
    setCentralWidget(widget);

}

MainWindow::~MainWindow()
{
}

void MainWindow::open(){
    //qDebug()<<"test";
    //int ret=QMessageBox::question(this,tr("真的要删除吗？"),tr("删除之后将无法恢复"),QMessageBox::No|QMessageBox::Yes);

    QMessageBox msgBox;
    msgBox.setText(tr("真的要删除吗？"));
    msgBox.setInformativeText(tr("删除之后将无法恢复"));
    msgBox.setStandardButtons(QMessageBox::No|QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::No);
    int ret=msgBox.exec();

    switch(ret){
        case QMessageBox::Yes:
            qDebug()<<"Yes";
        break;
    case QMessageBox::No:
            qDebug()<<"No";
        break;
    }
}

void MainWindow::open2(){
    //QColorDialog colorDialog;
    QString path=QFileDialog::getOpenFileName(this,
                                 tr("Open File"),
                                 ".",
                                 tr("Text Files(*.txt)"));
    qDebug()<<path;
}
