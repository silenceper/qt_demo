#include <QCoreApplication>
#include <stdio.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf("Hello World!");
    return a.exec();
}
