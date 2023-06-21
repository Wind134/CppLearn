/* 
* 一个机器人位于一个m x n网格的左上角

* 机器人每次只能向下或者向右移动一步，机器人试图达到网格的右下角。

* 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

* 网格中的障碍物和空位置分别用1和0来表示。
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int uniquePathsWithObstacles(const vector<vector<int>>& obstacleGrid) 
{
    auto temp_matrix = obstacleGrid;
    int row = temp_matrix.size();
    int col = temp_matrix[0].size();
    if (temp_matrix[0][0] == 1 || temp_matrix[row - 1][col - 1] == 1)   return 0;
    for (int i = 0; i < col; i++)
    {
        if (temp_matrix[0][i] != 1) temp_matrix[0][i] = 1;
        else    // 等于1代表遇到了障碍物
        {
            for(int j = i; j < col; j++)    temp_matrix[0][j] = 0;
            break;
        }
    }

    for (int i = 1; i < row; i++)
    {
        if (temp_matrix[i][0] != 1) temp_matrix[i][0] = 1;
        else
        {
            for(int j = i; j < row; j++)    temp_matrix[j][0] = 0;
            break;
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (temp_matrix[i][j] != 1)
            {
                temp_matrix[i][j] = temp_matrix[i][j - 1] + temp_matrix[i - 1][j];
            }
            else temp_matrix[i][j] = 0;
        }
        
    }
    
    return temp_matrix[row - 1][col - 1];
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

    cout << uniquePathsWithObstacles(input) << endl;
    
}