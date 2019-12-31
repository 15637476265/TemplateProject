#ifndef RECODEBYCHART_H
#define RECODEBYCHART_H

#include "RecodeBase.h"

class RecodeByChart : public RecodeBase
{
public:
    RecodeByChart();

    template<typename T,typename TARGET>
    virtual bool Data2Target(T value,TARGET tar,bool recodeTime = false) override{

    }
};

#endif // RECODEBYCHART_H
