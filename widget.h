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

    void sig_Convert_float(float num);//HEX4 float 浮点数
    void sig_Convert_double(float num);//HEX4 float 双精度浮点数

    void sig_Convert_bin(uint64_t num);//bin 二进制


public slots:
    void slot_Convert_INT_DEC(int64_t num);//DEC 有符号
    void slot_Convert_UINT_DEC(uint64_t num);//DEC 无符号

    void slot_Convert_INT_HEX4(int64_t num);//HEX4 有符号
    void slot_Convert_UINT_HEX4(uint64_t num);//HEX4 无符号
    void slot_Convert_float(float num);//HEX4 float 浮点数
    void slot_Convert_double(double num);//double 浮点数
    void slot_Convert_bin(uint64_t num);//bin 二进制

//    void slot_Convert_INT_HEX8(int64_t num);//HEX8 有符号
//    void slot_Convert_UINT_HEX8(uint64_t num);//HEX8 无符号

};

#endif // WIDGET_H
