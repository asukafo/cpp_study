#ifndef _XTASK_H_
#define _XTASK_H_

#include <string>

class XTask
{
public:
    struct Data
    {
        std::string type;
        std::string src;
        std::string des;
        std::string password;
        bool is_enc{ true };
        int begin_sec{ 0 };
        int end_sec{ 0 };
    };

    virtual bool Start(const Data&para) = 0;

    virtual int Progress() = 0;

    virtual bool Runing() = 0;

    virtual int TotalSec() = 0;

    virtual void Clear() = 0;
};
#endif // _XTASK_H_