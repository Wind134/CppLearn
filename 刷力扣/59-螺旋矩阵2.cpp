/* 
* 给你一个正整数n ，生成一个包含1到n^2所有元素，且元素按顺时针顺序螺旋排列的nxn正方形矩阵matrix。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> result(n, vector<int>(n));  // 初始化了一个矩阵matrix

    int row_up = 0;
    int row_down = 0;
    int col_left = 0;
    int col_right = 0;

    int init_value = 1;

    while (true)
    {
        for (int i = col_left; i < n - col_right; i++)
        {
            result[row_up][i] = init_value;
            init_value++;
        }
        row_up++;
        if(init_value == n * n + 1) break;
        
        for (int i = row_up; i < n - row_down; i++)
        {
            result[i][n - col_right - 1] = init_value;
            init_value++;
        }
        col_right++;
        if(init_value == n * n + 1) break;
        
        for (int i = n - col_right - 1; i >= col_left; i--)
        {
            result[n - 1 - row_down][i] = init_value;
            init_value++;
        }
        row_down++;
        if(init_value == n * n + 1) break;
        
        for (int i = n - row_down - 1; i >= row_up; i--)
        {
            result[i][col_left] = init_value;
            init_value++;
        }
        col_left++;
        if(init_value == n * n + 1) break;        
    }

    return result;
    
}

int main()
{
    int input_num;

    cin >> input_num;

    auto output = generateMatrix(input_num);

    for(const auto& vec : output)
    {
        for (auto elem : vec)   cout << elem << " ";
        cout << endl;
    }

    return 0;
}