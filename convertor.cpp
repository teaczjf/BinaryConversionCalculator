#include "convertor.h"
#include <qdebug.h>
/**
 * @brief Convertor::Convertor
 * 构造函数
 * @param parent
 */
Convertor::Convertor(QObject *parent) : QObject(parent)
{

//    connect(this,&Convertor::sig_Convert_INT_DEC,this,&Convertor::slot_Convert_INT_DEC);//有符号整数处理信号绑定
}

/**
 * @brief convertor::slot_Convert_INT_DEC
 * 处理有符号整数的转换
 * @param packet
 */
//void Convertor::slot_Convert_INT_DEC(int64_t num)
//{
//    qDebug()<<"开始有符号整数的转换 = "<<num;
//}
