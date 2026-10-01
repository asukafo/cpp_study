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
        func_= &Data::Test;
    }
    void Call()
    {
        func_(*this, "call this");
    }
    int Test(string str)
    {
        cout << "Data Test " << str << endl;
        return 0;
    }


private:
    function<int(Data&, string)> func_;
};


int main()
{

    function<int(string)> func1 = TestFunc;
    func1("func1");
    function<int(Data&, string)> func2;
    func2 = &Data::Test;
    Data d1;
    func2(d1, "d1 str");
    d1.Call();

}
