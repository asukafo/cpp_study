#include "manager.h"

Manager::Manager(uint32_t uId, std::string sName, uint32_t uDeptId)
{
    m_uId     = uId;
    m_sName   = sName;
    m_uDeptId = uDeptId;
}

void Manager::m_ShowInfo()
{
    std::cout << "Manager No: "      << m_uId
              << " \tManager Name: " << m_sName
              << " \tDept: "          << m_GetDeptName()
              << " \tJob Description: complete task from boss and assign to employee." << std::endl;
}

std::string Manager::m_GetDeptName()
{
    return std::string("Manager");
}
