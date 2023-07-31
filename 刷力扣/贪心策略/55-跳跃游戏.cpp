/*
题目：
- 给定一个长度为n的0索引整数数组nums，初始位置为nums[0]。
- 每个元素nums[i]表示从索引i向前跳转的最大长度。
- 换句话说，如果你在nums[i]处，你可以跳转到任意nums[i + j]处:
    -- 0 <= j <= nums[i] 
    -- 0 <= i + j < n
- 是否可以跳到最后一个，如果可以返回true，否则返回false。

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

点评：相比45题更简单
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(const vector<int>& nums)
{
    if(nums.size() == 1)    return true;

    if(nums[0] == 0)    return false;

    int left = 1, right = nums[0];  // 第一个区间的位置

    int farest_dis = 0;
    
    while(right < nums.size() - 1)  // 到倒数第二个位置截止即可
    {
        for(int i = left; i <= right; i++)
        {
            farest_dis = min(max(farest_dis, i + nums[i]), (int)nums.size() - 1);   // 取最远，但不超界
        }
        if (farest_dis == right)    return false;
        left = right + 1;
        right = farest_dis;
    }

    return true;
    
}

int main()
{
    vector<int> input;

    int elem_vector;

    while (cin >> elem_vector)
    {
        input.push_back(elem_vector);
        if(cin.get() == '\n')   break;
    }

    cout << boolalpha << canJump(input) << endl;

    return 0;
}