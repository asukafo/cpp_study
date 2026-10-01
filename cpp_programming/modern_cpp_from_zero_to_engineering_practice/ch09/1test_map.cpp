// test_map.cpp 
#include <iostream>
#include <map>
#include<string>
using namespace std;
int main()
{
    //创建map 初始化值
    map<int, string> mis {
        {1,"value1"},{4,"value4"},{5,"value5"} };
    map<string, string> mss
    { {"key1","val1"},{"key2","val2"}, {"key3","val3"},};
    for (auto& v : mis) //遍历访问
        cout << v.first << ":" << v.second << endl;
    for (auto& v : mss)
        cout << v.first << ":" << v.second << endl;


    //插入数据
    mis[100] = "100value";
    // 1 查找插入key4 设置值
    mss["key4"] = "value4";
    mss.insert(make_pair("key6","val6"));
    //查找访问
    cout << "mss[\"key4\"] = " << mss["key4"] << endl;
    cout << mss.size() << endl;
    cout << "mss[\"key5\"] = " << mss["key5"] << endl;
    cout << mss.size() << endl;
    auto itr = mss.find("key6");
    if (itr == mss.end())
    {
        cout << "find failed!" << endl;
    }
    else
    {
        cout << itr->first << ":" << itr->second << endl;
    }
    //迭代器遍历
    for (auto v = mss.begin(); v != mss.end(); v++)
    {
        cout << v->first << ":" << v->second << endl;
        v->second += " itr ";
    }
    for (auto& v : mss)
    {
        v.second += " for ";
        cout << v.first << ":" << v.second << endl;
    }
    for (auto& v : mss)
    {
        cout << v.first << ":" << v.second << endl;
    }
    mss["key5"];
    mss.erase("key5");
    for (auto& v : mss)
        cout << v.first <<" ";
    cout << endl;

    auto v1 = mss.find("key1");
    mss.erase(v1);
    for (auto& v : mss)
        cout << v.first << " ";
    cout << endl;
    mss.clear();
}
