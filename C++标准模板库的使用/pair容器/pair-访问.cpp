#include <iostream>
#include <utility>
#include <string>
using namespace std;

int main ()
{
    pair<string, int> p;
    p.first = "haha";       //定义方式1
    p.second = 5;
    cout << p.first << " " << p.second << endl;
    p = make_pair("xixi", 55);      //定义方式2
    cout << p.first << " " << p.second << endl;
    p = pair<string, int>("heihei", 555);   //定义方式3
    cout << p.first << " " << p.second << endl;
    return 0;
    /*
    pair<int, int> p2(5, 15);
    pair<int, int> p3(10, 5);
    */
}