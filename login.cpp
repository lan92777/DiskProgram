#include "login.h"
#include "ui_login.h"
#include <QPainter>


//指定父类和生成赋予ui
login::login(QWidget *parent) :QDialog(parent),ui(new Ui::login)
{

    ui->setupUi(this);
    //--初始化--
    //网络请求
    m_manager = com.getNetManager();

    //设置程序属性
    SetTiltleHide();
    this->setWindowIcon(QIcon(":/images/logo.ico"));
    ui->stackedWidget->setCurrentWidget(ui->Login);

    //设置数据格式
    SetDateFormat();



    //切换注册界面
    connect(ui->log_register_btn,&QToolButton::clicked,[=](){
        ui->stackedWidget->setCurrentWidget(ui->Register);

        ui->reg_usr->setFocus();
    });
    //切换设置界面
    connect(ui->loginhead, &logintitle::SetWindow,[=](){
        ui->stackedWidget->setCurrentWidget(ui->Set);
        ui->address_server->setFocus();

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
            //清空数据然后返回到登陆界面
            ui->reg_usr->clear();
            ui->reg_nickname->clear();
            ui->reg_pwd->clear();
            ui->reg_surepwd->clear();
            ui->reg_phone->clear();
            ui->reg_mail->clear();
            ui->stackedWidget->setCurrentWidget(ui->Login);
            ui->log_usr->setFocus();
        }
        else if(ui->stackedWidget->currentWidget() == ui->Set)
        {
            ui->address_server->clear();
            ui->port_server->clear();
            ui->stackedWidget->setCurrentWidget(ui->Login);

            ui->log_usr->setFocus();
        }
        else
        {
            close();
        }

    });
    //输入操作时 回车键的设置
    EnterEvent();
    this->installEventFilter(this);

    //登陆信息的json设置
    connect(ui->login_btn,&QToolButton::clicked,[=](){
        //初始化数据
        QString user = ui->log_usr->text();
        QString pwd = ui->log_pwd->text();
        QString address = ui->address_server->text();
        QString port = ui->port_server->text();
        //判断数据是否为空
        if(ui->log_usr->text().isEmpty())
        {
             QMessageBox::information(this, "提示", "用户名不能为空");
             return 0;
        }
        if(ui->log_usr->text().isEmpty())
        {
             QMessageBox::information(this, "提示", "用户名不能为空");
             return 0;
        }
        //正则表达式判断登陆数据
        if(REgexp())
        {
            return 0;
        }
        //写信息写进配置文件
        com.writeLoginInfo(user,pwd,ui->rember_pwd->isChecked());
        //获取登陆信息的比特流
        QByteArray memarry =  SetJoinLogin();
        //--设置网络包--
        //设置登陆url
        QNetworkRequest request;
        QString url = QString("http://%1:%2/login").arg(address).arg(port);
        request.setUrl(QUrl(url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json"));
        request.setHeader(QNetworkRequest::ContentLengthHeader, QVariant(memarry.size()));
        //发送数据
        QNetworkReply* reply = m_manager->post(request, memarry);

         return 0;
    });


     //测试操作
    testdate();

}
int login::REgexp(){
    QRegExp regexp(USER_REG);
    if(!regexp.exactMatch(ui->log_usr->text()))
    {
        QMessageBox::warning(this, "警告", "用户名格式不正确");
        ui->log_usr->clear();
        ui->log_usr->setFocus();
        return 1;
    }
    regexp.setPattern(PASSWD_REG);
    if(!regexp.exactMatch(ui->log_pwd->text()))
    {
        QMessageBox::warning(this, "警告", "密码格式不正确");
        ui->log_pwd->clear();
        ui->log_pwd->setFocus();
        return  1;
    }
    return 0;

}

QByteArray login::SetJoinLogin(){
    QMap<QString, QVariant> login;
    login.insert("user", ui->log_usr->text());
    login.insert("pwd", com.getstrMd5((QString)ui->log_pwd->text()));
    QJsonDocument jsonDocument = QJsonDocument::fromVariant(login);
    if ( jsonDocument.isNull() )
    {
        qDebug() << ("Registered is empty");
        return "";
    }
    return jsonDocument.toJson();

}
//背景设置
void login::paintEvent(QPaintEvent *){
    //绘画背景信息
    QPainter painter(this);
    QPixmap pixmap(":/images/login_bk.jpg");
    painter.drawPixmap(0, 0, width(), height(), pixmap);

}
//隐藏自带标题栏
void login::SetTiltleHide()
{
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);

}
login::~login()
{
    delete ui;
}
//设置数据格式提醒
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
//设置测试数据
void login::testdate(){
    ui->reg_usr->setText("kevin_666");
    ui->reg_nickname->setText("kevin@666");
    ui->reg_pwd->setText("123456");
    ui->reg_surepwd->setText("123456");
    ui->reg_phone->setText("11111111111");
    ui->reg_mail->setText("abc@qq.com");

}
//输入框enter事件
 void login::EnterEvent(){

     //connect(ui->log_usr, &QLineEdit::returnPressed,[=](){
    //   ui->log_pwd->setFocus();
  //

    //  });




 }
//事件过滤器
 bool login::eventFilter(QObject* watched, QEvent* event)
 {
     /*
     if (ui->log_usr->hasFocus())
     {
        //disconnect(lineEdit, &QLineEdit::textChanged, this, &MyWidget::onTextChanged);
         return 0;

     }
     */

     if (event->type() == QEvent::KeyPress)
     {
         QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
          if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
                       return true;

            }
        return    QWidget::eventFilter(watched, event);
     }
     return    QWidget::eventFilter(watched, event);
}

