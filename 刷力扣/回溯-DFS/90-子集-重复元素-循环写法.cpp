/*
题目：
- 给你一个整数数组nums，其中可能包含重复元素，请你返回该数组所有可能的子集(幂集)

思路：思路就是一个很明显的回溯，每个数都面临两种情况，选或者不选
- 首先还是需要排序，将所有相同的元素靠近在一起；
- 如果处理重复的问题：
    -- 假设前面的某个数x，后面有一个一样的数y；
    -- 在处理x的时候，回溯的任务是求取所有包含x的子集；
    -- 而对于后面那个一模一样的数y，就没有必要处理y了；
    -- 因为所有包含y的子集一定在包含x的子集范围内，不需要重复处理；

- 循环写法更好理解一点；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> result_set;
vector<int> vec_of_result;


void backtrace(const vector<int>& nums, int index)
{
    result_set.push_back(vec_of_result);

    if (index >= nums.size())   return;
    
    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1])    continue;
        vec_of_result.push_back(nums[i]);
        backtrace(nums, i + 1);     // 求下一个位置开始的一系列元素的子集
        vec_of_result.pop_back();   // 求完之后弹出
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    backtrace(nums, 0);
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