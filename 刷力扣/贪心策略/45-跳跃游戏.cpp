/*
题目：
- 给定一个长度为n的0索引整数数组nums，初始位置为nums[0]。
- 每个元素nums[i]表示从索引i向前跳转的最大长度。
- 换句话说，如果你在nums[i]处，你可以跳转到任意nums[i + j]处:
    -- 0 <= j <= nums[i] 
    -- 0 <= i + j < n
- 要求返回到达nums[n - 1]的最小跳跃次数。

思路：起初思路是采用回溯递归，但该方法会超时，递归层数太多(想想能否存在优化空间)；
- 思考一下我们的目的：我们要的是从第一个跳到最后的最小的次数；
- 针对起始位置nums[i]，在num[i]~nums[nums[i] + 1]的位置都能一步到，那就是说
- 可以尝试采用贪心策略，尽可能尝试跳到最远距离(尽可能覆盖最远的边界)，每次跳跃的
- 起点都是一个范围，这个范围的右边界能大于等于nums.size() - 1便达到了我们最终的结果：
- 2 3 1 1 4 3 5 2 1 3 1 7为例：
- 起跳的第一个范围是2自己，接下来如果要跳：
- 第一个范围是3 1
- 第二个范围是1 4
- 第三个范围是3 5 2 1
- 第四个范围是3 1 7
也就是说，最终我们需要的，就是这个范围的个数
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int jump(const vector<int>& nums) {
    // [startPoint, endPoint]组成了一个范围
    if (nums.size() == 1)   return 0;
    if (nums[0] == nums.size() - 1) return 1;   // 起始位置都直接覆盖到了n - 1的位置，那只需要跳一下
    
    // 第一个范围是nums[0]本身
    int startPoint = 1;         // 起始点的初始左边界索引
    int endPoint = nums[0];     // 起始点的初始右边界索引        
    int farest_pos = 1 + nums[1];   // 能跳动的距离初始值，取基于左边界索引跳的值
    int step = 1;   // 步数，也就是我们要返回的结果   
    
    // 虽然有两层循环，但时间复杂度就是O(n)
    while(endPoint < nums.size() - 1)
    {   
        for (int i = startPoint; i <= endPoint; i++)    // 边界范围内寻找能跳到的最远距离
        {
            farest_pos = min((int)nums.size() - 1, max(farest_pos, nums[i] + i));
            // 如果最远距离能到nums.size() - 1，接下来都不用算了，直接返回
            if(farest_pos == nums.size() - 1)   return ++step;
        }

        // 确认了最远距离之后，更新范围
        startPoint = endPoint + 1;
        endPoint = farest_pos;
        step++;   
    }
    return step;
}

int main() {
    input input45;

    auto vec = input45.input_vector();
    cout << jump(vec) << endl;
    return 0;
}