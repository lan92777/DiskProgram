#include "login.h"
#include "ui_login.h"



//指定父类和生成赋予ui
login::login(QWidget *parent) :QDialog(parent),ui(new Ui::login)
{

    ui->setupUi(this);

    SetTiltleHide();




}

void C(QPaintEvent *){




};



void login::SetTiltleHide()
{
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

}
login::~login()
{
    delete ui;
}
