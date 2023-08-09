/*
题目：
- 给你一个整数数组prices ，其中prices[i]表示 某支股票 第i天的价格。
- 在每一天，你可以决定是否购买和/或出售股票。你在任何时候最多只能持有一股股票。你也可以先购买，然后在同一天出售。
- 返回你能获得的最大利润。
- 当天可以买卖，只要满足持有一股股票即可。

思路：
- 如果下一天的价格高于这一天，我就卖出，这跟实际的股票还是不太一样的；
- 如果下一天价格更低呢？更低肯定不能卖，直到遇到价格更高的
- 遇到价格更高的，卖出，然后要再买入，是的，要再买入(不考虑股票交易手续费那些)
- 买入之后同样依据上述策略即可
直接使用贪心算法即可，设置初始利润为0
- 如果下一天价格高于这一天，那么就算利润
- 直到最后一天，思路简单明了

*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit = 0;

        for (int i = 0; i < size - 1; i++)
        {
            if (prices[i + 1] > prices[i])  profit += (prices[i + 1] - prices[i]);
        }        
        
        return profit;
    }

int main()
{
    input input121;
    auto vec = input121.input_vector();

    cout << maxProfit(vec) << endl;

    return 0;
}