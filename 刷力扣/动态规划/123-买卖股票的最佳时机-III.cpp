/*
题目：
给你一个整数数组prices ，其中prices[i]表示某支股票第i天的价格；
- 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易；
- 也不能同时参与多笔交易；
- 相比122，就是限制了交易笔数；
- 在这个条件下，要求返回能获得的最大利润。


思路：
设定两个动态规划数组：dp_array[2][size]，其中size为prices长度
- dp_array[0][i]负责第i(含)天之前买入股票然后卖出股票能获取的最大收益(只能买卖一次)
- dp_array[1][j]负责第j(含)天之后买入股票再卖出股票能获取的最大收益(只能买卖一次)
- 如果i与j相等，表明i天之前的股票在i天卖出，j天买入的股票在后面卖出的最大利润；
- 这个时候就已经完成了两笔交易，直接返回结果；

-- 这就限定了dp_array[0][i]需要从前往后求取
-- dp_array[1][j]需要从后往前求取

- 综合这两个数组，假设股价数组[1 4 1 4 3 1]，那么可以分别得到：
    -- dp_array[0]：[0 3 0 3 2 0]
    -- dp_array[1]：[3 0 3 0 0 0]
- 由于要求交易两次，我们要基于上个数组起始点遍历下个数组，对于上个数组，搜寻起始点之前的最大利润，对于下个数组，搜寻起始点之后的最大利润
- 叠两层for循环复杂度为n^2，会超时
- 因此我们需要想要聪明的办法，这个办法就是二分
- 通过二分锁定两笔交易的具体时机；

最后通过这两个数组求出最大收益(这个过程是否可以优化)
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;


int getValue(const vector<int>& v1, const vector<int>& v2, int i,int j, const vector<vector<int>>& dp_matrix)
{
    if (i > j) return 0;
    int mid = (i + j) / 2;
    int temp_i = i, temp_j = j;
    int left_profit = 0, right_profit = 0;  // 记住，都必须初始化
    while (temp_i <= temp_j)
    {
        left_profit = max(left_profit, v1[temp_i]);
        right_profit = max(right_profit, v2[temp_j]);
        temp_i++;
        temp_j--;
    }
    int result = left_profit + right_profit;
    if (i == j) return result;
    int left_result = getValue(v1, v2, i, mid, dp_matrix);

    result = max(result, left_result);
    int right_result = getValue(v1, v2, mid + 1, j, dp_matrix);
    result = max(result, right_result);
    return result;
}
int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int left_min = prices[0], right_max = prices[size - 1];
    vector<vector<int>> dp_matrix(2, vector<int>(size));
    
    for (int i = 0, j = size - 1; i < size && j >= 0; i++, j--)
    {   
        // 求dp_matrix[0]，第i(含)天之前买入能获取的最大收益
        if (prices[i] < left_min) {
            left_min = prices[i];
            dp_matrix[0][i] = 0;
        }
        else    dp_matrix[0][i] = prices[i] - left_min;

        // 求dp_matrix[j]，第i(含)天之后卖出能获取的最大收益
        if (prices[j] > right_max) {
            right_max = prices[j];
            dp_matrix[1][j] = 0;
        }
        else    dp_matrix[1][j] = right_max - prices[j];
    }

    // int profit = 0;

    // for(int i=1;i < size; i++) {
    //         profit = max(dp_matrix[0][i-1]+dp_matrix[1][i], profit);
    //     }

    // 我们不出意外应该获取到了两个动态规划数组，接下来的问题是
    // 怎么样尽可能的减少获取最大利润的时间复杂度
    // dp_matrix[1]的值必须在dp_matrix[0]的后面取得
    // 这里尝试利用二分法
    
    // return max(profit, dp_matrix[0][size - 1]);

    return getValue(dp_matrix[0], dp_matrix[1], 0, size - 1, dp_matrix);
}

int main()
{
    input input121;
    auto vec = input121.input_vector();

    cout << maxProfit(vec) << endl;

    return 0;
}