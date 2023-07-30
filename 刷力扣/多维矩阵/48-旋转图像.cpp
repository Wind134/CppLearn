/*
题目：
- 给定一个n × n的二维矩阵matrix表示一个图像。请你将图像顺时针旋转90度。
- 要求必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
- 附注：最后的结果就像是顺时针翻转了90度。

思路：
- 观察矩阵信息，可以很明显的看到规律：第一行的数组变成了最后一列的数组、第二行的数组变成了倒数第二列的数组
- 那么，也就是第n行的数组变成了倒数第n列的数组，如果允许再创造一个矩阵，将会很容易写出代码，但题目要求原地修改
- 那我们只能尝试绕圈的思路，每一圈看成一个循环数组来处理，关注矩阵的每一条边的某一个元素：
    -- 我们可以发现的规律是上边和右边即将交换的两个元素，从循环数组的角度来看，他们之间的距离永远是(矩阵的长度 - 1)，一个固定值
    -- 我们不断的缩小这个圈，直到这个圈只剩下一个元素
- 因此我们建立一个数组来保留这四个角的元素

- 还有一种比较巧妙的办法就是，先水平翻转再按对角线翻转，同样可以实现目的；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    int k = 0;
    auto tempArray = vector<int>(4);
    int last_row_index = size - 1;  // 更改一下标记的变量，让代码更可读，最后一行的索引
    int last_col_index = size - 1;  // 最后一列的索引
    
    while (k < size / 2)    // 循环的次数，也就是绕圈的次数，这是一个固定值
    {
        int next_size = size - k * 2;   // 下一轮大小，循环的次数与矩阵大小正相关

        for(int i = 0; i < next_size - 1; i++)
        {
            // 永远保存着四条边上相应的某个元素(那一圈循环数组)
            tempArray[0] = matrix[k][k + i];    // 上
            tempArray[1] = matrix[k + i][last_col_index - k];    // 右
            tempArray[2] = matrix[last_col_index - k][last_col_index - k - i]; // 下
            tempArray[3] = matrix[last_row_index - k - i][k];    // 左
            matrix[k + i][last_col_index - k] = tempArray[0];
            matrix[last_col_index - k][last_col_index - k - i] = tempArray[1];
            matrix[last_col_index - k - i][k] = tempArray[2];
            matrix[k][k + i] = tempArray[3];
        }
        k++;
    }   
}

int main()
{
    input input48;

    auto inputMatrix = input48.input_matrix();

    rotate(inputMatrix);

    output output48;

    output48.output_matrix(inputMatrix);
    
    return 0;
}