/*
题目：
- 给你一个整数数组nums，数组中的元素互不相同。返回该数组所有可能的子集(包括空集)。

要求：
- 解集不能包含重复的子集。
- 可以按任意顺序返回解集。

思路：
- 对于索引位置index而言，该位置上的元素只有两种可能：选，或者不选
- 如果不选，那么该位置舍弃，直接处理下一个位置，下一个位置处理完毕之后，记得恢复处理该位置时的vec数组
- 如果选，那么该位置作为集合的一部分，加入集合
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<int>> result;
vector<int> vec_of_result;

void backtrace(const vector<int>& nums, int index)
{
    if (index == nums.size())
    {
        result.push_back(vec_of_result);
        return;
    }

    // 选中当前index
    vec_of_result.push_back(nums[index]);
    backtrace(nums, index + 1);
    vec_of_result.pop_back();
    
    backtrace(nums, index + 1);    // 不选中当前index
}

vector<vector<int>> subsets(vector<int>& nums)
{
    backtrace(nums, 0);
    return result;
}

int main()
{
    input input78;
    output output78;
    auto vec = input78.input_vector();
    auto result = subsets(vec);
    output78.output_matrix(result);

    return 0;
}