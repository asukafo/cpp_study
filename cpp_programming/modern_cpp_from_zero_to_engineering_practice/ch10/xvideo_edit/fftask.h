#ifndef _FFTASK_H_
#define _FFTASK_H_

#include "xtask.h"
#include "xexec.h"

class FFTask :public XTask
{
public:
    bool Start(const Data& para)  override;
    int Progress() override { return progress_; }
    int TotalSec()override { return total_sec_; };
    bool Runing() override { return exec_.Runing(); };
    virtual void Clear() 
    {
        total_sec_ = 0;
        progress_ = 0;
     
    }
private:
    int total_sec_{ 0 };
    int progress_{ 0 };
    XExec exec_;

};

#endif //_FFTASk_H_