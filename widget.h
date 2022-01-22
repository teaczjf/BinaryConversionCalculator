#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "convertor.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    Convertor *cvt;

private:
    Ui::Widget *ui;


signals:
    void sig_Convert_INT_DEC(int64_t num);//DEC 有符号
    void sig_Convert_UINT_DEC(uint64_t num);//DEC 无符号

    void sig_Convert_INT_HEX4(int64_t num);//HEX4 有符号
    void sig_Convert_UINT_HEX4(uint64_t num);//HEX4 无符号

public slots:
    void slot_Convert_INT_DEC(int64_t num);//DEC 有符号
    void slot_Convert_UINT_DEC(uint64_t num);//DEC 无符号

    void slot_Convert_INT_HEX4(int64_t num);//HEX4 有符号
    void slot_Convert_UINT_HEX4(uint64_t num);//HEX4 无符号

};

#endif // WIDGET_H
