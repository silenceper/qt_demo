#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton qp("Hello button");
    QObject::connect(&qp,&QPushButton::clicked,&QApplication::quit);
    qp.show();
    return a.exec();
}
