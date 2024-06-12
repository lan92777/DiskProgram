#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QPainter>
#include <QDebug>
#include<common/logintitle.h>
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();
    //设置窗口标题栏隐藏
    void SetTiltleHide();
    //样式设置
    void SetDateFormat();
    //测试操作
    void testdate();
    //输入时回车键的操作
    void EnterEvent();
protected:
    //背景设置（回调函数）
    void paintEvent(QPaintEvent *);
    //事件过滤器(处理enter输入的问题)
    bool eventFilter(QObject* watched, QEvent* event) override;
private:
    Ui::login *ui;
};

#endif // LOGIN_H
