#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

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

    //设置窗口移动


    //样式设置
protected:
  //  void paintEvent(QPaintEvent *);


private:
    Ui::login *ui;
};

#endif // LOGIN_H
