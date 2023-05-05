/* N字形输入的字符串，需要从左往右逐行读取输出一个新的字符串 */
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int myAtoi(const string&);

int main()
{
    string s;
    getline(cin, s);
    cout << myAtoi(s) << endl;
}

int myAtoi(const string& s)
{
    if (s.empty()) return 0;
    int index = 0, n = s.size(), sign = 1, res = 0;
    // 处理前置空格
    while (index < n && s[index] == ' ') {
        ++index;
    }
    // 处理符号
    if (index < n && (s[index] == '+' || s[index] == '-'))
        sign = s[index++] == '+' ? 1 : -1;
    // 处理数字
    while (index < n && isdigit(s[index])) 
    {
        int digit = s[index] - '0';
        // 判断是否溢出
        if (res > (pow(2, 31) - 1 - digit) / 10) 
            return sign == 1 ? pow(2, 31) - 1 : -pow(2, 31);
        res = res * 10 + digit;
        ++index;
    }
    return res * sign;
}