/* 
* 编写一个高效的算法来判断m x n矩阵中，是否存在一个目标值。该矩阵具有如下特性：
* 每行中的整数从左到右按升序排列。
* 每行的第一个整数大于前一行的最后一个整数。

* 高效算法其实就是利用二分快速定位行列
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int left = 0, right = matrix.size() - 1;

    int target_row = -1;    // 保存目标行

    if (target < matrix[left][0])   return false;

    if (target > matrix[right][0])
    {
        target_row = right; // 直接去最后一行寻找目标
    }
    else    // 必定在[left, right]之间
    {
        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (matrix[mid][0] == target)   return true;
            if (matrix[mid][0] < target && matrix[mid + 1][0] > target)
            {
                target_row = mid;
                break;
            }
            else if (matrix[mid][0] > target)    right = mid - 1;
            else    left = mid + 1;
        }
    }
    
    left = 0;
    right = matrix[0].size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (matrix[target_row][mid] == target)   return true;
        else if (matrix[target_row][mid] > target)    right = mid - 1;
        else    left = mid + 1;
    }

    return false;
    
}

int main()
{
    int m, n, target;

    cout << "Please input the m & n & target: ";
    cin >> m >> n >> target;

    cin.get();
    string line;

    int input_data;

    vector<vector<int>> input;

    while (m != 0 && getline(cin, line))
    {
        istringstream iss(line);    // istringstream对象可以提取输入行中的相应类型
        
        vector<int> vec_of_input;
        
        while (iss >> input_data)
        {
            vec_of_input.push_back(input_data);
        }

        input.push_back(vec_of_input);
        m--;   
    }

    cout << boolalpha << searchMatrix(input, target) << endl;
    
    return 0;
}