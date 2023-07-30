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

void backtrace(vector<int>& nums, vector<int>::iterator it)   // 用了迭代器当递归参数
{
    if (it == nums.end())
    {
        result.push_back(elem_of_result);
        return;
    }

    for (auto t = it; t != nums.end(); t++)
    {
        elem_of_result.push_back(*t);
        auto newnums = nums;
        newnums.erase(find(newnums.begin(), newnums.end(), *t));
        backtrace(newnums, newnums.begin());
        elem_of_result.pop_back();
    }
    
}

vector<vector<int>> permute(vector<int>& nums) 
{
    backtrace(nums, nums.begin());
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