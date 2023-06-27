/*
* 给定n个非负整数，用来表示柱状图中各个柱子的高度，每个柱子彼此相邻，且宽度为1。

* 求在该柱状图中，能够勾勒出来的矩形的最大面积。

* 思路：考虑动态规划的方式，假设dp[i]为数组第i个位置所能构成的矩阵的最大面积，显然dp[0] = heights[0];

尝试思考动态规划转移方程：
         dp[i - 1] + height[i - 1];    height[i] >= height[i - 1]
dp[i] = 

当height[i] < height[i - 1]时，从i往前推，直到找到比height[i]还小的那个下标或者(开头)，假设这个位置为j
那么dp[i] = max((i - j) * height[i], dp[j] + (i - j) * height[j])

* 但是上面的做法求的是左边.....

* 因此对dp[i]的思路做一个转换，假设dp[i]为包含数组第i个位置的矩形的最大面积，是否能存在别的思路

* 经过思考，动态规划不适合考虑这道题的场景，因此剩下的办法就是暴力扩散了，寻找以height[i]为高度的最大矩形

* 但是这样的时间复杂度是O(n^2)，解题后会超时，尝试优化思路：

* 这里最后还是参考了题解做法，使用了单调栈以优化时间复杂度，大体来说就是：

* 将以索引index对应的高度heights[index]作为高的矩形的最大面积如果能确定，就计算面积

* 如果不能确定，则将对应下标入栈，直到能确定时出栈；

* 怎么样才能确定呢？如果下一个索引的高度值比当前的高度值要小，则确定
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int size = heights.size();
    heights.push_back(0);   // 给heights添加一个哨兵，使得下面的for循环[i + 1]不需要分类讨论
    int result = 0;         // 储存结果的变量
    stack<int> index_stack; // 定义一个储存下标索引元素的栈
    // 将数组首元素前的索引-1入栈(假想值)，因为不存在比0更小的正整数
    // 因此建模来说，该索引永远无法出栈，干脆就添加进去，以当哨兵之用，这样不需要判断栈空
    index_stack.push(-1);
    for (int i = 0; i < size; i++)
    {
        // 如果下一个元素更小，那么显然可以确定，同时，处理完的元素就当不存在
        if (heights[i + 1] < heights[i])    
        {
            result = max(result, (i - index_stack.top()) * heights[i]);

            // 确定了该元素就完事了吗？并不是，别忘了之前有过元素入栈，如果栈顶的元素也比
            // i + 1位置的要大呢，那么栈顶下标对应的高的宽度也能确定
            while (index_stack.top() == -1 || heights[index_stack.top()] > heights[i + 1])
            {
                if (index_stack.top() == -1)    break;

                else
                {
                    // 保存栈顶元素，之后将其出栈
                    int temp = index_stack.top();

                    // 出栈
                    index_stack.pop();

                    // 宽度刚好为i - index_stack.top()
                    result = max(result, (i - index_stack.top()) * heights[temp]);
                }
            }
        }
        else
        {
            index_stack.push(i);
        }
    }

    return result;
}


int main()
{
    vector<int> input;

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if (cin.get() == '\n')
        {
            cout << "Input Finished!\n";
            break;
        }
    }

    auto result = largestRectangleArea(input);

    cout << result << endl;

    return 0;
}