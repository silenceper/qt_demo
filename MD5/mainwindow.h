#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "encrypt.h"
#include "decrypt.h"
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Encrypt *encrypt;
    Decrypt *decrypt;
    QTabWidget *tabWidget;
    void createGui();
};

#endif // MAINWINDOW_H
