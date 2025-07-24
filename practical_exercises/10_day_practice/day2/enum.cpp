
#include <iostream>
#include <typeinfo>

enum weekday {
    s, 
    m,
    t,
    w,
    thu,
    f,
    sl
};
// enum默认是int类型
int main(int argc, char const *argv[])
{
    enum weekday wek = s;
    for (int i = wek; i != f; i++)
    {
        std::cout << "Loop[" << i << "]" << std::endl;
        std::cout << wek + m << std::endl;
    }
    std::cout << "siezeof(wek): " << sizeof(wek) << std::endl;
    std::cout << "typeid(wek).name(): " << typeid(wek).name() << std::endl;
    std::cout << "typeid(wek).name(): " << typeid(int).name() << std::endl;
    return 0;
}