#ifndef COMMON_H
#define COMMON_H

#include <QWidget>
#include <QCryptographicHash>


class common : public QWidget
{
    Q_OBJECT

public:
    explicit common(QWidget *parent = 0);
    ~common();
    QString getstrMd5(QString str);



private:

};

#endif // COMMON_H
