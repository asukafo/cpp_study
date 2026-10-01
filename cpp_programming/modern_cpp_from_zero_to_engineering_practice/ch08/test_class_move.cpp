/**
 * @file    test_class_move.cpp
 * @brief  
 * @author  asukaf
 * @date    2026-09-30
 *
 */

#include <iostream>
#include <vector>
#include <string>

class Data
{
public:
    Data() {std::cout << "Create Data" << std::endl;}
    Data(const Data&d) {std::cout << "Copy Data" << std::endl;}
    ~Data() {std::cout << "Drop Data" << std::endl;}
};

void TestData (std::vector<Data> d)
{
    std::cout << "In TestData " << d.size() << std::endl;
}

class String
{
public:
    void Clear()
    {
        delete str_;
        str_  = nullptr; 
        size_ = 0;
    }

    ~String()
    {
        std::cout << "Drop String, size: " << size_ << std::endl;
        Clear();  
    }

    String(const char* str)
    {
        std::cout << "Create String: " << str << std::endl;
        size_ = strlen(str);
        str_  = new char[size_ + 1]; // 1 for \0
        memcpy(str_, str, size_+1);
    }
    
    // Copy Constructor
    String(const String& s)
    {
        std::cout << "Copy String:" << s.str_ << std::endl;
        size_ = s.size_;
        str_  = new char[size_+1];
        memcpy(str_, s.str_, size_+1);
    }

    // Move Constructor
    String(String&& str)
    {
        std::cout << "Move String" << std::endl;
        str_ = str.str_;
        size_ = str.size_;
        str.str_ = nullptr;
        str.size_ = 0;
    }

    const char* c_str()
    {
        if (!str_) return "";
        return str_;
    }

private:
    char* str_ {nullptr};
    int size_ {0};
};

int main()
{
    std::vector<Data> datas (3);
    TestData(std::move(datas));
    std::cout << datas.size() << std::endl;
}