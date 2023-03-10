#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

/*
string str;   初始化数组
string str = "abcd";
*/

/*
int main()
{
    string str;
    cin >> str;
    cout << str;
    return 0;
}
*/

int main()
{
    string str = "abcd";
    for (string::iterator it = str.begin(); it != str.end(); it++)
        printf("%c", *it);
    return 0;
}