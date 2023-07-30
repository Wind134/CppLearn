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
vector<int> visited;

void backtrace(const vector<int>& nums, int index)
{
    if (index == nums.size())
    {
        result.push_back(elem_of_result);
        return;
    }

    for (int j = 0; j < (int)nums.size(); j++) {
        if (visited[j] || (j > 0 && nums[j] == nums[j - 1] && !visited[j - 1])) continue;   // 重复项剪枝
    
        elem_of_result.push_back(nums[j]);
        visited[j] = 1;
        backtrace(nums, index + 1);
        elem_of_result.pop_back();
        visited[j] = 0;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
    visited.resize(nums.size());
    sort(nums.begin(), nums.end()); // 去重很关键，因为要保证相同的数都是挨着的
    backtrace(nums, 0);
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

// 下面这个做法的问题主要在于破坏了后续的元素递增顺序
/* // 每个位置插入的元素的可能会逐步减小
    // index = 0的时候有n种可能，index = 1的时候有(n - 1)种可能，以此类推
    for (int j = index; j < nums.size(); j++) {
        // 去重操作，这一步自己想的，还挺妙
        // 从数学角度来说就是，减小某个位置插入的可能性，因为要处理的值与当前值相同
        // 而这种情况，在先前已经处理过了，没必要再重复处理
        if (j > index && nums[j] == nums[j - 1])    continue;

        elem_of_result.push_back(nums[j]);
        swap(nums[index], nums[j]);
        backtrace(nums, index + 1);
        swap(nums[index], nums[j]); // 记得换回来
        elem_of_result.pop_back();
    }  */