#include "common.h"


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


 void writeLoginInfo(QString user, QString pwd, bool isRemeber, QString path = CONFFILE)
 {




 }
common::~common()
{

}
