#include <iostream>
#include <cstdint>

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include "worker_manager.h"

void test()
{
    Worker* worker = NULL;
    worker = new Employee(1, "A", 1);
    worker->m_ShowInfo();
    delete worker;

    worker = new Manager(2, "B", 2);
    worker->m_ShowInfo();
    delete worker;

    worker = new Boss(3, "C", 3);
    worker->m_ShowInfo();
    delete worker;

}

int main()
{
    WorkerManager wm;
    std::cout << "hello" << std::endl;

    test();
    
    /*
    uint32_t choice = 0;

    while (true)
    {
        wm.m_ShowMenu();
        
        std::cout << "Please input your choice: " << std::endl;
        std::cin >> choice;

        switch (choice)
        {
            case 0:
                wm.m_ExitSystem();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                system("clear");
                break;
        }
    }
    */

    return 0;
}
