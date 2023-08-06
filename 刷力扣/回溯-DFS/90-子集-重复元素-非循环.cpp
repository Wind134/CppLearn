/*
题目：
- 给你一个整数数组nums，其中可能包含重复元素，请你返回该数组所有可能的子集(幂集)

思路：思路就是一个很明显的回溯，每个数都面临两种情况，选或者不选
- 首先还是需要排序，将所有相同的元素靠近在一起；
- 如果处理重复的问题：
    -- 我们先要明白这个回溯做的是什么，是选中与不选中index上的某个数后，求后续那些数的子集；
    -- 如果我们不选中某个数，求接下来的数子集，与选中某个数，求接下来的子集，必然是不同的，这是没有重复数字下的情况；
    -- 如果有重复的数字了，假设这个数字的前一个重复的数字没有加入，我们就没必要求接下来的子集了；
    -- 因为处理这个数字的前一个重复的数字时，已经求了没有加入这个数字的集合，那我们还要重复求取干嘛；
    -- 而如果加入了，就不一样了，因为加入的情况我们没有处理过，得处理；
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
    
    // 以1 2 2 2 3 5为例，假设index为2(处理第二个2)，那么这个回溯做的就是在不加入那个2的时候寻找2 3 5的子集；
    backtrace(false, index + 1, nums);  // 不加入当前的元素，去找index + 1开始的那些元素的子集；

    // process表明的是上个元素是否加入进去了，如果上个元素没有，假设第一个2没有加进去；
    // 同时该元素与前面一个元素重复，那就不需要处理包含第2个2的子集了；
    // 因为包含第一个2的子集在此之前已经被求取，显然，包含前面那个2的子集一定也包括包含第2个2的子集；
    if (!process && index > 0 && nums[index] == nums[index - 1])    return; // 直接返回，不需要处理下一个了

    vec_of_result.push_back(nums[index]);
    backtrace(true, index + 1, nums);   // 这个回溯做的就是，求取加入当前元素之后，后续的子集，这个回溯保证了与上面那个回溯一定不会重复；
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