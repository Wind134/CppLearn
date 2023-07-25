/*
题目：
- 给你一个整数数组nums，判断是否存在三元组[nums[a], nums[b], nums[c], nums[d]]
- 满足a、b、c、d互不相同的条件，同时还满足 nums[a] + nums[b] + nums[b] + nums[d] == 0 
- 输出所有符合条件且不重复的四元组

思路：尝试考虑使用回溯，回溯会导致超时，剪枝成了关键
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> vec_of_res;

void backtrace(const vector<int>& nums, long long target, int index) {
    if (vec_of_res.size() == 4) {
        if (target == 0) {
            res.push_back(vec_of_res);
            return;
        }
        else return;
    }

    if (vec_of_res.size() > 4 || vec_of_res.size() + nums.size() - index < 4 || index == nums.size())   return;

    if (!vec_of_res.empty()) {  // 这部分极致剪枝
        int size = nums.size();
        long long last_elem = (long long)*nums.rbegin();
        int n = vec_of_res.size();
        if (index < size - 1) {
            long long curr = (long long)nums[index];
            long long next = (long long)nums[index + 1];
            if (curr + (3 - n) * next > target) return;
        }
        if ((4 - n) * last_elem < target) return;
    }

    
    vec_of_res.push_back(nums[index]);  
    backtrace(nums, target - nums[index], index + 1);
    vec_of_res.pop_back();

    // 上面的这部分，已经执行完了从index开始后的全过程，那么下面没必要再重复执行
    while (index < nums.size() - 1 && nums[index + 1] == nums[index]) index++;

    backtrace(nums, target, index + 1);
    
}


vector<vector<int>> fourSum(vector<int>& nums, int target) 
{
    // long long int longtarget = static_cast<long long int>(target);
    if (nums.size() < 4)
    {
        return {};   
    }
    sort(nums.begin(), nums.end());     // 默认升序

    if (*(nums.end() - 1) <= 0 && target > 0)   return {};
    if (*(nums.begin()) >= 0 && target < 0)   return {};

    long long target_trans = (long long)target;


    backtrace(nums, target_trans, 0);

    return res;
    
}

int main()
{
    input input18;
    auto vec = input18.input_vector();
    int target;
    cout << "Input the target: ";
    cin >> target;

    auto threeSumarray = fourSum(vec, target);
    output output18;
    output18.output_matrix(threeSumarray);
    return 0;
}


