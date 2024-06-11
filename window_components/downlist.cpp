#include "downlist.h"
#include "ui_downlist.h"

downlist::downlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downlist)
{
    ui->setupUi(this);
}

downlist::~downlist()
{
    delete ui;
}
