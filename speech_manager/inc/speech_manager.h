#ifndef __SPEECH_MANAGER_H__
#define __SPEECH_MANAGER_H__

#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <fstream>

#include "speaker.h"


class SpeechManager
{
public:
    SpeechManager();

    ~SpeechManager();

    void m_ShowMenu();
    
    void m_ExitSystem();

    void m_InitSpeech();

    void m_CreateSpeaker();

    void m_StartSpeech();

    void m_SpeechDraw();

    void m_SpeechContest();

    void m_ShowScore();

    void m_SaveRecord();

    void m_LoadRecord();

    void m_ShowRecord();

    void m_ClearRecord();
public:
    uint32_t m_uRoundId;

    std::vector<uint32_t> m_uRound1SpeakerVec;
    std::vector<uint32_t> m_uRound2SpeakerVec;
    std::vector<uint32_t> m_uVictoryVec;
    std::map<uint32_t, Speaker> m_SpeakerMap;

    bool m_bFileIsEmpty = false;

    std::map<uint32_t, std::vector<std::string>> m_RecordMap;
};

#endif // __SPEECH_MANAGER_H__
