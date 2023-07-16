/*
- 给定一个未排序的整数数组nums，找出数字连续的最长序列(不要求序列元素在原数组中连续)的长度。

- 请你设计并实现时间复杂度为O(n)的算法解决此问题。
    -- 这就隐含了我们不能排序
    -- 考虑借助一个辅助数组

思路：题目要求序列连续，这就意味着当x存在于这个数组中，x - 1或者x + 1必须有一个存在于数组中    
    
*/
#include "../headfile/io_for_leetcode.h"
#include <unordered_set>
using namespace std;

int longestConsecutive(const vector<int>& nums) {
    if (nums.empty())   return 0;
    unordered_set<int> nums_set(nums.begin(), nums.end());  // 已经去重
    int result = 1; // 结果的初始值

    // 我们制定这么一个规则，我们要求从x开始，去依次枚举，这样就需要保证x - 1不存在
    // 如果x - 1存在呢，那我们先不管，因为总会轮到这个数，等下次轮到再说，我们依然会按照这个原则处理
    for (const auto& num : nums_set) {
        
        // 如果x - 1不存在
        if (nums_set.count(num - 1) == 0) {
            int curr_num = num;
            int temp_length = 1;

            while (nums_set.count(curr_num + 1)) {
                curr_num++;
                temp_length++;
            }

             // 更新能找到的最大长度
            result = max(result, temp_length);
        }
       
        // 如果更小值存在呢，无所谓，不处理，因为我们依然会按照这个原则处理，这样下去总会到最后一个最小的那个元素
    }
    return result;
}   

int main() {
    input input128;
    auto vec = input128.input_vector();

    cout << longestConsecutive(vec) << endl;

    return 0;
}