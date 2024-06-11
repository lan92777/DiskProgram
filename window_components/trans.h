#ifndef TRANS_H
#define TRANS_H

#include <QWidget>

namespace Ui {
class trans;
}

class trans : public QWidget
{
    Q_OBJECT

public:
    explicit trans(QWidget *parent = 0);
    ~trans();

private:
    Ui::trans *ui;
};

#endif // TRANS_H
