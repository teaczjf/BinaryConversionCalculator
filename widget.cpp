#include "widget.h"
#include "ui_widget.h"
#include "stdio.h"
#include <qdebug.h>
#include <qstring.h>
#include <qradiobutton.h>
#include <qpushbutton.h>
int64_t num_int64=0;
uint64_t num_uint64=0;
float num_float=0;
double num_double=0;

bool flag=0;//计算类型0：有符号 0 无符号

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("进制转换器");
    this->setWindowIcon(QIcon(":/image/计算器.png"));


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

    //==================================十进制==================================
    //限制框中输入参数范围
    QRegExp regx("^-?\\d+$");//限制只有- 和数字1到9可输入。
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit_DEC );
    ui->lineEdit_DEC->setValidator(validator);

    //设置十进制btn的按钮槽函数连接
    connect(ui->pushButton_DEC,&QPushButton::clicked,[=](){
        qDebug()<<"从DEC中取值转换";
        QString str1 = ui->lineEdit_DEC->text();
        if(flag == 0)
        {
            num_int64 =str1.toLongLong();
            ui->lineEdit_DEC->setText(QString::number(num_int64,10));
            ui->lineEdit_HEX64->setText(QString::number(num_int64,16));
            ui->lineEdit_BIN->setText(QString::number(num_int64,2));
        }
        else
        {
            num_uint64 =str1.toULongLong();
            ui->lineEdit_DEC->setText(QString::number(num_uint64,10));
            ui->lineEdit_HEX64->setText(QString::number(num_uint64,16));
            ui->lineEdit_BIN->setText(QString::number(num_uint64,2));
        }

        num_float =str1.toFloat();
        qDebug()<<num_float;
        ui->lineEdit_FLOAT->setText(QString::number(num_float,'f'));
        num_double =str1.toDouble();
        qDebug()<<num_double;
        ui->lineEdit_DOUBLE->setText(QString::number(num_double,'f',16));
    });

    //==================================十六进制==================================
    //限制框中输入参数范围
    QRegExp regx1("^[A-Fa-f0-9]+$");//由数字和6个英文字母组成的字符串
    QValidator *validator1 = new QRegExpValidator(regx1, ui->lineEdit_HEX64 );
    ui->lineEdit_HEX64->setValidator(validator1);
    ui->lineEdit_HEX64->setMaxLength(16);

    //设置十进制btn的按钮槽函数连接
    connect(ui->pushButton_HEX64,&QPushButton::clicked,[=](){
        qDebug()<<"从HEX中取值转换";
        QString str1 = ui->lineEdit_HEX64->text();
        if(flag == 0)//有符号
        {
//            QString str1("FFFFFFFF");
//            qDebug() << qint32(str1.toUInt(nullptr,16));//12
//            QByteArray ba = QByteArray::fromHex(str1.toLatin1());
//            qDebug() << qint32(ba.toHex().toUInt(nullptr,16));//12


            num_int64 =qint64(str1.toULongLong(nullptr,16));
            qDebug() << qint64(str1.toULongLong(nullptr,16));

            qDebug()<<str1<<" == "<<num_int64;
            ui->lineEdit_DEC->setText(QString::number(num_int64,10));
            ui->lineEdit_HEX64->setText(QString::number(num_int64,16));
            ui->lineEdit_BIN->setText(QString::number(num_int64,2));
        }
        else
        {
            num_uint64 =str1.toUInt(Q_NULLPTR,16);
            qDebug()<<num_uint64;
            ui->lineEdit_DEC->setText(QString::number(num_uint64,10));
            ui->lineEdit_HEX64->setText(QString::number(num_uint64,16));
            ui->lineEdit_BIN->setText(QString::number(num_uint64,2));
        }

        num_float =str1.toFloat();
        qDebug()<<num_float;
        ui->lineEdit_FLOAT->setText(QString::number(num_float,'f'));
        num_double =str1.toDouble();
        qDebug()<<num_double;
        ui->lineEdit_DOUBLE->setText(QString::number(num_double,'f',16));
    });

}

Widget::~Widget()
{
    delete ui;
}


