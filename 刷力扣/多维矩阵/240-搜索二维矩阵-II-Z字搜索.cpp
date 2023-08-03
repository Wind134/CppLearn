/*
题目：
- 编写一个高效的算法来搜索mxn矩阵matrix中的一个目标值target。该矩阵具有以下特性：
- 每行的元素从左到右升序排列；
- 每列的元素从上到下升序排列；

思路：随机给定一个值，我们尽可能缩小要搜寻的范围
- Z字形搜索是很棒的一种算法
- 特此开新帖，记录该算法
    -- 首先定位于右上角的元素matrix[0][col - 1]，如果该元素恰好等于target，则返回true结果;
    -- 如果该元素大于target，那么这一列的所有元素则不可能满足target，更新列号
    -- 如果该元素小于target，那么这一行的所有元素均可告辞，因为同样不能满足target
    -- 重复操作，直到超出了矩阵的范围
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int right_up_i = 0, right_up_j = col - 1;
    while (right_up_i < row && right_up_j >= 0) {
        if (matrix[right_up_i][right_up_j] == target)   return true;

        else if (matrix[right_up_i][right_up_j] > target)   --right_up_j;

        else ++right_up_i;
    }
    

    return false;
}

int main() {
    input input240;

    auto input_matrix = input240.input_matrix();
    cout << "Please input the target value: ";
    int target;
    cin >> target;

    cout << boolalpha << searchMatrix(input_matrix, target) << endl;

    return 0;
}