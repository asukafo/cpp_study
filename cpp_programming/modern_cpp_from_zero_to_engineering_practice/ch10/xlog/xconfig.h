#ifndef _XCONFIG_H_
#define _XCONFIG_H_

#include <string>
#include <map>

/*
* 
log.conf

log_type=console
log_file=log.txt
log_level=debug

conf_["log_type"]
conf_["log_file"]
*/
class XConfig
{
public:
    bool Read(const std::string& file);

    const std::string& Get(
        const std::string& key);
private:
    std::map<std::string, 
        std::string>conf_;

};

#endif //_XCONFIG_H_