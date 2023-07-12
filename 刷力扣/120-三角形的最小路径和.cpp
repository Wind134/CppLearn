/* 
给定一个三角形triangle，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点在这里指的是下标与上一层结点下标相同
或者等于上一层结点下标+1的两个结点。也就是说，如果正位于当前行的下标i，那么下一步可以移动到下一行的下标i或i + 1。

思考：
    - 分开来看，特别像一棵树，但是目前暂且不考虑树的做法，如果使用回溯，每个都算一遍肯定不是什么高效的做法
    - 即便求和的过程中可以尝试剪枝

    - 假设轮到了某一个数字，对于下行该选哪个是不确定的，因为即便某个数暂时是小一点，但不代表下下行加上一个数还会更小

经过思考，决定采用动态规划来做此题，我们基于最后一行的大小设定一个dp数组，为了尽可能减少空间的占用，我们随着
对矩阵的遍历，不断的重复更新dp_array的内容，直到遍历完最后一行，取dp_array当中的最小值；
假设矩阵大小为4
- 第一行，一个元素，因此只有dp_array[0] = matrix[0][0]，其他不管
- 第二行，两个元素，因此dp_array大小也变成了2，此时dp[1] = dp[0] + matrix[1][1]，然后更新dp_array[0] = dp_array[0] + matrix[1][1];
- 也就是说，随着行的遍历，dp_array也在跟着更新，其中更新的范围是从后往前

- 第n行，dp_appay应该有n个元素，其中dp[n - 1] = dp[n - 2] + matrix[n - 1][n - 1], dp[n - 2] = min (dp[n - 2], dp[n - 3]) + matrix[n][n - 2]

dp数组中的每个元素的含义
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

const int& MAX_INT = 2147483647;

int minimumTotal(const vector<vector<int>>& triangle) {
    int size = triangle.size();
    vector<int> dp_array(size);

    dp_array[0] = triangle[0][0];

    for (int i = 1; i < size; i++)
    {
        dp_array[i] = dp_array[i - 1] + triangle[i][i]; // 最后一个特殊处理
        for (int j = i - 1; j >= 0; j--)    // 数组的长度等于行数，所以事情反而好办了起来
        {
            if (j >= 1) dp_array[j] = min(dp_array[j - 1], dp_array[j]) + triangle[i][j];
            else   dp_array[j] = dp_array[j] + triangle[i][j]; 
        }
    }

    // dp_array应该更新完成了
    int result = MAX_INT;
    for (auto& elem : dp_array)
        if (elem < result)  result = elem;    
    
    return result;
}

int main()
{
    input input120;
    auto matrix = input120.input_matrix();

    cout << minimumTotal(matrix) << endl;
    return 0;
}