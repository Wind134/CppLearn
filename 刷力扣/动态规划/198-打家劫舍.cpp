/*
题目：
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下，一夜之内能够偷窃到的最高金额。

思路：这道题动态规划还是比较方便的吧，设定一个动态规划数组dp_array[i]; 表明如果选择第i个房间盗窃所能窃取的最高金额
- 显然，dp_array[0] = nums[0], dp_array[1] = nums[1];
- dp_array[index] = max(dp_array[0......index - 2]) + nums[index];
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 1)  return nums[0];
    vector<int> dp_array(size);
    dp_array[0] = nums[0];
    dp_array[1] = nums[1];
    int temp_max = dp_array[0];
    for (int i = 2; i < size; i++) {
        temp_max = max(temp_max, dp_array[i - 2]);
        dp_array[i] = temp_max + nums[i];
    }

    int result = 0;
    for (auto& elem : dp_array) {
        if (elem > result)  result = elem;
    }

    return result;
}

int main() {
    input input198;
    auto input_vec = input198.input_vector();

    cout << rob(input_vec) << endl;
}