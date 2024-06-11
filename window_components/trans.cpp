#include "trans.h"
#include "ui_trans.h"

trans::trans(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trans)
{
    ui->setupUi(this);
}

trans::~trans()
{
    delete ui;
}
