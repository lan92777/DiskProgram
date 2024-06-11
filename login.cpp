#include "login.h"
#include "ui_login.h"
#include <QPainter>


//指定父类和生成赋予ui
login::login(QWidget *parent) :QDialog(parent),ui(new Ui::login)
{

    ui->setupUi(this);
    //设置程序属性
    SetTiltleHide();
    this->setWindowIcon(QIcon(":/images/logo.ico"));
    connect(ui->loginhead, &logintitle::CloseWindow, [=]()
    {
        close();


    });



}

//背景设置
void login::paintEvent(QPaintEvent *){
    //绘画背景信息
    QPainter painter(this);
    QPixmap pixmap(":/images/login_bk.jpg");
    painter.drawPixmap(0, 0, width(), height(), pixmap);

}


void login::SetTiltleHide()
{
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

}
login::~login()
{
    delete ui;
}
