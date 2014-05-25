#include "encrypt.h"
#include <QDebug>
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

Encrypt::Encrypt(QWidget *parent):QWidget(parent){
    //包裹的widget
    QWidget *MainWidget=new QWidget(this);
    QVBoxLayout *mainLayout=new QVBoxLayout();

    //创建第一个widget
    QWidget *inputWidget=new QWidget(MainWidget);
    QHBoxLayout *inputLayout=new QHBoxLayout();

    QLabel *inputLabel=new QLabel(tr("明文:"),inputWidget);
    inputLayout->addWidget(inputLabel);

    inputEdit=new QTextEdit(inputWidget);
    inputLayout->addWidget(inputEdit);

    inputWidget->setLayout(inputLayout);

    //第二个widget存放button
    //QWidget *buttonWidget=new QWidget(MainWidget);
    encryButton=new QPushButton(tr("加密"));
    connect(encryButton,&QPushButton::clicked,this,&Encrypt::createMd5);

    //第三个个widget 存放结果
    QWidget *resultWidget=new QWidget(MainWidget);
    QHBoxLayout *resultLayout=new QHBoxLayout();

    QLabel *resultLabel=new QLabel(tr("密文:"),resultWidget);
    resultLayout->addWidget(resultLabel);

    resultEdit=new QLineEdit(resultWidget);
    resultEdit->setStyleSheet("height:25px;font-size:15px;");
    resultLayout->addWidget(resultEdit);
    resultWidget->setLayout(resultLayout);

    //将上面wiodget放入
    mainLayout->addWidget(inputWidget);
    mainLayout->addWidget(encryButton,1,Qt::AlignCenter);
    mainLayout->addWidget(resultWidget);
    setLayout(mainLayout);
}

Encrypt::~Encrypt(){
}

void Encrypt::createMd5(){
    //获取需要加密的字符串
    QString inputText=inputEdit->toPlainText();
    if(inputText.isEmpty()){
        QMessageBox::warning(this,tr("错误提示"),tr("请输入需要加密的内容^_^"));
        return;
    }
    QString md5=Md5Algorithm(inputText);
    resultEdit->setText(md5);
    //resultEdit->setFocus();
    //resultEdit->selectAll();
}

/**
 * 生成md5的算法
 * @brief Encrypt::Md5Algorithm
 * @param str
 */
QString Encrypt::Md5Algorithm(QString str){
    QString md5;
    QByteArray bb;
    bb = QCryptographicHash::hash ( str.toUtf8(), QCryptographicHash::Md5 );
    md5.append(bb.toHex());
    return md5;
}



