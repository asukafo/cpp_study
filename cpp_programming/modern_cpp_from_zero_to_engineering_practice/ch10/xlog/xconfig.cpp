#include "xconfig.h"
#include <iostream>
#include <fstream>

const std::string& XConfig::Get(
    const std::string& key)
{
    auto c = conf_.find(key);
    if (c == conf_.end())
        return "";
    return c->second;

    //return conf_[key];
}
bool XConfig::Read
(const std::string& file)
{
    std::ifstream ifs(file);    if (!ifs.is_open())return false;
    std::string line;
    for (;;)
    {
        std::getline(ifs, line);
        std::string k, v;
        if (!line.empty())
        {
            auto p = line.find('=');
            if (p <= 0)continue;
            k = line.substr(0, p);
            v = line.substr(p+1);
            std::cout << "k��" << k 
                << " v:" << v << std::endl;
            conf_[k] = v;
        }
        if (!ifs.good())break;
    }
    return true;
}