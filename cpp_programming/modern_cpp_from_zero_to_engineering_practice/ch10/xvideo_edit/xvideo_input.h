#ifndef _XVIDEO_INPUT_H_
#define _XVIDEO_INPUT_H_
#include <memory>
#include "xtask.h"

class XVideoInput
{
public:
    void Start(std::unique_ptr<XTask> task);
private:
    void RunTask(XTask& task, const XTask::Data& data);
};

#endif // _XVIDEO_INPUT_H_