/*
题目：
- 给定一个包含非负整数的m x n网格grid，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
- 说明：每次只能向下或者向右移动一步。

思路：动态规划；
- minSum[i][j] = min(minSum[i - 1][j], minSum[i][j - 1]) + grid[i][j]
- 而minSum[0][j] = grid[0][0] + ... + grid[0][j](同样只有一条路)
- min[i][0] = grid[0][0] + ... + grid[i][0](因为只有一条路)
- 就这么简单
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int minPathSum(const vector<vector<int>>& grid)
{
    int row = grid.size();
    int col = (*grid.begin()).size();
    vector<vector<int>> minSum(row, vector<int>(col));  // 定义一个二维数组


    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        sum += grid[0][i];
        minSum[0][i] = sum;
    }

    sum = grid[0][0];   // 重赋值

    for (int i = 1; i < row; i++)
    {
        sum += grid[i][0];
        minSum[i][0] = sum;
    }
    
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
            minSum[i][j] = min(minSum[i - 1][j], minSum[i][j - 1]) + grid[i][j];
    }
    
    return minSum[row - 1][col - 1];
}


int main()
{
    input input64;
    auto input_matrix = input64.input_matrix();
    cout << minPathSum(input_matrix) << endl;
}