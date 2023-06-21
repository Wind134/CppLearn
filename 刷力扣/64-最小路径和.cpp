/*
* 给定一个包含非负整数的m x n网格grid，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

* 说明：每次只能向下或者向右移动一步。

* 思路：动态规划，minSum[i][j] = min(minSum[i - 1][j], minSum[i][j - 1]) + grid[i][j]

* 而minSum[0][j] = grid[0][0] + ... + grid[0][j]

* min[i][0] = grid[0][0] + ... + grid[i][0]

* 就这么简单
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int minPathSum(const vector<vector<int>>& grid)
{
    int row = grid.size();
    int col = (*grid.begin()).size();
    vector<vector<int>> minSum(row, vector<int>(col));  // 定义一个二维数组


    int sum = 0;
    for (int i = 0; i < col; i++)
    {
        sum += grid[0][i];
        minSum[0][i] = sum;
    }

    sum = grid[0][0];   // 重赋值

    for (int i = 1; i < row; i++)
    {
        sum += grid[i][0];
        minSum[i][0] = sum;
    }
    
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
            minSum[i][j] = min(minSum[i - 1][j], minSum[i][j - 1]) + grid[i][j];
    }
    
    return minSum[row - 1][col - 1];
}


int main()
{
    int m, n;

    cout << "Please input the m & n: ";
    cin >> m >> n;

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
    cout << minPathSum(input) << endl;
    
}