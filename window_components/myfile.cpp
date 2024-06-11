#include "myfile.h"
#include "ui_myfile.h"

myfile::myfile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::myfile)
{
    ui->setupUi(this);
}

myfile::~myfile()
{
    delete ui;
}
