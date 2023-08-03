/*
题目：
- 给定一个m x n的矩阵，如果一个元素为0，则将其所在行和列的所有元素都设为0。请使用原地算法。

思路：
- 设定两个标记数组，一个数组代表矩阵所有行的情况，一个数组代表矩阵所有列的情况；
- 最终根据这个情况做迭代；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // 初始标记位
    bool row_tag[row] = {false};
    bool col_tag[col] = {false};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                row_tag[i] = true;  // 这一行该全部为0
                col_tag[j] = true;  // 这一列该全部为0
            }      
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (row_tag[i] || col_tag[j])   // 如果某一行或者某一列要求全为0，那么这一行的所有元素，这一列的所有元素都应为0
            {
                matrix[i][j] = 0;
            }      
        }
    }
}

int main()
{
    input input73;
    output output73;
    auto input_matrix = input73.input_matrix();
    setZeroes(input_matrix);
    output73.output_matrix(input_matrix);
    
    return 0;
}