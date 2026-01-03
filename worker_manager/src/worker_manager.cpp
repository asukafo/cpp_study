#include "worker_manager.h"

void pause() {
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

WorkerManager::WorkerManager()
{
}

WorkerManager::~WorkerManager()
{
}

void WorkerManager::m_ShowMenu()
{
    std::cout << "**************************************************" << std::endl;
    std::cout << "**** Welcome to use Worker Manager! **************" << std::endl;
    std::cout << "***    0: Quit Worker Manager     ****************" << std::endl;
    std::cout << "***    1: Add Worker Info         ****************" << std::endl;
    std::cout << "***    2: Show Worker Info        ****************" << std::endl;
    std::cout << "***    3: Delete Last Day Worker  ****************" << std::endl;
    std::cout << "***    4: Edit Worker Info        ****************" << std::endl;
    std::cout << "***    5: Find Worker Info        ****************" << std::endl;
    std::cout << "***    6: Sort on Number          ****************" << std::endl;
    std::cout << "***    7: Clear all documents     ****************" << std::endl;
    std::cout << "**************************************************" << std::endl;
    std::cout << std::endl;
}

void WorkerManager::m_ExitSystem()
{
    std::cout << "Welcome to use next time !" << std::endl;
    pause();
    exit(0);
}
