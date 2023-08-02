/*
题目：
- 一个机器人位于一个m x n网格的左上角，机器人每次只能向下或者向右移动一步，机器人试图达到网格的右下角。
- 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
- 注意：网格中的障碍物和空位置分别用1和0来表示。

思路：动态规划，延续上题的做法，只是这次需要考虑障碍物的存在；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) 
{
    auto temp_matrix = obstacleGrid;
    int row = temp_matrix.size();
    int col = temp_matrix[0].size();
    if (temp_matrix[0][0] == 1 || temp_matrix[row - 1][col - 1] == 1)   return 0;

    // 获取动态规划矩阵第一行的数值信息
    for (int i = 0; i < col; i++)
    {
        if (temp_matrix[0][i] != 1) temp_matrix[0][i] = 1;
        else    // 等于1代表遇到了障碍物
        {
            for(int j = i; j < col; j++)    temp_matrix[0][j] = 0;
            break;
        }
    }

    // 获取动态规划矩阵第一列的数值信息
    for (int i = 1; i < row; i++)
    {
        if (temp_matrix[i][0] != 1) temp_matrix[i][0] = 1;
        else
        {
            for(int j = i; j < row; j++)    temp_matrix[j][0] = 0;
            break;
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (temp_matrix[i][j] != 1)
            {
                temp_matrix[i][j] = temp_matrix[i][j - 1] + temp_matrix[i - 1][j];
            }
            else temp_matrix[i][j] = 0;
        }
        
    }
    
    return temp_matrix[row - 1][col - 1];
}

int main()
{
    input input63;

    auto input_matrix = input63.input_matrix();

    cout << uniquePathsWithObstacles(input_matrix) << endl;
    
}