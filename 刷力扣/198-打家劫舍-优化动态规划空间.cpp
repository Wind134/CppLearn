/*
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下，一夜之内能够偷窃到的最高金额。

思路：这道题动态规划还是比较方便的吧，设定一个动态规划数组dp_array[i]; 表明如果选择第i个房间盗窃所能窃取的最高金额
- 显然，dp_array[0] = nums[0], dp_array[1] = nums[1];
- dp_array[index] = max(dp_array[0......index - 2]) + nums[index];

- 简化一下做法，减小空间复杂度
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 1)  return nums[0];
    // vector<int> dp_array(size);
    int max_of_index_2 = nums[0];   // 代表index - 2位置的最大盗窃数量
    int max_of_index_1 = nums[1];   // 代表index - 1位置的最大盗窃数量
    int temp_max = max_of_index_2;
    int max_of_index = max(nums[0], nums[1]);
    for (int i = 2; i < size; i++) {
        temp_max = max(temp_max, max_of_index_2);   // 获取前index - 2个位置处的最大值
        max_of_index = max(max_of_index, temp_max + nums[i]);   // 更新目前位置处的最大值
        max_of_index_2 = max(max_of_index_2, max_of_index_1);   // i准备去下一个位置，因此准备更新index - 2处的最大值
        max_of_index_1 = max_of_index;  // 准备更新index - 1处的最大值，其实就是计算出的max_of_index
    }

    // int result = 0;
    // for (auto& elem : dp_array) {
    //     if (elem > result)  result = elem;
    // }

    return max_of_index;
}

int main() {
    input input198;
    auto input_vec = input198.input_vector();

    cout << rob(input_vec) << endl;
}