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

    //测试
    ui->log_usr->setText("12345678");
    ui->log_pwd->setText("12345678");

    //测试

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
        //测试
        address="192.168.73.132";
        //address="192.168.73.132";
        port="80";
        //测试


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
        cout << "post url:" << url << "post data: " << memarry;
        //检验回发的数据
        connect(reply, &QNetworkReply::finished, [=]()
        {
            // 出错了
            if (reply->error() != QNetworkReply::NoError)
            {
                cout << reply->errorString();
                //释放资源
                reply->deleteLater();
                return;
            }
            //读取数据
            QByteArray json =reply->readAll();
            //数据包例子如下
            /*
              "code":	"000",
              "token":	"c818303fcaac6d8732ab69c0a4127958"
            */
            cout << "服务器反馈数据: " << json;
            //将数据存储到字符串列表
            QStringList tmpList = getLoginStatus(json); //common.h
            //判断是否成功
            if( tmpList.at(0) == "000" )
            {
                cout << "登陆成功";


            }
            else
            {
                QMessageBox::warning(this, "登录失败", "用户名或密码不正确！！！");
            }

            reply->deleteLater(); //释放资源
        });
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

//获得登陆状态
 QStringList login::getLoginStatus(QByteArray json)
 {
     QJsonParseError error;
     QStringList list;

     // 将来源数据json转化为JsonDocument
     // 由QByteArray对象构造一个QJsonDocument对象，用于我们的读写操作
     QJsonDocument doc = QJsonDocument::fromJson(json, &error);
     if (error.error == QJsonParseError::NoError)
     {
         if (doc.isNull() || doc.isEmpty())
         {
             cout << "doc.isNull() || doc.isEmpty()";
             return list;
         }

         if( doc.isObject() )
         {
             //取得最外层这个大对象
             QJsonObject obj = doc.object();
             cout << "服务器返回的数据" << obj;
             //状态码
             list.append( obj.value( "code" ).toString() );
             //登陆token
             list.append( obj.value( "token" ).toString() );
         }
     }
     else
     {
         cout << "err = " << error.errorString();
     }

     return list;
 }
