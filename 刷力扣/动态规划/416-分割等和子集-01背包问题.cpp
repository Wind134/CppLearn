/**
 * 题目：
 * - 给你一个只包含正整数的非空数组nums。
 * - 请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 思路：
 * - 这是一个经典的NP完全问题，目前这是一个数学界悬而未决的问题，建立描述暂且不表；
 * - 而本题又属于NP完全问题的一种，即0-1背包问题，且听接下来的分析；
 * - 0-1背包的介绍：
 *  -- 一共有N件物品，第i（i从1开始）件物品的重量为w[i]，价值为v[i]。
 *  -- 在总重量不超过背包承载上限W的情况下，能够装入背包的最大价值是多少？
 * - 具体的思路就是我们设定一个动态规划数组，dp[i][j]，表示从1~i(index->0 ~ (i - 1))件物品
 * - 放入承载上限为j(index->0 ~ j)的背包所能获取的最大价值！
 * - 显然，dp[0~N-1][0] = 0；
 * - 动态规划的状态转移方程：
 *  -- dp[i][j]的值取决于如果放入第i个物品，与不放入第i个物品，这两种情况下的价值更大值
 *  -- dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]) j >= w[i]
 *  -- dp[i][j] = dp[i - 1][j]  j < w[i]
 * - 而落实到这道题就是：
 *  -- 首先考虑数组和的值，如果为奇数则必然不可能，如果为偶数，要考虑整个数组的最大值，如果超过和的一半，则不可能；
 *  -- 在可能的情况下，这道题的目的就转换为了：求一个子集，子集中数的和为num / 2；
 *  -- 然后仿照01背包问题，设定一个dp[i][j]，表明从数组num[0~i]中找和为j的子集，看能否找到；
 *  -- 动态规划数组：
 *  -- dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];    j >= nums[i];
 *  -- dp[i][j] = dp[i - 1][j] 
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool canPartition(vector<int>& nums) {
    int size = nums.size();
    int sum = 0;
    int maxValue = 0;
    for (int i = 0; i < size; i++)
    {
        sum += nums[i];
        maxValue = max(maxValue, nums[i]);
    }

    if (sum % 2)    return false;
    else if (maxValue > sum / 2)    return false;
    else if (maxValue == sum / 2)   return true;

    int target = sum / 2;
    
    vector<vector<bool>> dp_matrix(size, vector<bool>(target + 1));
    for (int i = 0; i < size; i++)  dp_matrix[i][0] = false;    // 数组中都是正整数 
    dp_matrix[0][nums[0]] = true;   
    for (int j = 1; j <= target; j++) {
        for (int i = 1; i < size; i++) {
            if (nums[i] <= j)   dp_matrix[i][j] = dp_matrix[i - 1][j] | dp_matrix[i - 1][j - nums[i]];
            else    dp_matrix[i][j] = dp_matrix[i - 1][j];
        }
    }

    return dp_matrix[size - 1][target];
}

int main() {
    input input416;
    auto vec = input416.input_vector();
    cout << boolalpha << canPartition(vec) << endl;

    return 0;
}