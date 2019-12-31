#ifndef RECODEBASE_H
#define RECODEBASE_H

#include <QObject>

class RecodeBase
{
public:
    RecodeBase();

    /**/
    // 数据记录到目标
    // 参数3:是否需要记录时间
    template<typename T,typename TARGET>
    virtual bool Data2Target(T value,TARGET tar,bool recodeTime = false){
        return false;
    }
};

#endif // RECODEBASE_H
