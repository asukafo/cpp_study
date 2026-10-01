// test_function_ptr.cpp 
#include <iostream>
#include <string>
using namespace std;
int TestFuncPtr(string str)
{
    cout << "call TestFuncPtr " << str << endl;
    return 0;
}
//函数指针声明
using FuncType = int(*)(string);



class MyClass
{
public:
    using Func = int(MyClass::*)(string);
    MyClass()
    {
        func_ = &MyClass::Test;
    }
    void Call() {
        (this->*func_)("para Call");
    }
    int Test(string str)
    {
        cout << "MyClass::Test(" << str << ")" << endl;
        return 0;
    }
private:
    Func func_{ nullptr };

};
//声明成员函数指针类型
using CFun = int(MyClass::*)(string);
int main()
{
    TestFuncPtr("para1");
    auto FunPtr = TestFuncPtr;
    FunPtr("para2");
    //定义函数指针遍历
    int (*fun_ptr)(string);
    fun_ptr = TestFuncPtr;
    fun_ptr("para3");
    FuncType fptr1 = TestFuncPtr;
    fptr1("para4");
    //成员函数取地址要加&
    auto cfun = &MyClass::Test;
    MyClass mc;
    (mc.*cfun)("para auto cfun");


    CFun cfun2 = &MyClass::Test;
    (mc.*cfun2)("para using");
    mc.Call();



}
