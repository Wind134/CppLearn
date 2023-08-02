/*
题目：求平方根；

思路：
- 题目只需要返回整数，因此常规二分即可，要考虑溢出的可能；
- 还可以考虑牛顿迭代法；
*/
#include <iostream>
using namespace std;

int mySqrt(int x)
{
    int left = 0;
    int right = x;
    long long mid = (left + right) / 2;

    int result;
    while (true)
    {
        if(mid * mid <= x && (mid + 1) * (mid + 1) > x)
        {
            result = mid;
            break;
        }
        else if(mid * mid > x)
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        else
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
    }
    return result;
}

int main()
{
    int input;
    cin >> input;
    cout << mySqrt(input) << endl;
    return 0;
}