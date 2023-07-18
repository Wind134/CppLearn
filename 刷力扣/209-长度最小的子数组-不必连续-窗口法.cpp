/*
- 给定一个含有n个正整数的数组和一个正整数target 。

- 找出该数组中满足其和≥target的长度最小的连续子数组[numsl, numsl+1, ..., numsr-1, numsr]，并返回其长度。
- 如果不存在符合条件的子数组，返回0。

是大于等于，同时题目要求的是连续索引的数组即可，这样题目就简化多了
    -- 设定两个指针，分别指向窗口的左右两边 
*/
#include "../headfile/io_for_leetcode.h"
#include <climits>
#include <cmath>
using namespace std;

int minSubArrayLen(int target, const vector<int>& nums) {
    int left = 0;  // 指向我们要维护的窗口左边
    int right = left;   // 指向我们要维护的窗口右边
    int res = INT_MAX;    // 初始结果
    int temp_sum = 0;
    // 获取初始的窗口长度
    while (right < nums.size()) {
        temp_sum += nums[right];
        if (temp_sum < target) right++;
        else {
            while (temp_sum >= target) {
                temp_sum -= nums[left];
                left++;
                if (res == 1)   return res;
            }
            res = (right - left + 2) < res ? (right - left + 2) : res;
            right++;
        }
    }
    
    return (res == INT_MAX) ? 0 : res;
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