#ifndef MYFILE_H
#define MYFILE_H

#include <QWidget>

namespace Ui {
class myfile;
}

class myfile : public QWidget
{
    Q_OBJECT

public:
    explicit myfile(QWidget *parent = 0);
    ~myfile();

private:
    Ui::myfile *ui;
};

#endif // MYFILE_H
