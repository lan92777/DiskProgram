#ifndef COMMON_H
#define COMMON_H

#include <QWidget>
#include <QCryptographicHash>
//文件路径
const QString CONFFILE      = "conf/cfg.json";

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


private:

};

#endif // COMMON_H
