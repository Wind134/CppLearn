/* 
* 给定一个m x n的矩阵，如果一个元素为0，则将其所在行和列的所有元素都设为0。请使用原地算法。
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    // 初始标记位
    bool row_tag[row] = {false};
    bool col_tag[col] = {false};

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                row_tag[i] = true;
                col_tag[j] = true;
            }      
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (row_tag[i] || col_tag[j])
            {
                matrix[i][j] = 0;
            }      
        }
    }
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

    setZeroes(input);

    for(const auto& vec : input)
    {
        for(auto elem : vec)    cout << elem << " ";
        cout << endl;
    }
    
    return 0;
}