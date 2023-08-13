/**
 * 题目：
 * - 给定一个整数数组nums和一个正整数k，找出是否有可能把这个数组分成k个非空子集，其总和都相等。
 * 
 * 思路：
 * - 初步认定还是动态规划，类似于背包问题；
 * - 设定动态矩阵dp[i][j]，存储的是数组[0...i]的序列中，可以划分出的目标为j的子序列个数；
 * - 通过规划无法处理这道题，这种涉及到K的处理大概率还是要回溯；
 * - 这道题的回溯相当有深度！
 * - 同时还学习到了决策树的思路；
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

/**
 * @brief 回溯的基本思路是找到合适的放置的桶，能放就放进去，不能放就找下一个桶，如果所有桶都不能放，返回false；
 */
bool backtrace(const vector<int>& nums, int index, int k, int target, vector<int>& v) { // 数组传引用
    if (index == nums.size())   return true;    // 一定能放置，因为这个时候说明每个球都放进了对应的桶

    for (int i = 0; i < k; i++) // 对每个桶做判断
    {
        if (i > 0 && v[i] == v[i - 1])  continue;   // 一些已经处理过的桶不必再放了，因此已经放过了，不必重复了
        if (v[i] + nums[index] > target)    continue;

        v[i] += nums[index];

        if (backtrace(nums, index + 1, k, target, v))   return true;

        v[i] -= nums[index];
    }
    
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    int maxValue = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        maxValue = max(maxValue, nums[i]);
    }
    if (sum % k)    return false;
    else if (maxValue > sum / k)    return false;
    
    int target_value = sum / k;

    vector<int> barrel(k);
    sort(nums.rbegin(), nums.rend());   // 为剪枝而增加的排序，这是数学层面的剪枝，大的在前，让回溯尽快返回；

    return backtrace(nums, 0, k, target_value, barrel);
}

int main() {
    input input698;
    auto vec = input698.input_vector();
    cout << "Please input the K value: ";
    int k;
    cin >> k;
    cout << boolalpha << canPartitionKSubsets(vec, k) << endl;
}