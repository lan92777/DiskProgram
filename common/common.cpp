#include "common.h"

//QString common::m_typePath = FILETYPEDIR;

common::common(QObject *parent)
{
    Q_UNUSED(parent)
}

//字符串md5化
QString common::getstrMd5(QString str)
{
    QByteArray array;
    //md5加密
    array = QCryptographicHash::hash ( str.toLocal8Bit(), QCryptographicHash::Md5 );
    return array.toHex();
}


 void common::writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path)
 {
     // web_server信息
     QString ip = getCfgValue("web_server", "ip");
     QString port = getCfgValue("web_server", "port");
     cout<<ip;
     cout<<port;

     QMap<QString, QVariant> web_server;
     web_server.insert("ip", ip);
     web_server.insert("port", port);

     // type_path信息
     QMap<QString, QVariant> type_path;
     type_path.insert("path", FILETYPEDIR);

     // login信息
     QMap<QString, QVariant> login;

     // 登陆信息加密
     int ret = 0;

     // 登陆用户加密
     unsigned char encUsr[1024] = {0};
     int encUsrLen;
     // QString -> const char*
     // QString toutf8(QByteArray)->char*  (.data())
     // toLocal8Bit(), 转换为本地字符集，如果windows则为gbk编码，如果linux则为utf-8编码
     ret = DesEnc((unsigned char *)user.toLocal8Bit().data(), user.toLocal8Bit().size(), encUsr, &encUsrLen);
     if(ret != 0)//加密失败
     {
         cout << "DesEnc err";
         return;
     }

     // 用户密码加密
     unsigned char encPwd[512] = {0};
     int encPwdLen;
     // toLocal8Bit(), 转换为本地字符集，如果windows则为gbk编码，如果linux则为utf-8编码
     ret = DesEnc((unsigned char *)pwd.toLocal8Bit().data(), pwd.toLocal8Bit().size(), encPwd, &encPwdLen);
     if(ret != 0)
     {
         cout << "DesEnc err";
         return;
     }

     // 再次加密
     // base64转码加密，目的将加密后的二进制转换为base64字符串
     login.insert("user",  QByteArray((char *)encUsr, encUsrLen).toBase64());
     login.insert("pwd", QByteArray((char *)encPwd, encPwdLen).toBase64() );
     if(isRemeber == true)
     {
          login.insert("remember", "yes");
     }
     else
     {
         login.insert("remember", "no");
     }

     // QVariant类作为一个最为普遍的Qt数据类型的联合
     // QVariant为一个万能的数据类型--可以作为许多类型互相之间进行自动转换。
     QMap<QString, QVariant> json;
     json.insert("web_server", web_server);
     json.insert("type_path", type_path);
     json.insert("login", login);


     QJsonDocument jsonDocument = QJsonDocument::fromVariant(json);
     if ( jsonDocument.isNull() == true)
     {
         cout << " QJsonDocument::fromVariant(json) err";
         return;
     }

     QFile file(path);

     if( false == file.open(QIODevice::WriteOnly) )
     {
         cout << "file open err";
         return;
     }

     //json内容写入文件
     file.write(jsonDocument.toJson());
     file.close();
 }
 QString common::getCfgValue(QString title, QString key, QString path )
 {
     QFile file(path);

     // 只读方式打开
     if( false == file.open(QIODevice::ReadOnly) )
     {
         // 打开失败
         cout << "file open err";
         return "";
     }

     QByteArray json = file.readAll(); // 读取所有内容
     file.close(); // 关闭文件

     QJsonParseError error;

     // 将来源数据json转化为JsonDocument
     // 由QByteArray对象构造一个QJsonDocument对象，用于我们的读写操作
     QJsonDocument doc = QJsonDocument::fromJson(json, &error);
     if (error.error == QJsonParseError::NoError) // 没有出错
     {
         if (doc.isNull() || doc.isEmpty())
         {
             cout << "doc.isNull() || doc.isEmpty()";
             return "";
         }

         if( doc.isObject()) // 如果对象不为空
         {
             // QJsonObject json对象，描述json数据中{}括起来部分
             QJsonObject obj = doc.object();// 取得最外层这个大对象

             QJsonObject tmp = obj.value( title ).toObject();
             QStringList list = tmp.keys(); // 取出key列表
             for(int i = 0; i < list.size(); ++i)
             {
                 if( list.at(i) == key )
                 {
                     return tmp.value( list.at(i) ).toString();
                 }
             }

         }
     }
     else
     {
         cout << "err = " << error.errorString();
     }

     return "";


 }
common::~common()
{

}
