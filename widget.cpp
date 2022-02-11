#include "widget.h"
#include "ui_widget.h"
#include "stdio.h"
#include <qdebug.h>
#include <qstring.h>
#include <qradiobutton.h>
#include <qpushbutton.h>
#include "convertor.h"
#include <ctype.h>
int64_t num_int64=0;
int32_t num_int32=0;
int16_t num_int16=0;
int8_t  num_int8=0;

uint64_t num_uint64=0;
uint32_t num_uint32=0;
uint16_t num_uint16=0;
uint8_t  num_uint8=0;

float num_float=0;
double num_double=0;
union {float f; int i;}cvt_float;

bool flag=0;//计算类型0：有符号 0 无符号
union data_64b{
    uint64_t num_u64b;
    int64_t num_i64b;
    double num_d64b;
};

union data_32b{
    uint32_t num_u32b;
    int32_t num_i32b;
    float num_f32b;
};


union data_64b num_data_64b;
union data_32b num_data_32b;


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("进制转换器");
    this->setWindowIcon(QIcon(":/image/计算器.png"));

    connect(this,&Widget::sig_Convert_INT_DEC,this,&Widget::slot_Convert_INT_DEC);//有符号整数处理信号绑定
    connect(this,&Widget::sig_Convert_UINT_DEC,this,&Widget::slot_Convert_UINT_DEC);//无符号整数处理信号绑定
    connect(this,&Widget::sig_Convert_INT_HEX4,this,&Widget::slot_Convert_INT_HEX4);//有符号整数处理信号绑定
    connect(this,&Widget::sig_Convert_UINT_HEX4,this,&Widget::slot_Convert_UINT_HEX4);//无符号整数处理信号绑定
    connect(this,&Widget::sig_Convert_float,this,&Widget::slot_Convert_float);//浮点数处理信号绑定
    connect(this,&Widget::sig_Convert_double,this,&Widget::slot_Convert_double);//浮点数处理信号绑定
    connect(this,&Widget::sig_Convert_bin,this,&Widget::slot_Convert_bin);//浮点数处理信号绑定


    //    connect(this,&Widget::sig_Convert_INT_HEX4,this,&Widget::slot_Convert_INT_HEX4);//有符号整数处理信号绑定
    //    connect(this,&Widget::sig_Convert_UINT_HEX4,this,&Widget::slot_Convert_UINT_HEX4);//无符号整数处理信号绑定
    ui->radbtn_int->setChecked(true);
    flag=0;
    //两个radiobtn的配置
    connect(ui->radbtn_int,&QRadioButton::clicked,[=](){
        flag=0;
        qDebug()<<"切换为有符号模式";
    });

    connect(ui->radbtn_uint,&QRadioButton::clicked,[=](){
        flag=1;
        qDebug()<<"切换为无符号模式";
    });


    //==================================btn信号槽绑定==================================
    //DEC按钮 限制输入整数
    QRegExp regx("^-?\\d+$");//整数
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit_DEC );
    ui->lineEdit_DEC->setValidator(validator);
    connect(ui->pushButton_DEC,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_DEC->text();
        if(flag == 0)//有符号
        {
            num_int64 =str1.toLongLong();
            emit this->sig_Convert_INT_DEC(num_int64);
        }
        else
        {
            num_uint64 =str1.toULongLong();
            emit this->sig_Convert_UINT_DEC(num_uint64);
        }
    });

    //HEX4b
    QRegExp regx1("[A-Fa-f0-9]+$");//
    QValidator *validator1 = new QRegExpValidator(regx1, ui->lineEdit_HEX4 );
    ui->lineEdit_HEX4->setValidator(validator1);
    connect(ui->pushButton_HEX4,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_HEX4->text();
        if(flag == 0)//有符号
        {
            num_data_64b.num_u64b=str1.toULongLong(0,16);
            emit this->sig_Convert_INT_HEX4(num_data_64b.num_i64b);
        }
        else
        {
            num_uint64=str1.toULongLong(0,16);
            emit this->sig_Convert_UINT_HEX4(num_uint64);
        }
    });



    //HEX8b
    QRegExp regx2("[A-Fa-f0-9]+$");//
    QValidator *validator2 = new QRegExpValidator(regx2, ui->lineEdit_HEX8 );
    ui->lineEdit_HEX8->setValidator(validator2);

    connect(ui->pushButton_HEX8,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_HEX8->text();
        if(flag == 0)//有符号
        {
            num_data_64b.num_u64b=str1.toULongLong(0,16);
            emit this->sig_Convert_INT_HEX4(num_data_64b.num_i64b);
        }
        else
        {
            num_uint64=str1.toULongLong(0,16);
            emit this->sig_Convert_UINT_HEX4(num_uint64);
        }
    });

    //HEX16b
    QRegExp regx3("[A-Fa-f0-9]+$");//
    QValidator *validator3 = new QRegExpValidator(regx3, ui->lineEdit_HEX16 );
    ui->lineEdit_HEX16->setValidator(validator3);

    connect(ui->pushButton_HEX16,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_HEX16->text();
        if(flag == 0)//有符号
        {
            num_data_64b.num_u64b=str1.toULongLong(0,16);
            emit this->sig_Convert_INT_HEX4(num_data_64b.num_i64b);
        }
        else
        {
            num_uint64=str1.toULongLong(0,16);
            emit this->sig_Convert_UINT_HEX4(num_uint64);
        }
    });

    //HEX32b
    QRegExp regx4("[A-Fa-f0-9]+$");//
    QValidator *validator4 = new QRegExpValidator(regx4, ui->lineEdit_HEX32 );
    ui->lineEdit_HEX32->setValidator(validator4);

    connect(ui->pushButton_HEX32,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_HEX32->text();
        if(flag == 0)//有符号
        {
            num_data_64b.num_u64b=str1.toULongLong(0,16);
            emit this->sig_Convert_INT_HEX4(num_data_64b.num_i64b);
        }
        else
        {
            num_uint64=str1.toULongLong(0,16);
            emit this->sig_Convert_UINT_HEX4(num_uint64);
        }
    });

    //HEX64b
    QRegExp regx5("[A-Fa-f0-9]+$");//
    QValidator *validator5 = new QRegExpValidator(regx5, ui->lineEdit_HEX64 );
    ui->lineEdit_HEX64->setValidator(validator5);

    connect(ui->pushButton_HEX64,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_HEX64->text();
        if(flag == 0)//有符号
        {
            num_data_64b.num_u64b=str1.toULongLong(0,16);
            //            num_int64=str1.toInt(0,16);
            emit this->sig_Convert_INT_HEX4(num_data_64b.num_i64b);
        }
        else
        {
            num_uint64=str1.toULongLong(0,16);
            emit this->sig_Convert_UINT_HEX4(num_uint64);
        }
    });

    //float
    QRegExp regx6("^(-?\\d+)(\\.\\d+)?$");//    浮点数
    QValidator *validator6 = new QRegExpValidator(regx6, ui->lineEdit_FLOAT );
    ui->lineEdit_FLOAT->setValidator(validator6);
    connect(ui->pushButton_FLOAT,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_FLOAT->text();
        num_data_32b.num_f32b=str1.toFloat();
        emit this->slot_Convert_float(num_data_32b.num_f32b);
    });


    //double
    QRegExp regx7("^(-?\\d+)(\\.\\d+)?$");//    双精度浮点数
    QValidator *validator7 = new QRegExpValidator(regx7, ui->lineEdit_DOUBLE );
    ui->lineEdit_DOUBLE->setValidator(validator7);
    connect(ui->pushButton_DOUBLE,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_DOUBLE->text();
        num_data_64b.num_d64b=str1.toDouble();
        emit this->sig_Convert_double(num_data_64b.num_d64b);
    });

    //bin 二进制
    QRegExp regx8("[0-1]+$");//
    QValidator *validator8 = new QRegExpValidator(regx8, ui->lineEdit_BIN );
    ui->lineEdit_BIN->setValidator(validator8);

    connect(ui->pushButton_BIN,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit_BIN->text();
//        if(flag == 0)//有符号
//        {
            num_data_64b.num_u64b=str1.toULongLong(0,2);
            //            num_int64=str1.toInt(0,16);
            emit this->slot_Convert_bin(num_data_64b.num_i64b);
//        }
//        else
//        {
//            num_uint64=str1.toULongLong(0,2);
//            emit this->slot_Convert_bin(num_uint64);
//        }
    });
}

Widget::~Widget()
{
    delete ui;
}


//int64_t num_int64=0;
//int32_t num_int32=0;
//int16_t num_int16=0;
//int8_t  num_int8=0;

//uint64_t num_uint64=0;
//uint32_t num_uint32=0;
//uint16_t num_uint16=0;
//uint8_t  num_uint8=0;



/**
 * @brief Widget::slot_Convert_INT_DEC
 * 处理有符号整数的转换
 * @param num
 */
void Widget::slot_Convert_INT_DEC(int64_t num)
{
    qDebug()<<"开始有符号整数的转换 = "<<num;
    if(num < 0)
    {
        QString str1=(QString("%1").arg(num,16,16,QLatin1Char('0')));
        ui->lineEdit_HEX64->setText(str1);
        ui->lineEdit_HEX32->setText(str1.mid(8,8));
        ui->lineEdit_HEX16->setText(str1.mid(12,4));
        ui->lineEdit_HEX8->setText(str1.mid(14,2));
        ui->lineEdit_HEX4->setText(str1.mid(15,1));
        ui->lineEdit_BIN->setText(QString::number(num,2));
    }
    else
    {
        QString str1=(QString("%1").arg(num,16,16,QLatin1Char('0')));
        ui->lineEdit_HEX64->setText(str1);
        ui->lineEdit_HEX32->setText(str1.mid(8,8));
        ui->lineEdit_HEX16->setText(str1.mid(12,4));
        ui->lineEdit_HEX8->setText(str1.mid(14,2));
        ui->lineEdit_HEX4->setText(str1.mid(15,1));
        ui->lineEdit_BIN->setText(QString::number(num,2));
    }

    num_float =float(num);
    qDebug()<<num_float;
    //    cvt_float.f=num_float;
    ui->lineEdit_FLOAT->setText(QString::number(num_float,'f'));
    //    ui->lineEdit_HEX32->setText(QString::number(cvt_float.i,16));

    num_double =double(num);
    qDebug()<<num_double;
    ui->lineEdit_DOUBLE->setText(QString::number(num_double,'f',16));
}

/**
 * @brief Widget::slot_Convert_UINT_DEC
 * 处理无符号整数的转换
 * @param num
 */
void Widget::slot_Convert_UINT_DEC(uint64_t num)
{
    qDebug()<<"开始无符号整数的转换 = "<<num;

    QString str1=(QString("%1").arg(num,16,16,QLatin1Char('0')));
    ui->lineEdit_HEX64->setText(str1);
    ui->lineEdit_HEX32->setText(str1.mid(8,8));
    ui->lineEdit_HEX16->setText(str1.mid(12,4));
    ui->lineEdit_HEX8->setText(str1.mid(14,2));
    ui->lineEdit_HEX4->setText(str1.mid(15,1));
    ui->lineEdit_BIN->setText(QString::number(num,2));

    num_float =float(num);
    ui->lineEdit_FLOAT->setText(QString::number(num_float,'f'));

    num_double =double(num);
    ui->lineEdit_DOUBLE->setText(QString::number(num_double,'f',16));
}



/**
 * @brief Widget::slot_Convert_INT_HEX4
 * 处理有符号HEX数的转换
 * @param num
 */
void Widget::slot_Convert_INT_HEX4(int64_t num)
{
    qDebug()<<"开始有符号HEX数的转换 = "<<num;

    if(num < 0)
    {
        QString str1=(QString("%1").arg(num,16,16,QLatin1Char('0')));
        ui->lineEdit_DEC->setText(QString::number(num,10));
        ui->lineEdit_HEX64->setText(str1);
        ui->lineEdit_HEX32->setText(str1.mid(8,8));
        ui->lineEdit_HEX16->setText(str1.mid(12,4));
        ui->lineEdit_HEX8->setText(str1.mid(14,2));
        ui->lineEdit_HEX4->setText(str1.mid(15,1));
        ui->lineEdit_BIN->setText(QString::number(num,2));
    }
    else
    {
        QString str1=(QString("%1").arg(num,16,16,QLatin1Char('0')));
        ui->lineEdit_DEC->setText(QString::number(num,10));
        ui->lineEdit_HEX64->setText(str1);
        ui->lineEdit_HEX32->setText(str1.mid(8,8));
        ui->lineEdit_HEX16->setText(str1.mid(12,4));
        ui->lineEdit_HEX8->setText(str1.mid(14,2));
        ui->lineEdit_HEX4->setText(str1.mid(15,1));
        ui->lineEdit_BIN->setText(QString::number(num,2));
    }
    num_data_64b.num_i64b=num;

    num_data_32b.num_u32b =num_data_64b.num_u64b&0x0000000ffffffff;
    ui->lineEdit_FLOAT->setText(QString("%1").arg(num_data_32b.num_f32b));


    ui->lineEdit_DOUBLE->setText(QString::number(num_data_64b.num_d64b,'g',16));
}




/**
 * @brief Widget::slot_Convert_UINT_HEX4
 * 处理无符号HEX数的转换
 * @param num
 */
void Widget::slot_Convert_UINT_HEX4(uint64_t num)
{
    qDebug()<<"开始无符号HEX数的转换 = "<<num;

    QString str1=(QString("%1").arg(num,16,16,QLatin1Char('0')));
    ui->lineEdit_DEC->setText(QString::number(num,10));
    ui->lineEdit_HEX64->setText(str1);
    ui->lineEdit_HEX32->setText(str1.mid(8,8));
    ui->lineEdit_HEX16->setText(str1.mid(12,4));
    ui->lineEdit_HEX8->setText(str1.mid(14,2));
    ui->lineEdit_HEX4->setText(str1.mid(15,1));
    ui->lineEdit_BIN->setText(QString::number(num,2));
    num_data_64b.num_u64b=num;
    num_data_32b.num_u32b =num_data_64b.num_u64b&0x0000000ffffffff;
    ui->lineEdit_FLOAT->setText(QString("%1").arg(num_data_32b.num_f32b));
    ui->lineEdit_DOUBLE->setText(QString::number(num_data_64b.num_d64b,'g',16));
}


/**
 * @brief Widget::slot_Convert_float
 * 处理浮点数的转换
 * @param num
 */
void Widget::slot_Convert_float(float num)
{
    num_data_32b.num_f32b=num;
    int k1=num_data_32b.num_f32b;
    QString str1=(QString("%1").arg(num_data_32b.num_u32b,16,16,QLatin1Char('0')));
    ui->lineEdit_DEC->setText(QString::number(k1,10));
    ui->lineEdit_HEX64->setText(str1);
    ui->lineEdit_HEX32->setText(str1.mid(8,8));
    ui->lineEdit_HEX16->setText(str1.mid(12,4));
    ui->lineEdit_HEX8->setText(str1.mid(14,2));
    ui->lineEdit_HEX4->setText(str1.mid(15,1));
    ui->lineEdit_BIN->setText(QString::number(num_data_32b.num_u32b,2));

    ui->lineEdit_FLOAT->setText(QString("%1").arg(num_data_32b.num_f32b));

    num_double =num_data_32b.num_f32b;
    ui->lineEdit_DOUBLE->setText(QString::number(num_double,'f',16));
    //    ui->lineEdit_FLOAT->setText(QString::number(num_data_32b.num_u32b,'f',16));

}


/**
 * @brief Widget::slot_Convert_double
 * 处理双精度浮点数的转换
 * @param num
 */
void Widget::slot_Convert_double(double num)
{
    num_data_64b.num_d64b=num;
    int k1=num_data_64b.num_d64b;
    QString str1=(QString("%1").arg(num_data_64b.num_u64b,16,16,QLatin1Char('0')));
    ui->lineEdit_DEC->setText(QString::number(k1,10));
    ui->lineEdit_HEX64->setText(str1);
    ui->lineEdit_HEX32->setText(str1.mid(8,8));
    ui->lineEdit_HEX16->setText(str1.mid(12,4));
    ui->lineEdit_HEX8->setText(str1.mid(14,2));
    ui->lineEdit_HEX4->setText(str1.mid(15,1));
    ui->lineEdit_BIN->setText(QString::number(num_data_64b.num_u64b,2));
    double f1= num_data_64b.num_d64b;
    ui->lineEdit_FLOAT->setText(QString("%1").arg(f1));

    num_double =num_data_64b.num_d64b;
    ui->lineEdit_DOUBLE->setText(QString::number(num_double,'f',16));
//    ui->lineEdit_DOUBLE->setText(QString("%1").arg(num_double));

    //    ui->lineEdit_FLOAT->setText(QString::number(num_data_32b.num_u32b,'f',16));

}


/**
 * @brief Widget::slot_Convert_bin
 * 二进制转换
 * @param num
 */
void Widget::slot_Convert_bin(uint64_t num)
{
    qDebug()<<"开始无符号HEX数的转换 = "<<num;

    QString str1=(QString("%1").arg(num,16,16,QLatin1Char('0')));
    ui->lineEdit_DEC->setText(QString::number(num,10));
    ui->lineEdit_HEX64->setText(str1);
    ui->lineEdit_HEX32->setText(str1.mid(8,8));
    ui->lineEdit_HEX16->setText(str1.mid(12,4));
    ui->lineEdit_HEX8->setText(str1.mid(14,2));
    ui->lineEdit_HEX4->setText(str1.mid(15,1));
    ui->lineEdit_BIN->setText(QString::number(num,2));
    num_data_64b.num_u64b=num;
    num_data_32b.num_u32b =num_data_64b.num_u64b&0x0000000ffffffff;
    ui->lineEdit_FLOAT->setText(QString("%1").arg(num_data_32b.num_f32b));
    ui->lineEdit_DOUBLE->setText(QString::number(num_data_64b.num_d64b,'g',16));
//    ui->lineEdit_DOUBLE->setText(QString("%1").arg(num_data_64b.num_d64b));

}

