#ifndef SHARELIST_H
#define SHARELIST_H

#include <QWidget>

namespace Ui {
class sharelist;
}

class sharelist : public QWidget
{
    Q_OBJECT

public:
    explicit sharelist(QWidget *parent = 0);
    ~sharelist();

private:
    Ui::sharelist *ui;
};

#endif // SHARELIST_H
