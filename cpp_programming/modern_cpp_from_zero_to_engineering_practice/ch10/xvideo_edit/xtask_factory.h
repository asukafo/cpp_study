#ifndef _XTASK_FACTORY_H_
#define _XTASK_FACTORY_H_

#include "xtask.h"
#include<memory>
class XTaskFactory
{
public:
    static std::unique_ptr<XTask> Create(int type = 0);
};

#endif //_XTASK_FACTORY_H_