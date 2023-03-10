#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map <string, int> mp;
    mp.insert(make_pair("heihei", 5));      //作为map的键值插入
    mp.insert(pair<string, int>("haha", 10));   // 这一步代替的二元结构体及其构造函数？
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}