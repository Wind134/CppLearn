/*
题目：
- 给定一个含有n个正整数的数组和一个正整数target。
- 找出该数组中满足其和≥target的长度最小的连续子数组，只要求索引连续而并非数据连续，并返回其长度。
- 如果不存在符合条件的子数组，返回0。

注意：
- 题目已经给定范围是正整数了，因此不需要考虑负；

思路：暴力法逐个判断，n^2级别的复杂度
-- 是大于等于，同时题目要求的是连续索引的数组即可，这样题目就简化多了
-- 设定两个指针，分别指向窗口的左右两边 
-- 暴力能做，但超时；
-- 超时的点在于left每次只是自增1；
-- 优化的空间在于能否直接跳一个窗口呢？
-- 假设我们获取了一个长度为n，n窗口范围内所有元素的和为target；
    -- 那么相等或者更长的窗口就不会是我们所关心的；
    -- 只需要聚焦更短的窗口
*/
#include "../headfile/io_for_leetcode.h"
#include <climits>
#include <cmath>
using namespace std;

int minSubArrayLen(int target, const vector<int>& nums) {
    int left = 0;  // 初始起点
    int res = INT_MAX;    // 初始结果
    while (left < nums.size()) {
        if (nums[left] >= target)  return 1;    // 左边元素等于，直接返回1
        // 如果左边的元素小于目标值，接下来我们可以判断了
        else {
            int temp_sum = nums[left];
            int right = left + 1;
            while (right < nums.size()) {
                if ((temp_sum += nums[right]) >= target) break;
                else right++;
            }
            if (right == nums.size())   return (res == INT_MAX) ? 0 : res;
            else res = (right - left + 1) < res ? (right - left + 1) : res;
        }
        left++;    
    }
    
    return res;
}
        

int main() {
    input input209;
    auto input_vec = input209.input_vector();
    cout << "Input the target: ";
    int t;
    cin >> t;

    cout << minSubArrayLen(t, input_vec) << endl;

    return 0;
}