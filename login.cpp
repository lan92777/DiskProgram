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
    //设置数据格式
    SetDateFormat();



    //切换注册界面
    connect(ui->log_register_btn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->Register);
    });
    //切换设置界面
    connect(ui->loginhead, &logintitle::ShowSetWidget,[=](){
        ui->stackedWidget->setCurrentWidget(ui->Set);
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
        else if(ui->stackedWidget->currentWidget() == ui->Set)
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
//设置数据格式
void login::SetDateFormat()
{
    //设置密码
    ui->log_pwd->setEchoMode(QLineEdit::Password);
    ui->reg_pwd->setEchoMode(QLineEdit::Password);
    ui->reg_surepwd->setEchoMode(QLineEdit::Password);
    //首次输入者
    ui->log_usr->setFocus();
    //输入提示
    ui->log_usr->setToolTip("合法字符:[a-z|A-Z|#|@|0-9|-|_|*],字符个数: 3~16");
    ui->reg_usr->setToolTip("合法字符:[a-z|A-Z|#|@|0-9|-|_|*],字符个数: 3~16");
    ui->reg_nickname->setToolTip("合法字符:[a-z|A-Z|#|@|0-9|-|_|*],字符个数: 3~16");
    ui->log_pwd->setToolTip("合法字符:[a-z|A-Z|#|@|0-9|-|_|*],字符个数: 6~18");
    ui->reg_pwd->setToolTip("合法字符:[a-z|A-Z|#|@|0-9|-|_|*],字符个数: 6~18");
    ui->reg_surepwd->setToolTip("合法字符:[a-z|A-Z|#|@|0-9|-|_|*],字符个数: 6~18");
}
