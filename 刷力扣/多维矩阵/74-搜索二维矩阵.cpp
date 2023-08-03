/*
题目：
- 编写一个高效的算法来判断m x n矩阵中，是否存在一个目标值。该矩阵具有如下特性：
- 每行中的整数从左到右按升序排列。
- 每行的第一个整数大于前一行的最后一个整数。

思路：高效算法其实就是利用二分快速定位行列，但其实二分也不算特别高效；
- 把矩阵拉直，整体使用二分
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool searchMatrix(const vector<vector<int>>& matrix, int target)
{
    if (target < matrix[0][0] || target > (*(*matrix.rbegin()).rbegin()))   return false;

    int left = 0;
    int right = matrix.size() * matrix[0].size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int row_index = mid / matrix[0].size();
        int col_index = mid % matrix[0].size();
        if (matrix[row_index][col_index] == target) return true;
        else if (matrix[row_index][col_index] > target) right = mid - 1;
        else left = mid + 1;
    }
    
    return false;
}

int main()
{
    input input74;
    auto input_matrix = input74.input_matrix();
    cout << "Input the target value: ";
    int target;
    cin >> target;

    cout << boolalpha << searchMatrix(input_matrix, target) << endl;
    
    return 0;
}