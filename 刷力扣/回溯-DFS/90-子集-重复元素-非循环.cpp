/*
题目：
- 给你一个整数数组nums，其中可能包含重复元素，请你返回该数组所有可能的子集(幂集)

思路：思路就是一个很明显的回溯，每个数都面临两种情况，选或者不选
- 首先还是需要排序，将所有相同的元素靠近在一起；
- 如果处理重复的问题：
    -- 以a a a b b c集合为例
    -- 包含第一个a的子集，与包含第二个a的子集，后者的所有内容一定都在前者范围内
    -- 对于index位置的元素而言，如果前一个元素并未添加进去，同时该位置的元素与前一个相等
    -- 那么包含该index的所有子集一定会出现在包含前一个元素的所有子集中，那就没必要继续求了
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> result_set;
vector<int> vec_of_result;


void backtrace(bool process, int index, const vector<int>& nums)
{
    if (index == nums.size())
    {
        result_set.push_back(vec_of_result);
        return;
    }
    
    backtrace(false, index + 1, nums);  // 不处理当前的元素，去回溯下一个元素

    // 对于index位置的元素而言，如果前一个元素并未添加进去，同时该位置的元素与前一个相等
    // 那么包含该index的所有子集一定会出现在包含前一个元素的所有子集中，那就没必要继续求了
    if (!process && index > 0 && nums[index] == nums[index - 1])    return; // 直接返回，不需要处理下一个了

    vec_of_result.push_back(nums[index]);
    backtrace(true, index + 1, nums);
    vec_of_result.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    backtrace(false, 0, nums);
    return result_set;
}

int main()
{
    input input90;
    auto input_vec = input90.input_vector();

    auto result = subsetsWithDup(input_vec);

    output output90;

    output90.output_matrix(result);

    return 0;
}