#include "logintitle.h"
#include "ui_logintitle.h"

logintitle::logintitle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logintitle)
{
    ui->setupUi(this);

    //设置图片样式
    logopicture.load(":/images/logo.ico");
    ui->login_logo->setPixmap(logopicture);
    ui->login_logo->setScaledContents(true);


    m_parent=parent;





}
void logintitle::SetLogOPicture(logopicture){

    logopicture.load(":/images/logo.ico");
    ui->login_logo->setPixmap(logopicture);
    ui->login_logo->setScaledContents(true);



};

logintitle::~logintitle()
{
    delete ui;
}
