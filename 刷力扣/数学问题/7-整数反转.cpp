/*
题目：
- 给一个32位的有符号整数x返回将x中的数字部分反转后的结果。 
- 难点在于处理超范围的情况，不能超过32位(假设环境不允许存储64位整数)
- 如果反转后整数超过32位的有符号整数的范围[−2^31, 2^31 − 1]，就返回0。

思路：
- 一是针对字符反转的核心反转策略
- 二是妥善处理超范围的情况
*/
#include <iostream>
#include <climits>
using namespace std;

int reverse(const int& x)
{
    int temp = x;
    int max = INT_MAX;  // (2147483647)
    int min = INT_MIN;  // (-2147483648)
    int result = 0;
    while (temp != 0)
    {
        if (result > max / 10 || (result == max/10 && temp % 10 > 7))   // 超越上限的情况
        {
            return 0;
        }
        if (result < min / 10 || (result == min/10 && temp % 10 < -8))  // 超越下限的情况
        {
            return 0;
        }
        result = result * 10 + temp % 10;   // 翻转的核心处理策略
        temp /= 10;
    }
    return result;
}

int main()
{
    int num;
    cin >> num;
    cout << reverse(num) << endl;
    return 0;
}

