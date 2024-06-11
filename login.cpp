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
    ui->stackedWidget->setCurrentWidget(ui->Login);
    //切换界面
    connect(ui->log_register_btn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->Register);
    });



    //关闭操作
    connect(ui->loginhead, &logintitle::CloseWindow, [=]()
    {
         if(ui->stackedWidget->currentWidget() == ui->Login)
        {
            close();
        }
        else if(ui->stackedWidget->currentWidget() == ui->Register)
        {
            ui->stackedWidget->setCurrentWidget(ui->Login);
        }
        else
        {
            close();
        }


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
