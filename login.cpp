#include "login.h"
#include "ui_login.h"

/*
登陆界面


*/

//指定父类和生成赋予ui
login::login(QWidget *parent) :QDialog(parent),ui(new Ui::login)
{

    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}
