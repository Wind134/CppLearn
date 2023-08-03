/*
题目：
- 编写一个高效的算法来搜索mxn矩阵matrix中的一个目标值target。该矩阵具有以下特性：
- 每行的元素从左到右升序排列；
- 每列的元素从上到下升序排列；

思路：随机给定一个值，我们尽可能缩小要搜寻的范围
- 要是小于matrix[0][0]或者大于matrix[m - 1][n - 1]，直接返回false
- 接下来，找到这个数最先可能存在的行，以及最后可能存在的行
- 这个思想有点类似，退化寻找，先找行列
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int begin_row = 0, end_row = row - 1;
    bool begin_tag = false; // 给寻找开始行设定一个标签，结尾行就免了
    for (int i = 0; i < row; i++) {
        if (!begin_tag && matrix[i][0] <= 0) {
            begin_row = i;
            begin_tag = true;
        }
        if (matrix[i][0] > target) {
            end_row = i - 1;
            break;  // 使命完成，break
        }
    }

    for (int i = begin_row; i <= end_row; i++) {
        int left = 0, right = col - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[i][mid] == target)   return true;
            else if (matrix[i][mid] > target) right = mid - 1;
            else left = mid + 1;
        } 
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