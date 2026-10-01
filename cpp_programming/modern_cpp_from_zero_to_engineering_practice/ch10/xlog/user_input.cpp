#include "user_input.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

static std::vector<std::string>Split(const std::string& s)
{
    std::vector<std::string> vec;
    std::string tmp;
    std::istringstream is(s);
    while (std::getline(is, tmp, ' '))
    {
        if (tmp.empty())continue;
        vec.push_back(tmp);
    }
    return vec;
}
void UserInput::Start(std::function<void(const std::vector<std::string>&)> init)
{
    std::cout << "UserInput::Start()" << std::endl;
    while (!is_exit_)
    {
        std::string input;
        std::cout << "\n>>" << std::flush;
        if (!std::getline(std::cin, input))
            break; // stdin closed (EOF)
        if (input.empty())continue;
        if (input == "exit")break;
        auto vec = Split(input);
        if (vec.empty())continue;
        //for (auto v : vec)cout << v << endl;
        // 
        //cin >> input;
        //cout << input << endl;
        //cv  -s test.mp4 -d test.avi

        std::string type = vec[0];
        if (init)
            init(vec);
        for (int i = 1; i < vec.size(); i++)
        {
            // -s test.mp4 -p -d out.mp4
            auto &k = vec[i];
            auto fitr = key_funcs_.find(k);
            if (fitr != key_funcs_.end())
            {
                if (vec.size()-1 > i)
                {
                    auto &v = vec[i + 1];
                    if (key_funcs_.find(v) == key_funcs_.end())
                    {
                        std::cout << k << ":" << v << std::endl;
                        fitr->second(v);
                        i++;
                        continue;
                    }
                }
                fitr->second("");
                std::cout << k << ":" << " " << std::endl;
                //cout << k << endl;
            }
        }

        // run the task once per input line
        auto task = task_funcs_.find(type);
        if (task == task_funcs_.end())
        {
            std::cout << type << " not support!" << std::endl;
        }
        else
        {
            task->second();
        }

    }


}