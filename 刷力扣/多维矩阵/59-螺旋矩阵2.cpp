/*
题目：
- 给你一个正整数n，生成一个包含1到n^2所有元素，且元素按顺时针顺序螺旋排列的nxn正方形矩阵matrix。

思路：54题的逆过程，当然，54题本身矩阵行列并不等。
- 对矩阵绕圈圈的过程；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n));  // 初始化了一个矩阵matrix

    int row_up = 0;         // 上方行索引
    int row_down = n - 1;   // 下方行索引
    int col_left = 0;       // 左边列索引
    int col_right = n - 1;  // 右边列索引

    int init_value = 1;

    while (true)
    {
        for (int i = col_left; i <= col_right; ++i)  // 第上行开始，列号变化
        {
            result[row_up][i] = init_value;
            init_value++;
        }
        ++row_up;   // 上边行成功完成，恭喜，上方行索引加1

        if(init_value == n * n + 1) break;
        
        for (int i = row_up; i <= row_down; ++i)
        {
            result[i][col_right] = init_value;
            init_value++;
        }
        --col_right;    // 右边列成功完成，恭喜，右方列索引减1
        // if(init_value == n * n + 1) break;
        
        for (int i = col_right; i >= col_left; --i)
        {
            result[row_down][i] = init_value;
            init_value++;
        }
        --row_down;
        // if(init_value == n * n + 1) break;
        
        for (int i = row_down; i >= row_up; --i)
        {
            result[i][col_left] = init_value;
            init_value++;
        }
        ++col_left;
        if(init_value == n * n + 1) break;        
    }

    return result;
}

int main()
{
    int input_num;

    cin >> input_num;

    auto output_res = generateMatrix(input_num);

    output output59;
    output59.output_matrix(output_res);

    return 0;
}