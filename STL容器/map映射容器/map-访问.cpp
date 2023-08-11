#include <map>
#include <iostream>
using namespace std;


//单独定义一个map
//map<typename1, typename2> mp;     //有点类似字典类型，所以需要填写两个类型

//字符串到整型的映射，必须使用string而不能是char数组
//map <string, int> mp;

int main()
{
    map<char, int> mp;
    mp['m'] = 20;
    mp['r'] = 30;
    mp['a'] = 40;
    /*
    map<char, int>::iterator it = mp.find('r');     //find函数返回迭代器
    mp.erase(it);   //迭代器删除
    */
    //mp.erase('r');  //通过key值删除
    map<char, int>::iterator it1 = mp.find('m');
    mp.erase(it1, mp.end());
    for (map<char, int>::iterator it = mp.begin(); it !=  mp.end(); it++)
    {
        cout << it ->first << " " << it->second << endl;
    }
    return 0;   
}