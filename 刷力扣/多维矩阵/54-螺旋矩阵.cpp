/*
题目：
- 给你一个m行n列的矩阵matrix，请按照顺时针螺旋顺序，返回矩阵中的所有元素。


思路：
- 贼简单，先列增长，再行增长，遇到访问过的，代表某一个方向已经访问完成；
- 由于题目要求顺时针，因此首先变化的是列，列到底了，说明一行已经访问完了；
- 列数增加，行数增加，列数减少，行数减少，一轮执行完毕，新的一轮又是列数增加....
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix) 
{
    vector<int> result;

    if (matrix.empty() || matrix[0].empty())
    {
        return result; 
    }
    
    int row_size = matrix.size();    // 记录行数，以下两个值会在后续不断的变化
    int col_size = matrix[0].size(); // 记录列数

    int row = matrix.size();    // 记录真实行数
    int col = matrix[0].size(); // 记录真实列数

    int row_count_up = 0;   // 上方的行减少的数量，也可以理解为上方起始行的一种表达；
    int row_count_down = 0; // 下方的行减少的数量
    int col_count_left = 0; // 左边的列减少的数量
    int col_count_right = 0;// 右边的列减少的数量

    
    while(true)
    {
        for(int i = col_count_left; i < col - col_count_right; i++) // 访问上方某行
        {
            result.push_back(matrix[row_count_up][i]);
        }
        row_size--; // 行数在不断减小
        row_count_up++;
        if (!row_size)   break; // 所有行都已访问完，可以结束了
        
        for(int i = row_count_up; i < row - row_count_down; i++)    // 访问右边某列
        {
            result.push_back(matrix[i][col - col_count_right - 1]);
        }
        col_size--; // 列数不断减小
        col_count_right++;
        if (!col_size)   break;

        for (int i = col - col_count_right - 1; i >= col_count_left; i--)   // 访问下方某行
        {
            result.push_back(matrix[row - row_count_down - 1][i]);
        }
        row_size--; // 行数接着减小
        row_count_down++;
        if (!row_size)   break;

        for(int i = row - row_count_down - 1; i >= row_count_up; i--)   // 访问左方某列
        {
            result.push_back(matrix[i][col_count_left]);
        }
        col_size--;
        col_count_left++;
        
        if (!col_size)   break;
    }

    return result;
}

int main()
{
    input input54;
    output output54;

    auto input_matrix = input54.input_matrix();

    auto res = spiralOrder(input_matrix);

    output54.output_array(res);

    return 0;
}