/*
题目：
给你一个整数数组prices ，其中prices[i]表示某支股票第i天的价格；
- 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易；
- 也不能同时参与多笔交易；
- 相比122，就是限制了交易笔数；
- 在这个条件下，要求返回能获得的最大利润。


思路：对比了官解的方法，官解一来优化在时间复杂度，二来只需要一个动态规划数组；
- 官解是这么分析状态的：任意一天结束之后，股票交易只会处于以下五种状态的某一种；
    -- 未进行过任何操作，这个是不需要记录的状态，为0；
    -- 只进行过一次买操作，记录为buy1；
    -- 进行了一次买操作和一次卖操作，即完成了一笔交易，记录为sell1；
    -- 在完成了一笔交易的前提下，进行了第二次买操作，记录为buy2；
    -- 完成了全部的两笔交易，记录为sell2；
- 最后只需要对每一天的这四种状态轮询，就能得到我们要的结果；

- 而这四种状态的求取方式也比较直观：
    -- buy1​ = max{buy1, -prices[i]}    买入嘛，现金自然就为负了；
    -- sell1​ = max{sell1, buy1​ + prices[i]}   当天买入，然后卖出，对上了；
    -- buy2​ = max{buy2, sell1​ - prices[i]}   sell1的利润减去当前股票的价格，也对上了；
    -- sell2​ = max{sell2, buy2​ + prices[i]}   buy2时的利润再加上当前股票的价格，也对上了；

每一轮更新的都是最大值，因此到最后，直接返回sell2即可，假设是sell1最大，sell2也不过是多了一次当天买卖而已，因此返回sell2是一定没问题的；
至于sell2是哪两次交易，这就是动态规划数组无法确定的了；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int size = prices.size();
    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;
    for (int i = 1; i < size; ++i) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }
    return sell2;
}

int main()
{
    input input121;
    auto vec = input121.input_vector();

    cout << maxProfit(vec) << endl;

    return 0;
}