/* 
题目：相比上题，这道题中元素可以重复

思路：回溯问题
- 对于当前某个index的位置，加入的元素有(n - index)中可能，我们依次推进
- 只是这里需要单独针对重复项进行处理
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> result;
vector<int> elem_of_result;

void backtrace(const vector<int>& nums, vector<int>::iterator it)
{
    if (it == nums.end())
    {
        result.push_back(elem_of_result);
        return;
    }

    for (auto t = it; t != nums.end(); t++)
    {
        if (t > it && *t == *(t-1)) continue;   // 去重操作，重复值没必要处理
        
        elem_of_result.push_back(*t);
        auto newnums = nums;    // 为了保证有序的无奈之举
        newnums.erase(find(newnums.begin(), newnums.end(), *t));
        backtrace(newnums, newnums.begin());
        elem_of_result.pop_back();
    }
    
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    sort(nums.begin(), nums.end()); // 去重很关键，因为要保证相同的数都是挨着的
    backtrace(nums, nums.begin());
    return result;
}

int main()
{
    input input47;
    
    auto vec = input47.input_vector();
    auto result = permuteUnique(vec);

    output output47;

    output47.output_matrix(result);
    return 0;
}