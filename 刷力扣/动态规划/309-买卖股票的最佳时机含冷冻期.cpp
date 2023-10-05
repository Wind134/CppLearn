/**
 * 题目：
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 *      卖出股票后，你无法在第二天买入股票 (即冷冻期为1天)。
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 思路：动态规划分三个状态考虑，详情融合进代码了
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

// dp[i][0]为第i天持有股票的最大收益
// dp[i][1]为第i天不持有股票，且不在冷冻期的最大收益
// dp[i][2]为第i天不持有股票，且在冷冻期的最大收益
int maxProfit(vector<int>& prices) {
    int size = prices.size();
    if (size == 0)  return 0;
    // vector<vector<int>> dp_matrix(size, vector<int>(3));
    int maxProfit_1 = -prices[0];
    int maxProfit_2 = 0;
    int maxProfit_3 = 0;
    for(int i = 1; i < size; ++i) {
        // 第i天持有股票，有两种情况考虑，分别是前一天购买的股票和当天购买的股票，当天能购买意味着前一天没卖
        maxProfit_1 = max(maxProfit_1, maxProfit_2 - prices[i]);

        // 第i天不持有股票，且不在冷冻期，意味着今天没有卖出，此种情况下有两种情形
        // 前一天就是该状态，或者前一天可能处于冷冻期
        maxProfit_2 = max(maxProfit_2, maxProfit_3);

        // 第i天不持有股票，且在冷冻期，说明今天卖出了股票，说明前一天必然有股票
        maxProfit_3 = maxProfit_1 + prices[i];
    }

    return max(maxProfit_2, maxProfit_3);
}

int main() {
    input input309;
    auto input_vec = input309.input_vector();
    cout << maxProfit(input_vec) << endl;

    return 0;
}