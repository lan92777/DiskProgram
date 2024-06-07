#include "logintitle.h"
#include "ui_logintitle.h"

logintitle::logintitle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logintitle)
{
    ui->setupUi(this);

    //设置图片样式
    m_parent=parent;

    SetLogOPicture();

    settitlename();

}

void logintitle::SetLogOPicture(){

    //设置图片元素
    logopicture.load(":/images/disklogo.png");
    //设置图片大小
    logopicture = logopicture.scaled(58, 58, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //ui->login_logo->setScaledContents(true);
    //将图片元素赋予控件
    ui->login_logo->setPixmap(logopicture);

};

void logintitle::settitlename()
{
    //设置内容
    ui->DiskName->setText("DiskName");
    ui->DiskName->setStyleSheet("QLabel { color : blue; font-size: 24px; }");
}

void SetSetPicture(){


};
void SetMinWindowPicture(){};
void SetClsWindowPicture(){};

logintitle::~logintitle()
{
    delete ui;
}
