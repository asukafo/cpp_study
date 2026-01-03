#include "speech_manager.h"

void pause() {
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

SpeechManager::SpeechManager()
{
    m_InitSpeech();

    m_CreateSpeaker();

    m_LoadRecord();
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::m_ShowMenu()
{
    std::cout << "*************************************" << std::endl;
    std::cout << "***Welcome Join Speech! *************" << std::endl;
    std::cout << "*** 1: begin speech     *************" << std::endl;
    std::cout << "*** 2: Query Prvious Speech Track ***" << std::endl;
    std::cout << "*** 3: Clear Speech Track ***********" << std::endl;
    std::cout << "*** 0: Quit Speech ******************" << std::endl;
    std::cout << "*************************************" << std::endl;
    std::cout << std::endl;
}

void SpeechManager::m_ExitSystem()
{
    std::cout << "Welcome to use next time !" << std::endl;
    pause();
    exit(0);
}

void SpeechManager::m_InitSpeech()
{
    m_uRound1SpeakerVec.clear();
    m_uRound2SpeakerVec.clear();
    m_uVictoryVec.clear();
    m_SpeakerMap.clear();
    
    m_uRoundId = 1;

    m_RecordMap.clear();
}

void SpeechManager::m_CreateSpeaker()
{

    std::string sNameSeed = "ABCDEFGHIJKL";
    //std::cout << sNameSeed.size() << std::endl;
    
    for (uint32_t i = 0; i < sNameSeed.size(); ++i)
    {
        std::string sName = "Competitor_";
        sName += sNameSeed[i];

        Speaker sp;
        sp.m_sName = sName;
        for (uint32_t j = 0; j < 2; j++)
        {
            sp.m_dScore[j] = 0;
        }

        m_uRound1SpeakerVec.push_back(i + 10001);

        m_SpeakerMap.insert(std::make_pair(i + 10001, sp));
    }
}

void SpeechManager::m_StartSpeech()
{
    // Round 1
    // 1: Draw
    m_SpeechDraw();

    // 2: Competition
    m_SpeechContest();
    
    // 3: Display Result
    m_ShowScore();

    // Round 2
    m_uRoundId++;

    // 1: Draw 
    m_SpeechDraw();

    // 2: Competition
    m_SpeechContest();

    // 3: Display Final Result 
    m_ShowScore();

    // 4: Save Score
    m_SaveRecord();

    m_InitSpeech();
    m_CreateSpeaker();
    m_LoadRecord();

    std::cout << "Complete Current Period Competition!" << std::endl;

    pause();
    system("clear");
}

void SpeechManager::m_SpeechDraw()
{
    std::cout << "Round " << m_uRoundId << "Draw" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Draw Speech Sequence: " << std::endl;
    
    std::random_device rd;
    std::default_random_engine rng(rd());

    std::vector<uint32_t>& vec = (m_uRoundId == 1) ? m_uRound1SpeakerVec : m_uRound2SpeakerVec;

    std::shuffle(vec.begin(), vec.end(), rng); 

    for (std::vector<uint32_t>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl; 

    std::cout << "--------------------------------------" << std::endl;

    pause();
    std::cout << std::endl;
}

void SpeechManager::m_SpeechContest()
{
    std::cout << "---------------" << "Begin Round " << m_uRoundId << "---------------" << std::endl;
    
    std::multimap<double, uint32_t, std::greater<double>> GroupScore;

    uint32_t num = 0;

    std::vector<uint32_t>& src_vec = (m_uRoundId == 1) ? m_uRound1SpeakerVec : m_uRound2SpeakerVec;
    
    std::mt19937 engine(time(nullptr));
    std::uniform_int_distribution<int> dist(600, 1000);

    for (std::vector<uint32_t>::iterator it = src_vec.begin(); it != src_vec.end(); it++)
    {
        num++;

        std::deque<double> score_deque;
        for (uint32_t i=0; i<10; ++i)
        {
            double dScore = dist(engine);
            score_deque.push_back(dScore);
        }

        std::sort(score_deque.begin(), score_deque.end(), std::greater<double>());
        score_deque.pop_front();
        score_deque.pop_back();

        double dSum = accumulate(score_deque.begin(), score_deque.end(), 0.0f);
        double dSvg = dSum / (double)score_deque.size();

        m_SpeakerMap[*it].m_dScore[m_uRoundId - 1] = dSvg;

        GroupScore.insert(std::make_pair(dSvg, *it));
        if (num % 6 == 0)
        {
            std::cout << num/6 << "step" << std::endl;
            for (std::multimap<double, uint32_t, std::greater<double>>::iterator it = GroupScore.begin(); it!= GroupScore.end(); ++it)
            {
                std::cout << "No: " << it->second 
                          << " Name: " << m_SpeakerMap[it->second].m_sName 
                          << " Score: " << m_SpeakerMap[it->second].m_dScore[m_uRoundId-1] 
                          << std::endl;
            }

            uint32_t uCount = 0;
            for (std::multimap<double, uint32_t, std::greater<double>>::iterator it = GroupScore.begin(); it != GroupScore.end() && uCount < 3; ++it, ++uCount)
            {
                if (m_uRoundId == 1)
                {
                    m_uRound2SpeakerVec.push_back((*it).second);
                }
                else 
                {
                    m_uVictoryVec.push_back((*it).second);
                }
            }

            GroupScore.clear();

            std::cout << std::endl;
        }
    }


    std::cout << "---------------" << "Complete Round " << m_uRoundId << "---------------" << std::endl;

    pause();
}

void SpeechManager::m_ShowScore()
{
    std::cout << "-----------------" << "Round " << m_uRoundId << "Qualified Speaker Info: ----------------" << std::endl;

    std::vector<uint32_t>& ref_vec = (m_uRoundId == 1) ? m_uRound2SpeakerVec : m_uVictoryVec;

    for (const auto& it : ref_vec)
    {
        std::cout << "No: " << it
                  << " Name: " << m_SpeakerMap[it].m_sName 
                  << " Score: " << m_SpeakerMap[it].m_dScore[m_uRoundId - 1] 
                  << std::endl;
    }
    std::cout << std::endl;
    
    pause();
    system("clear");
}

void SpeechManager::m_SaveRecord()
{
    // output stream object, write file
    std::ofstream ofs;
    ofs.open("speech.csv", std::ios::out | std::ios::app);
    // ios::app : append mode

    for (const auto& it : m_uVictoryVec)
    {
        ofs << it << ","
            << m_SpeakerMap[it].m_dScore[1] << ",";
    }
    ofs << std::endl;

    ofs.close();

    std::cout << "Record has been saved!" << std::endl;

    m_bFileIsEmpty = false;
}

void SpeechManager::m_LoadRecord()
{
    // input stream object, read file
    std::ifstream ifs("speech.csv", std::ios::in);

    if (!ifs.is_open())
    {
        m_bFileIsEmpty = true;
        std::cout << "File is not exist!" << std::endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        std::cout << "File is empty!" << std::endl;
        m_bFileIsEmpty = true; 
        ifs.close();
        return;
    }

    m_bFileIsEmpty = false;

    ifs.putback(ch);

    std::string data;
    uint32_t index = 0;
    while (ifs >> data)
    {
        std::vector<std::string> vec;

        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                break;
            }
            std::string tmp = data.substr(start, pos-start);
            vec.push_back(tmp);
            start = pos + 1;
        }

        m_RecordMap.insert(std::make_pair(index, vec));
        index++;
    }

    ifs.close();
}

void SpeechManager::m_ShowRecord()
{
    if (m_bFileIsEmpty)
    {
        std::cout << "File is Not Exist or is empty!" << std::endl;
    }
    else 
    {
        for (uint32_t i=0; i < m_RecordMap.size(); ++i)
        {
            std::cout << "[Period " << i+1 << " ]: "
                      << "Champion No:"    << m_RecordMap[i][0] << ", Score:" << m_RecordMap[i][1] << ", "
                      << "Runner-up No:"   << m_RecordMap[i][2] << ", Score:" << m_RecordMap[i][3] << ", " 
                      << "Third-place No:" << m_RecordMap[i][4] << ", Score:" << m_RecordMap[i][5] << ", "
                      << std::endl;
        }
    }

    pause();
    system("clear");
}

void SpeechManager::m_ClearRecord()
{
    std::cout << "Confirm to clear? " << std::endl;
    std::cout << "1: Yes" << std::endl;
    std::cout << "0: No" << std::endl;

    uint32_t sel = 0;
    std::cin >> sel;

    if (1 == sel)
    {
        // Open Mode, ios::trunc if exist, delete file and re-create
        std::ofstream ofs("speech.csv", std::ios::trunc);
        ofs.close();

        m_InitSpeech();

        m_CreateSpeaker();

        m_LoadRecord();

        std::cout << "Clear Success!" << std::endl;
    }

    pause();
    system("clear");
}
