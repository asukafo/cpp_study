#include "boss.h"

Boss::Boss(uint32_t uId, std::string sName, uint32_t uDeptId)
{
    m_uId     = uId;
    m_sName   = sName;
    m_uDeptId = uDeptId;
}

void Boss::m_ShowInfo()
{
    std::cout << "Boss No: "      << m_uId
              << " \tBoss Name: " << m_sName
              << " \tDept: "          << m_GetDeptName()
              << " \tJob Description: Manage all tasks in company." << std::endl;
}

std::string Boss::m_GetDeptName()
{
    return std::string("Boss");
}
