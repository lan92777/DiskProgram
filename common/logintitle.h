#ifndef LOGINTITLE_H
#define LOGINTITLE_H

#include <QWidget>
#include <QIcon>
#include <QToolButton>

namespace Ui {
class logintitle;
}

class logintitle : public QWidget
{
    Q_OBJECT
public:
    explicit logintitle(QWidget *parent = 0);
    ~logintitle();

    /*------------
    设置图片样式
    -------------*/
    //设置图片需要的元素
    void SetLogOPicture();
    void settitlename();
    void SetSetPicture();
    void SetMinWindowPicture();
    void SetClsWindowPicture();


    /*------------
    设置与父窗口的交互
    -------------*/
    //设置父窗口指针
    void setparent(QWidget *parent);

private:
    //窗口元素是
    Ui::logintitle *ui;
    //父窗口元素
    QWidget *m_parent;
    //图片元素
    QPixmap logopicture;
    QIcon seticon;
    QIcon closeicon;
    QIcon minicon;

signals:
    void ShowSetWidget();
    void CloseWindow();
};

#endif // LOGINTITLE_H
