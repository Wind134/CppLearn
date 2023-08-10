/*
题目：
- 你是一个专业的小偷，计划偷窃沿街的房屋。
- 每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
- 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
- 给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下，一夜之内能够偷窃到的最高金额。
- 相比198题目，多了一个成环的条件

那就是说，第一个和最后一个数组元素两者只能选一个
- 选择第一个元素，那么处理到size - 2即可
- 不选择第一个元素，那么可以处理到最后一个元素

两个数组绝对可以解决这个问题，就是空间复杂度略高

我代码写得也不够优雅了

如果nums[0] > nums[1]，那么我们是不是可以选择第一个呢

思路：设定一个动态规划数组dp_array[i]; 表明如果选择第i个房间盗窃所能窃取的最高金额
- 
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 1)  return nums[0];
    if (size == 2)  return max(nums[0], nums[1]);
    
    int result = 0;
    // 选择第一个数的数组
    vector<int> dp_array1(size - 1);
    // 选择第二个数的数组
    vector<int> dp_array2(size - 1);
    // 初始化前2个
    dp_array1[0] = nums[0]; 
    dp_array1[1] = nums[1];
    result = max(result, max(dp_array1[0], dp_array1[1]));

    // 初始化后2个
    dp_array2[0] = nums[1];
    dp_array2[1] = nums[2];
    result = max(result, max(dp_array2[0], dp_array2[1]));

    // 初始化临时最大值
    int temp_max1 = dp_array1[0];
    int temp_max2 = dp_array2[0];

    // 选第一个元素
    for (int i = 2; i < size - 1; i++) {
        temp_max1 = max(temp_max1, dp_array1[i - 2]);
        dp_array1[i] = temp_max1 + nums[i];
        result = max(result, dp_array1[i]);
    }

    // 选第二个元素
    for (int i = 3; i < size; i++) {
        temp_max2 = max(temp_max2, dp_array2[i - 3]);
        dp_array2[i - 1] = temp_max2 + nums[i];
        result = max(result, dp_array2[i - 1]);
    }

    return result;
}

int main() {
    input input198;
    auto input_vec = input198.input_vector();

    cout << rob(input_vec) << endl;
}