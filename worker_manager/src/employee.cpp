#include "employee.h"

Employee::Employee(uint32_t uId, std::string sName, uint32_t uDeptId)
{
    m_uId     = uId;
    m_sName   = sName;
    m_uDeptId = uDeptId;
}

void Employee::m_ShowInfo()
{
    std::cout << "Employee No: "      << m_uId
              << " \tEmployee Name: " << m_sName
              << " \tDept: "          << m_GetDeptName()
              << " \tJob Description: complete task from manager." << std::endl;
}

std::string Employee::m_GetDeptName()
{
    return std::string("Employee");
}
