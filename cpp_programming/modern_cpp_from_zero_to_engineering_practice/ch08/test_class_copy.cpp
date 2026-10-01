/**
 * @file    test_class_copy.cpp
 * @brief   Tests for class copy control semantics: copy ctor, copy assignment, move ctor, move assignment
 * @author  asukaf
 * @date    2026-09-30
 *
 */

#include <iostream>

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

    const char* c_str()
    {
        if (!str_) return "";
        return str_;
    }

private:
    char* str_ {nullptr};
    int size_ {0};
};

void TestString(String s)
{
    std::cout << "TestString: " << s.c_str() << std::endl;
}

void TestStringRef(String& s)
{
    std::cout << "TestStringRef: " << s.c_str() << std::endl;
}

class MyString
{
public:
    MyString(String& str): str_(str)
    {}
private:
    String str_;
};

int main()
{
    String str1("Test my string str1");
    TestString(str1);
    String str2 = str1;
    std::cout << "----------- TestString Ref-------------" << std::endl;
    TestStringRef(str1);
    std::cout << "---------------------------------------" << std::endl;
    String str3("Test my string str3");
    MyString mystr(str3);
}