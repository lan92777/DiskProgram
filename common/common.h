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

#define cout qDebug() << "[ " << __FILE__ << ":"  << __LINE__ << " ] "

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
