#ifndef DATARECODEHELPER_H
#define DATARECODEHELPER_H

#include <QObject>


//数据记录模式：
//1.TXT  2.SQL   3.表格
namespace DataRecode {
    typedef enum Control_Tag{
        TXT_MODE =(0u),
        SQL_MODE ,
        CHART_MODE,
        TAG_ALL
    }REQUEST_MODE;
}

static DataRecode::REQUEST_MODE current_mode = DataRecode::TXT_MODE;

class DataRecodeHelper
{
public:
    DataRecodeHelper();
};

#endif // DATARECODEHELPER_H
