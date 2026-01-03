#include <iostream>
#include <cstdint>

#include "speaker.h"
#include "speech_manager.h"


int main()
{
    SpeechManager sm;
    std::cout << "hello" << std::endl;
    /*
    for (std::map<uint32_t, Speaker>::iterator it = sm.m_SpeakerMap.begin(); it != sm.m_SpeakerMap.end(); it++)
    {
        std::cout << "Speaker NO: " << it->first 
             << " Name: " << it->second.m_sName
             << " Socre0: " << it->second.m_dScore[0]
             << " Socre1: " << it->second.m_dScore[1] << std::endl;
    }
    */

    uint32_t choice = 0;

    while (true)
    {
        sm.m_ShowMenu();


        std::cout << "Please input your choice: " << std::endl;
        std::cin >> choice;


        switch (choice)
        {
            case 1:
                sm.m_StartSpeech();
                break;
            case 2:
                sm.m_ShowRecord();
                break;
            case 3:
                sm.m_ClearRecord();
                break;
            case 0:
                sm.m_ExitSystem();
                break;
            default:
                system("clear");
                break;
        }
    }

    //pause();
    //system("pause");
    //system("read -n 1 -s -r -p \"Press any key to continue...\"");

    return 0;
}
