/**
 * 题目：
 * 给你一个整数数组nums和一个整数k，请你统计并返回该数组中和为k的连续子数组的个数。
 * 
 * 思路：
 * 第一眼是回溯，因为不确定数组的元素个数，只有回溯方便处理这个问题；
 * 但是题目要求的是连续子数组，所以好像回溯也没太大意义
 * 其实回溯本质上就是枚举....考虑换种方式做这个题目
 * 
 * 考虑使用前缀和思想：前缀和（Prefix Sum）是一种常用的算法思想，主要用于
 * 处理数组或序列中元素的累加和。通过提前计算出前缀和数组，可以在常数时间内
 * 快速求解数组中任意区间的累加和。
 * 这种方法对于需要频繁查询区间和的问题非常有效。
 * 
 * 对于这道题：
 * 假设pre[i]是索引[0....i]数组的元素之和，那么显然：
 * pre[i] = pre[i - 1] + nums[i]；
 * 而对于子数组：[j...i]之和，它等价于pre[i] - pre[j - 1]，题目要求和为k的连续子数组个数：
 * 即pre[i] - k = pre[j - 1]，这种(j - 1)的个数即可；
 * 这种怎么找呢？显然只需要计算pre[i]，然后减去的k，看看有多少和为pre[i] - k的结果
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sum_times;
    sum_times[0] = 1;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];

        // 先寻找，再自增，否则会多次重复算自己这个位置
        // 而在上述的公式中，i与j - 1显然不能是重合的
        // 也就是说，i与j - 1显然是不同的索引位置
        if (sum_times.find(sum - k) != sum_times.end()) {
            res += sum_times[sum - k];
        }
        ++sum_times[sum];
    }

    return res;
}

int main() {
    input input560;
    auto vec = input560.input_vector();
    int k;
    cin >> k;
    cout << subarraySum(vec, k) << endl;

    return 0;
}