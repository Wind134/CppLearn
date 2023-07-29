/*
题目：
- 给定n个非负整数表示每个宽度为1的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
- [0 1 0 2 1 0 1 3 2 1 2 1]：给定了12个柱子，其中每根柱子的高度就是其中元素值

做法：这个做法采用动态规划的思想，针对每个索引index，该索引的位置所能接的水量：
- 等于该索引左边的最大值leftMax[index]与该索引右边最大值rightMax[index]的较小者减去该索引本身的高度height[index]
- 我们需要维护这两个数组，因此我们想办法求得这两个数组，这两个数组有两个特殊的位置leftMax[0]以及rightMax[N-1]，为了统一
- 处理，我们将索引本身融入索引左边的位置，同时也将索引本身融入索引右边的位置，那么我们就能得到leftMax[0] = height[0]以及
- rightMax[N - 1] = height[N - 1]，而在1～N-1的位置，对于leftMax而言，leftMax[i] = max(leftMax[i - 1], height[i])
- 对于rightMax而言，rightMax[i] = max(rightMax[i + 1], height[i])
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int trap(const vector<int>& height)
{
    int size = height.size();
    int leftMax[size], rightMax[size];  // 维护两个指针
    leftMax[0] = height[0];
    rightMax[size - 1] = height[size - 1];
    for (int i = 1; i < size; i++)
    {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    for (int i = size - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }
    
    int result = 0;

    for (int i = 0; i < size; i++)
    {
        result += min(leftMax[i], rightMax[i]) - height[i];    
    }
    return result;
}

int main()
{
    input input42;

    auto vec = input42.input_vector();
    
    cout << trap(vec) << endl;
}    