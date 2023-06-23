/*
* 假设你正在爬楼梯，需要n阶你才能到达楼顶。
* 每次你可以爬1或2个台阶。
* 你有多少种不同的方法可以爬到楼顶呢？

* 当台阶数大于等于3时：dp[i] = dp[i - 2] + dp[i - 1];

dp[1] = 1;
dp[2] = 2;
*/
#include <iostream>
using namespace std;

int climbStairs(int n)
{
    if (n == 2) return 2;
    if (n == 1) return 1;

    int dp[n];
    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
}

int main()
{
    int input;
    cin >> input;
    cout << climbStairs(input) << endl;
    return 0;
}