#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include "worker.h"

class Employee : public Worker
{
public:
    
    Employee(uint32_t uId, std::string sName, uint32_t uDeptId);

    virtual void m_ShowInfo();

    virtual std::string m_GetDeptName();
};

#endif // __EMPLOYEE_H__
