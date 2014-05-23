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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent){
    QWidget *widget=new QWidget(this);
    QHBoxLayout *layout=new QHBoxLayout(widget);//注意这里中的parent是widget
    //第一个按钮
    QPushButton *button=new QPushButton(tr("question"),widget);
    connect(button,&QPushButton::clicked,this,&MainWindow::open);
    layout->addWidget(button);
    //第二个按钮
    QPushButton *button2=new QPushButton(tr("color"),widget);
    connect(button2,&QPushButton::clicked,this,&MainWindow::open2);
    qDebug()<<"test";
    qDebug()<<&QPushButton::clicked;
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



