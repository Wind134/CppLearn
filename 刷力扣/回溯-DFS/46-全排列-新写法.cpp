/*
题目：
- 给定一个不含重复数字的数组nums，返回其所有可能的全排列，可以按任意顺序返回答案。

思路：回溯问题，也是数学问题
- 对于当前某个index的位置，加入的元素有(n - index)中可能，我们依次推进
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> result;
vector<int> elem_of_result;

void backtrace(vector<int>& nums, int index)
{
    if (index == nums.size())
    {
        result.push_back(elem_of_result);
        return;
    }

    // 每个位置插入的元素的可能会逐步减小
    // index = 0的时候有n种可能，index = 1的时候有(n - 1)种可能，以此类推
    for (int j = index; j < nums.size(); j++) { 
        elem_of_result.push_back(nums[j]);
        swap(nums[index], nums[j]);
        backtrace(nums, index + 1);
        swap(nums[index], nums[j]); // 记得换回来
        elem_of_result.pop_back();
    }
    
}

vector<vector<int>> permute(vector<int>& nums) 
{
    backtrace(nums, 0);
    return result;
}

int main()
{
    input input46;
    
    auto vec = input46.input_vector();
    auto result = permute(vec);

    output output46;

    output46.output_matrix(result);
    return 0;
}