/*
题目：
- 请你来实现一个myAtoi(string s)函数，使其能将字符串转换成一个32位有符号整数（类似C/C++中的atoi函数）。

思路：
- 本质上也是一道数学题
*/
#include <iostream>
#include <climits>
#include <string>
using namespace std;

int myAtoi(const string& s)
{
    if (s.empty()) return 0;
    int index = 0, n = s.size(), sign = 1, res = 0;
    // 处理前置空格，空格可能有多个，因此需要循环
    while (index < n && s[index] == ' ') {
        ++index;
    }
    // 处理符号，符号只会有一个，因此if即可
    if (index < n && (s[index] == '+' || s[index] == '-'))
        sign = s[index++] == '+' ? 1 : -1;
    // 处理数字
    while (index < n && isdigit(s[index])) 
    {
        int digit = s[index] - '0';
        // 判断是否溢出
        if (res > (INT_MAX - digit) / 10) 
            return sign == 1 ? INT_MAX : INT_MIN;
        res = res * 10 + digit;
        ++index;
    }
    return res * sign;
}

int main()
{
    string s;
    getline(cin, s);
    cout << myAtoi(s) << endl;
}

