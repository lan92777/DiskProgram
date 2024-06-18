#ifndef COMMON_H
#define COMMON_H

#include <QWidget>
#include <common/des.h>
#include <QCryptographicHash>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QDebug>
#include <iostream>

//处理输出问题
#define cout qDebug() << "[ " << __FILE__ << ":"  << __LINE__ << " ] "

//正则表达式
const QString USER_REG      = "^[\u4e00-\u9fa5a-zA-Z0-9]{6,12}$";
const QString PASSWD_REG    = "^[a-zA-Z\\d_@#-*]{6,18}$";
const QString PHONE_REG     = "1\\d\\{10\\}";
const QString EMAIL_REG     = "^[a-zA-Z\\d\\._-]\\+@[a-zA-Z\\d_\\.-]\\+(\\.[a-zA-Z0-9_-]\\+)+$";
const QString IP_REG        = "((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)";
const QString PORT_REG      = "^[1-9]$|(^[1-9][0-9]$)|(^[1-9][0-9][0-9]$)|(^[1-9][0-9][0-9][0-9]$)|(^[1-6][0-5][0-5][0-3][0-5]$)";



//文件路径
const QString CONFFILE      = "C:/Users/what/Desktop/Disk/Disk/conf/cfg.json";      //配置文件存储信息路径
const QString FILETYPEDIR   = "conf/fileType";      //存放文件类型类型图片目录

class common : public QObject
{
    Q_OBJECT

public:
    explicit common(QObject *parent = 0);
    ~common();

    //字符串md5化
    QString getstrMd5(QString str);

    //配置文件记录登录信息
    void writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path = CONFFILE);
    //从配置文件中得到信息
    QString getCfgValue(QString title, QString key, QString path = CONFFILE);

private:

};

#endif // COMMON_H
