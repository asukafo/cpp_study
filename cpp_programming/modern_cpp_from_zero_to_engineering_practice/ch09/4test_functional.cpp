// test_functional.cpp
#include <iostream>
#include <string>
#include <functional>
using namespace std;
int TestFunc(string str)
{
    cout << "TestFunc:" << str << endl;
    return 0;
}
class Data
{
public:
    Data() {
        func_ = &Data::Test;
        bfunc_ = bind(&Data::Test, this, std::placeholders::_1);

    }
    void Call()
    {
        func_(*this, "call this");
        bfunc_("bind call this");
    }
    int Test(string str)
    {
        cout << "Data Test " << str << endl;
        return 0;
    }
    void SetFunc(function <int(string)> f)
    {
        bfunc_ = f;
    }

private:
    function<int(Data&, string)> func_;
    function <int(string)>bfunc_;
};
int TestBind(int x, int y, string str, int count)
{
    cout << x << ":" << y << " " << str << " " << count << endl;
    return 0;
}

int main()
{
    using namespace placeholders;
    auto bfun = std::bind(TestBind,100,200,
        std::placeholders::_1,_2
        );
    bfun("test bind 2", 999);
    auto bfun2 = std::bind(TestBind, 100, 200,
        std::placeholders::_1, 888
    );
    bfun2("test bind 2");
    auto bfun3 = std::bind(TestBind, 100, 200,
        _2,_1
    );
    bfun3(777 ,"test bind 3");

    //成员函数转换为普通函数
    Data data;
    auto cfun = std::bind(&Data::Test, &data, _1);
    cfun("bind Data::Test");
    data.Call();
    auto bfun4 = std::bind(TestBind, 100, 200,
        _1, 666
    );
    data.SetFunc(bfun4);
    data.Call();

    data.SetFunc(cfun);
    data.Call();

    return 0;


    function<int(string)> func1 = TestFunc;
    func1("func1");
    function<int(Data&, string)> func2;
    func2 = &Data::Test;
    Data d1;
    func2(d1, "d1 str");
    d1.Call();
}
