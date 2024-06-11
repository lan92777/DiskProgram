#include "logintitle.h"
#include "ui_logintitle.h"


logintitle::logintitle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::logintitle)
{
    ui->setupUi(this);


    m_parent=parent;
    //设置图片样式
    SetLogOPicture();

    settitlename();

    SetSetPicture();

    SetMinWindowPicture();

    SetClsWindowPicture();

    //设置控件
    connect(ui->minwindow, &QToolButton::clicked, [=]()
    {
        m_parent->showMinimized();
    });

    connect(ui->setbutton, &QToolButton::clicked, [=]()
    {
        emit ShowSetWidget();
    });
    connect(ui->setbutton, &QToolButton::clicked, [=]()
    {
        emit CloseWindow();
    });
}

void logintitle::SetLogOPicture(){

    //设置图片元素
    logopicture.load(":/images/disklogo.png");
    //设置图片大小
    logopicture = logopicture.scaled(58, 58, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    //ui->login_logo->setScaledContents(true);
    //将图片元素赋予控件
    ui->login_logo->setPixmap(logopicture);

}

void logintitle::settitlename()
{
    //设置内容
    ui->DiskName->setText("DiskName");
    ui->DiskName->setStyleSheet("QLabel { color : blue; font-size: 24px; }");
}

void logintitle::SetSetPicture(){
    //设置图片
    seticon.addFile(tr(":/images/login_setting.png"));
    ui->setbutton->setIcon(seticon);
    ui->setbutton->setFlat(true);
    ui->setbutton->setText("");
    //设置内容

}
void logintitle::SetMinWindowPicture(){
    minicon.addFile(tr(":/images/login_min.png"));
    ui->minwindow->setIcon(minicon);
    ui->minwindow->setFlat(true);
    ui->minwindow->setText("");

}
void logintitle::SetClsWindowPicture(){
    closeicon.addFile(tr(":/images/login_close.png"));
    ui->closewindow->setIcon(closeicon);
    ui->closewindow->setFlat(true);
    ui->closewindow->setText("");
    //设置内容
}

//
void logintitle::mousePressEvent(QMouseEvent *ev)
{
    // 如果是左键, 计算窗口左上角, 和当前按钮位置的距离
    if(ev->button() == Qt::LeftButton)
    {
        // 计算和窗口左上角的相对位置
        m_pos = ev->globalPos() - m_parent->geometry().topLeft();
    }
}



void logintitle::mouseMoveEvent(QMouseEvent *ev)
{
    // 移动是持续的状态, 需要使用buttons
    if(ev->buttons() & Qt::LeftButton)
    {
        QPoint pos = ev->globalPos() - m_pos;
        m_parent->move(pos);
    }
}
logintitle::~logintitle()
{
    delete ui;
}
