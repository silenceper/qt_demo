#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QAction>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
