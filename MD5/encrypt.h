#ifndef ENCRYPT_H
#define ENCRYPT_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>

class Encrypt : public QWidget
{
    Q_OBJECT
public:
    Encrypt(QWidget *parent = 0);
    ~Encrypt();
private:
    QPushButton *encryButton;
    QTextEdit *inputEdit;
    QLineEdit *resultEdit;
    void createMd5();
    QString Md5Algorithm(QString str);
};
#endif // ENCRYPT_H
