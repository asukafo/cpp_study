#ifndef __SPEAKER_H__
#define __SPEAKER_H__

#include <string>

class Speaker
{
public:
    Speaker();
    
    ~Speaker();


    std::string m_sName;
    double m_dScore[2];
};

#endif //__SPEAKER_H__
