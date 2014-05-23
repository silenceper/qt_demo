#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QKeySequence>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QMessageBox>
#include <QTextStream>
#include <QFileInfo>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon(":images/editor-icon"));
    setWindowIconText(tr("sadfasdf "));
    appName=tr("记事本");
    setWindowTitle(appName);
    resize(300,450);
    //新建文件夹
    newAction=new QAction(QIcon(":images/doc-new"),tr("新建"),this);
    newAction->setStatusTip(tr("新建一个文件"));
    newAction->setShortcut(QKeySequence::New);
    connect(newAction,&QAction::triggered,this,&MainWindow::newF);
    //打开文件动作
    openAction=new QAction(QIcon(":images/doc-open"),tr("打开"),this);
    openAction->setStatusTip(tr("打开一个文件"));
    openAction->setShortcut(QKeySequence::Open);
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    //保存文件动作
    saveAction=new QAction(QIcon(":images/doc-save"),tr("保存"),this);
    saveAction->setStatusTip(tr("保存文件"));
    saveAction->setShortcut(QKeySequence::Save);
    connect(saveAction,&QAction::triggered,this,&MainWindow::save);
    //退出程序
    exitAction=new QAction(QIcon(":images/doc-exit"),tr("退出"),this);
    exitAction->setStatusTip(tr("退出"));
    exitAction->setShortcut(QKeySequence::Quit);
    connect(exitAction,&QAction::triggered,this,&MainWindow::exitF);

    menu=menuBar()->addMenu(tr("&文件"));
    menu->addAction(newAction);
    menu->addAction(openAction);
    menu->addAction(saveAction);
    menu->addAction(exitAction);

    aboutAction=new QAction(QIcon(":images/doc-about"),tr("关于"),this);
    aboutAction->setStatusTip(tr("关于"));
    connect(aboutAction,&QAction::triggered,this,&MainWindow::about);

    //帮助菜单
    HelpMenu=menuBar()->addMenu(tr("&帮助"));
    HelpMenu->addAction(aboutAction);
    statusBar();
    textEdit=new QTextEdit(this);
    setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}

/**
 * 新建一个文件
 * @brief MainWindow::newF
 */
void MainWindow::newF(){
    setWindowTitle(tr("新建文件"));
    textEdit->setText("");
}
/**
 * 打开一个文件
 * @brief MainWindow::open
 */
void MainWindow::open(){
    QString path=QFileDialog::getOpenFileName(this,tr("选择文件"),tr("C:/"),tr("文本文件(*.txt)"));
    if(path.isEmpty()){
        return ;
    }
    //读取文件内容
    QFile file(path);
    QFileInfo info(file);
    if(!info.isFile()){
         QMessageBox::warning(this,tr("打开文件失败"),tr("打开的不是一个文件"));
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QMessageBox::warning(this,tr("打开文件失败"),tr("文件无法打开"));
    }
    /*
    while(!file.atEnd()){
        content+=file.readLine();
    }
    */
    QTextStream text(&file);
    QString content(text.readAll());
    file.close();
    //qDebug()<<content;
    //更改标题
    setWindowTitle(info.fileName()+"("+info.filePath()+")"+" "+appName);
    textEdit->setText(content);
}

/**
 * 保存文件
 * @brief MainWindow::save
 */
void MainWindow::save(){
    QString path=QFileDialog::getSaveFileName(this,tr("保存文件"),tr("."),tr("文本文件(*.txt)"));
    if(path.isEmpty()){
        //QMessageBox::warning(this,tr("保存文件失败"),tr("保存文件失败"));
        return ;
    }
    QFile file(path);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::warning(this, tr("保存文件"), tr("无法保存文件:\n%1").arg(path));
        return;
    }
    QTextStream out(&file);
    out << textEdit->toPlainText();
    file.close();
}

/**
 * 退出程序
 * @brief MainWindow::exitF
 */
void MainWindow::exitF(){
    //判断文件中是否有内容
    if(textEdit->toPlainText()==""){
        exit(0);
    }
    int ret=QMessageBox::question(this,tr("退出询问?"),tr("当前编辑的文件中含有内容,您真的要退出吗？"),QMessageBox::Yes|QMessageBox::No);
    switch(ret){
        case QMessageBox::Yes:
            exit(0);
            break;
        case QMessageBox::No:
            break;
    }
}

/**
 * 关于
 * @brief MainWindow::about
 */
void MainWindow::about(){
    QMessageBox::about(this,tr("开发者"),tr("Author:silenceper\nEmail:silenceper@gmail.com"));
}
