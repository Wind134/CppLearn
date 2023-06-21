/*
* 一个机器人位于一个m x n网格的左上角

* 机器人每次只能向下或者向右移动一步，机器人试图达到网格的右下角

* 问总共有多少条不同的路径？

* 思路：经典回溯(Der，超时了)

* 更新思路，动态规划：dp[i][j] = dp[i][j-1] + dp[i-1][j](索引从0开始吧)

* dp[i][0] = 1, dp[0][j] = 1
*/
#include <iostream>
using namespace std;

int uniquePaths(int m, int n)
{
    int dp[m][n];

    for(int i = 0; i < n; i++)
    {
        dp[0][i] = 1;   // 第一行全为0
    }
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = 1;   // 第一列全为0
    }

    for (int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }
    
    return dp[m - 1][n - 1];
}

int main()
{
    int input_m, input_n;

    cin >> input_m >> input_n;

    cout << uniquePaths(input_m, input_n) << endl;
}