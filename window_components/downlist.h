#ifndef DOWNLIST_H
#define DOWNLIST_H

#include <QWidget>

namespace Ui {
class downlist;
}

class downlist : public QWidget
{
    Q_OBJECT

public:
    explicit downlist(QWidget *parent = 0);
    ~downlist();

private:
    Ui::downlist *ui;
};

#endif // DOWNLIST_H
