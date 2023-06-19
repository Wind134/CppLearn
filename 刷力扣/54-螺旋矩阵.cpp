/* 
* 给你一个m行n列的矩阵matrix，请按照顺时针螺旋顺序，返回矩阵中的所有元素。

* 思路，贼简单，先列增长，再行增长，遇到访问过的，代表某一个方向已经访问完成

* 由于题目要求顺时针，因此首先变化的是列，列到底了，说明一行已经访问完了

* 列数增加，行数增加，列数减少，行数减少，一轮执行完毕，新的一轮又是

* 列数增加....
*/
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> spiralOrder(const vector<vector<int>>& matrix) 
{
    vector<int> result;

    if (matrix.empty() || matrix[0].empty())
    {
        return result; 
    }
    
    int row_tag = matrix.size();    // 记录行数
    int col_tag = matrix[0].size(); // 记录列数

    int row = matrix.size();    // 记录真实行数
    int col = matrix[0].size(); // 记录真实列数

    int row_count_up = 0;   // 上方的行减少的数量
    int row_count_down = 0; // 下方的行减少的数量
    int col_count_left = 0; // 左边的列减少的数量
    int col_count_right = 0;// 右边的列减少的数量

    
    while(true)
    {
        for(int i = col_count_left; i < col - col_count_right; i++)
        {
            result.push_back(matrix[row_count_up][i]);
        }
        row_tag--;
        row_count_up++;
        if (!row_tag)   break;
        
        for(int i = row_count_up; i < row - row_count_down; i++)
        {
            result.push_back(matrix[i][col - col_count_right - 1]);
        }
        col_tag--;
        col_count_right++;
        if (!col_tag)   break;

        for (int i = col - col_count_right - 1; i >= col_count_left; i--)
        {
            result.push_back(matrix[row - row_count_down - 1][i]);
        }
        row_tag--;
        row_count_down++;
        if (!row_tag)   break;

        for(int i = row - row_count_down - 1; i >= row_count_up; i--)
        {
            result.push_back(matrix[i][col_count_left]);
        }
        col_tag--;
        col_count_left++;
        
        if (!col_tag)   break;
    }

    return result;
}

int main()
{
    vector<vector<int>> input;

    string line;    // 获取一行的输入

    while(getline(cin, line))
    {
        if (line == "q" || line == "Q")
        {
            cout << "End Of Input!\n";
            break;
        }

        vector<int> elem_of_input;

        int vector_elem;

        istringstream inputstream(line);    // 将每一行绑定到stream流类型的对象
        while (inputstream >> vector_elem)  // 从每行中提取字符
        {
            elem_of_input.push_back(vector_elem);
        }

        input.push_back(elem_of_input);
    }

    for(auto& elem : input)
    {
        for(auto data : elem)   cout << data << " ";
        cout << endl;
    }

    auto output = spiralOrder(input);

    for(auto& data : output) cout << data << " ";

    return 0;
}