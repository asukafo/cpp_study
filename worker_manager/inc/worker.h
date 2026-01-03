#ifndef __WORKER_H__
#define __WORKER_H__

#include <iostream>
#include <cstdint>
#include <string>

class Worker
{
public:
    virtual void m_ShowInfo() = 0;

    virtual std::string m_GetDeptName() = 0;

    uint32_t m_uId;
    std::string m_sName;
    uint32_t m_uDeptId;
};


#endif // __WORKER_H__
