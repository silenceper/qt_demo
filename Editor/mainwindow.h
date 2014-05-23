#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QString appName;
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *aboutAction;

    QMenu *menu;
    QMenu *HelpMenu;
    QTextEdit *textEdit;
    void newF();
    void open();
    void save();
    void exitF();
    void about();
};

#endif // MAINWINDOW_H
