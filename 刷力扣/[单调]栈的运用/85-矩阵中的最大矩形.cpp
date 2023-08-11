/**
题目：
- 给定一个仅包含0 和 1、大小为rows x cols的二维二进制矩阵，找出只包含1的最大矩形，并返回其面积。

思路：延续单调栈的思路；
- 一行一行处理，每一行的处理就是84题的翻版；
- 单调栈确实是个好东西；

*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) 
{
    if (matrix.empty()) return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int res = 0;
    vector<int> height(col + 1);    // 保存每行矩形的高度，初始化全为0
    for (int i = 0; i < row; ++i) {
        stack<int> indexes;
        indexes.push(-1);
        matrix[i].push_back(0); // 给每一行数组的最后一个地方添加0，表明已到末端
        for (int j = 0; j <= col; ++j) {    // 注意判别，是小于等于col，因为已经添加了
            // 想办法求高度，简单递增即可
            if (matrix[i][j] == '1')    ++height[j];
            else height[j] = 0; // 否则直接转化为0，这个好理解，也正因为这个原因，上面是1下面是0的情况会被直接剔掉(判为0)
            // 接下来就是调用84题的核心算法了

            while (indexes.top() != -1 && height[indexes.top()] > height[j]) {
                int index = indexes.top();
                indexes.pop();
                res = max(res, (j - indexes.top() - 1) * height[index]);    // 弹出左边更大的那个值，并求取相应的面积
            }
            indexes.push(j);
        }
    }

    return res;
}

int main() {
    input input85;
    auto input_matrix = input85.input_char_matrix();

    cout << maximalRectangle(input_matrix) << endl;

    return 0;

}

