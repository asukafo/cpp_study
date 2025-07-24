
#include <iostream>

enum gender
{
    e_MALE,
    e_FEMALE
};

struct student
{
    int num;
    char name[20];
    gender g;
};

int main(int argc, char const *argv[])
{
    student s = {10, "asd", e_MALE};
    
    std::cout << s.num << std::endl;
    std::cout << sizeof(s.num) << std::endl;
    std::cout << sizeof(s.name) << std::endl;
    std::cout << sizeof(s.g) << std::endl;
    std::cout << sizeof(s) << std::endl;

    return 0;
}