/*
题目：
- 给你两个二进制字符串a和b，以二进制字符串的形式返回它们的和。
-注意：二进制的本质就是满2进位

思路：
- 代码不够优雅，要优雅；
- 下面这个写法已经很不错了，但同时还是可以考虑位运算；
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b)
{
    int len1 = a.length();
    int len2 = b.length();

    int long_str = (len1 >= len2) ? len1 : len2;    // 两个字符串的较长者
    int short_str = (len1 < len2) ? len1 : len2;    // 两个字符串的较短者
    
    string result(long_str, '0');   // 结果初始值

    bool tag = false;   // 代表要进位，初始值默认不进位

    for (int i = 1; i <= short_str; i++)
    {
        int num1 = *(a.end() - i) - '0';
        int num2 = *(b.end() - i) - '0';

        int value = num1 + num2 + tag;
        if (value >= 2)   // 如果相加和为3，则下一位要进位
        {
            *(result.end() - i) = '0' + value - 2;
            tag = true;
        }
        else 
        {
            *(result.end() - i) = '0' + value;  // 更新tag，不必进位
            tag = false;
        }
    }

    // 上面的循环就将较短的那一边遍历完成了，接下来处理剩下的那部分

    for (int i = long_str - short_str - 1; i >= 0; i--)
    {
        int num = (len1 >= len2) ? (a[i] - '0') : (b[i] - '0');
        int add_value = num + tag;
        if (add_value >= 2)
        {
            result[i] = '0' + add_value - 2;
            tag = true;
        }
        else
        {
            result[i] = '0' + add_value;
            tag = false; 
        }
    }
    if (tag == true)    result.insert(result.begin(), '1');
    return result;
}

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    cout << addBinary(s1, s2) << endl;
}