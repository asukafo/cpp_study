/*union.cpp*/
#include <iostream>
using namespace std;

union myun
{
    struct {
        int x;
        int y;
        int z;
    } u;
    int k;
} a;

int main(int argc, char const *argv[])
{
    a.u.x = 4;
    a.u.y = 5;
    a.u.z = 6;
    a.k = 0; //覆盖掉第一个int空间值
    printf("%d %d %d %d\n", a.u.x, a.u.y, a.u.z, a.k);
    printf("%ld\n", sizeof(a));

    return 0;
}


/*
* output: 
   0 5 6 0
   12
* 说明union的空间是共享的，a.u.x, a.u.y, a.u.z和a.k都占用同一块内存空间。
* 当我们给a.k赋值时，它覆盖了a.u.x的值，因此输出的a.u.x为0。
* 这表明在union中，所有成员共享同一块内存空间。
* union的大小是最大的成员的大小，这里是int的大小。
*/