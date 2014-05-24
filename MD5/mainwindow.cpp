#include "mainwindow.h"
#include "encrypt.h"
#include "decrypt.h"
#include <QDebug>
#include <QIcon>
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置窗体
    setWindowIcon(QIcon(":images/icon-md5"));
    resize(550,230);
    setWindowTitle("MD5加密解密");
    //不允许缩放
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    flags |= Qt::WindowCloseButtonHint;
    flags |= Qt::MSWindowsFixedSizeDialogHint;
    setWindowFlags(flags);
    createGui();
}
MainWindow::~MainWindow()
{
}

/**
 * 初始化
 * @brief MainWindow::createGui
 */
void MainWindow::createGui(){
    encrypt=new Encrypt(this);//后面其实可以不加this  因为加入了tabWidget会自动设置parent
    decrypt=new Decrypt(this);

    tabWidget=new QTabWidget(this);
    tabWidget->addTab(encrypt,tr("加密"));
    tabWidget->addTab(decrypt,tr("解密"));
    setCentralWidget(tabWidget);
}
