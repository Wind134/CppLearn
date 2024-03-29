/*
题目：
- 手动实现一个pow算法，主要原理是利用快速乘机制实现

思路：
- 本质上就是递归
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int MinV = INT_MIN;

double myPow(double x, int n)
{
    if (n == MinV)  // 这里是唯一需要特殊处理的部分
    {
        return 1 / myPow(x, - (n + 1)) * x;
    }
    if (n < 0)  return 1 / myPow(x, -n);
    if (n == 0) return 1.0;
    double y = myPow(x, n / 2); // 这里需要用一个y代替，不然时间复杂度喜人
    return n % 2 == 0 ? y * y : x * y * y;
}

int main()
{
    double a;
    int b;
    cin >> a >> b;
    cout << myPow(a, b) << endl;
}