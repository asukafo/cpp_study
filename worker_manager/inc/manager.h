#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "worker.h"

class Manager : public Worker
{
public:
    
    Manager(uint32_t uId, std::string sName, uint32_t uDeptId);

    virtual void m_ShowInfo();

    virtual std::string m_GetDeptName();
};

#endif // __Manager_H__
