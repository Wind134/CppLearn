/* 给一个32位的有符号整数x返回将x中的数字部分反转后的结果。 
难点在于处理超范围的情况，不能超过32位
*/
#include <iostream>
#include <cmath>
using namespace std;

int reverse(const int&);

int main()
{
    int num;
    cin >> num;
    cout << reverse(num) << endl;
    return 0;
}

int reverse(const int& x)
{
    int temp = x;
    int max = pow(2, 31) - 1;
    int min = -pow(2, 31);
    int result = 0;
    while (temp != 0)
    {
        if (result > max / 10 || (result == max/10 && temp % 10 > 7))
        {
            return 0;
        }
        if (result < min / 10 || (result == min/10 && temp % 10 < -8))
        {
            return 0;
        }
        result = result * 10 + temp % 10;
        temp /= 10;
    }
    return result;
}