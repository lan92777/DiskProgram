#include "sharelist.h"
#include "ui_sharelist.h"

sharelist::sharelist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sharelist)
{
    ui->setupUi(this);
}

sharelist::~sharelist()
{
    delete ui;
}
