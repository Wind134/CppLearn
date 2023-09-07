/**
 * 题目：
 * 给你一个整数数组coins，表示不同面额的硬币；以及一个整数amount，表示总金额。
 * 计算并返回可以凑成总金额所需的最少的硬币个数。
 * 如果没有任何一种硬币组合能组成总金额，返回-1。
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 
 * 思路：完全背包问题的转换
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

/**
 * @brief 滚动优化空间的版本
 */
int coinChange(vector<int>& coins, int amount) {
    int size = coins.size();
    if (!amount)    return 0;
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = 1; j <= amount; ++j) {
            if (coins[i] <= j)  dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    input input322;
    auto input_vec = input322.input_vector();

    int amount;
    cin >> amount;

    cout << coinChange(input_vec, amount) << endl;

    return 0;
}