#ifndef _XDIR_H_
#define _XDIR_H_

#include <string>
#include <vector>

class XDir
{
public:
    struct File
    {
        std::string name; // file name
        std::string path; // full path
    };

    static bool IsDir(const std::string& path);
    static void Create(const std::string& path);

    std::vector<File> GetFiles(const std::string& dir);
};

#endif //_XDIR_H_
