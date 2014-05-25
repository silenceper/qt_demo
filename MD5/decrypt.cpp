#include "decrypt.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QString>
#include <QByteArray>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QNetworkReply>
#include <QList>
#include <QSslError>
#include <QDebug>

Decrypt::Decrypt(QWidget *parent):QWidget(parent){
    //包裹的widget
    QWidget *MainWidget=new QWidget(this);
    QVBoxLayout *mainLayout=new QVBoxLayout();

    //创建第一个widget
    QWidget *inputWidget=new QWidget(MainWidget);
    QHBoxLayout *inputLayout=new QHBoxLayout();

    QLabel *inputLabel=new QLabel(tr("密文:"),inputWidget);
    inputLayout->addWidget(inputLabel);

    inputEdit=new QLineEdit(inputWidget);
    inputLayout->addWidget(inputEdit);

    inputWidget->setLayout(inputLayout);

    //第二个widget存放button
    //QWidget *buttonWidget=new QWidget(MainWidget);
    decryButton=new QPushButton(tr("解密"));
    connect(decryButton,SIGNAL(clicked()),this,SLOT(setResult()));

    //第三个个widget 存放结果
    QWidget *resultWidget=new QWidget(MainWidget);
    QHBoxLayout *resultLayout=new QHBoxLayout();

    QLabel *resultLabel=new QLabel(tr("明文:"),resultWidget);
    resultLayout->addWidget(resultLabel);

    resultEdit=new QTextEdit(resultWidget);
    resultEdit->setStyleSheet("height:25px;font-size:15px;");
    resultLayout->addWidget(resultEdit);
    resultWidget->setLayout(resultLayout);

    //将上面widget放入
    mainLayout->addWidget(inputWidget);
    mainLayout->addWidget(decryButton,1,Qt::AlignCenter);
    mainLayout->addWidget(resultWidget);
    setLayout(mainLayout);
}

Decrypt::~Decrypt(){
}

/**
 * 设置结果
 * @brief Decrypt::setResult
 */
void Decrypt::setResult(){
    QString inputString=inputEdit->text();
    if(inputString.isEmpty()){
        QMessageBox::warning(this,tr("错误提示"),tr("请输入需要解密的内容^_^"));
        return ;
    }
    //判断是否为32位
    if(inputString.length()!=32){
        QMessageBox::warning(this,tr("错误提示"),tr("MD5加密的内容是32位^_^"));
        return ;
    }
    //请求的url
    requestUrl="http://php/md5/post.php?md5="+inputString;
    startRequest(requestUrl);
}

/**
 * 请求
 * @brief Decrypt::startRequest
 * @param url
 */
void Decrypt::startRequest(QString url){
    //设置按钮不可用
    decryButton->setDisabled(true);
    reply=qnam.get(QNetworkRequest(url));
    connect(reply, SIGNAL(finished()),
            this, SLOT(httpFinished()));
}

/**
 * 完成http请求
 * @brief Decrypt::httpFinished
 */
void Decrypt::httpFinished(){
    QString httpResult=reply->readAll();
    //qDebug()<<httpResult;
    reply->deleteLater();
    reply=0;
    resultEdit->setText(httpResult);
    //设置按钮可用
    decryButton->setEnabled(true);
}
