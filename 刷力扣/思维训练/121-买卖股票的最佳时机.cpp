/*
题目：
- 给定一个数组prices，它的第i个元素prices[i]表示一支给定股票第i天的价格。
- 你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。
- 设计一个算法来计算你所能获取的最大利润。
- 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回0。

思路：要尽可能保证时间复杂度；
- 目的只是为了选中一个最高价，然后卖出；
- 因此我们从后往前依次遍历，碰到更高的价格就更新这个更高的价格；
- 如果碰到小于等于的情况，就用最高价减去当前价即可，即为利润；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


int maxProfit(const vector<int>& prices) {
        int size = prices.size();

        int result = 0;

        int temp_max = *prices.rbegin();

        // 核心思想就是从后往前推，找到在某个位置买入的最大收益
        for (int i = size - 2; i >= 0; i--)
        {
            if (prices[i] >= temp_max)
            {
                // 更新临时的最大值
                temp_max = prices[i];
            }
            else
            {
                // 更新在这个位置买入所能获取的最大利润
                result = max(result, temp_max - prices[i]);
            }
        }

        return result;
}

int main()
{
    input input121;
    auto vec = input121.input_vector();

    cout << maxProfit(vec) << endl;

    return 0;
}