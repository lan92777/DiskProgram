#include "common.h"



common::~common()
{

}

QString common::getstrMd5(QString str)
{
    QByteArray array;
    //md5加密
    array = QCryptographicHash::hash ( str.toLocal8Bit(), QCryptographicHash::Md5 );

    return array.toHex();
}
