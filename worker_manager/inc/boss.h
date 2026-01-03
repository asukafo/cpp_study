#ifndef __BOSS_H__
#define __BOSS_H__

#include "worker.h"

class Boss : public Worker
{
public:
    
    Boss(uint32_t uId, std::string sName, uint32_t uDeptId);

    virtual void m_ShowInfo();

    virtual std::string m_GetDeptName();
};

#endif // __BOSS_H__
