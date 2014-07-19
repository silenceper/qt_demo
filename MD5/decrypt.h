#ifndef DECRYPT_H
#define DECRYPT_H
#include <QWidget>
#include <QLineEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkReply>
#include <QList>
#include <QSslError>

class Decrypt : public QWidget{
    Q_OBJECT
public:
    Decrypt(QWidget *parent = 0);
    ~Decrypt();
private:
    QPushButton *decryButton;
    QLineEdit *inputEdit;
    QTextEdit *resultEdit;
    QString requestUrl;
    QNetworkAccessManager qnam;

    QNetworkReply *reply;
    void startRequest(QString url);
private slots:
    void setResult();
    void httpFinished();
};
#endif // DECRYPT_H
