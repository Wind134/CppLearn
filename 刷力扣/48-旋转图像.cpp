/*
* 给定一个n × n的二维矩阵matrix表示一个图像。请你将图像顺时针旋转90度。
* 要求必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
* 附注：最后的结果就像是顺时针翻转了90度
* 观察矩阵信息，可以很明显的看到规律：第一行的数组变成了最后一列的数组、第二行的数组变成了倒数第二列的数组
* 那么，也就是第n行的数组变成了倒数第n列的数组，如果允许再创造一个矩阵，将会很容易写出代码，但题目要求原地修改
* 那我们只能尝试绕圈的思路，每一圈看成一个循环数组来处理，关注每个角，任何矩阵都只有四个角，因此我们建立一个数组
* 来保留这四个角的元素
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int size = matrix.size();
    int k = 0;
    auto tempArray = vector<int>(4);
    while (k < size / 2)
    {
        int matrix_size = size - k * 2;
        for(int i = 0; i < matrix_size - 1; i++)
        {
            // 永远都是四个角，这一点肯定没错
            tempArray[0] = matrix[k][k + i];
            tempArray[1] = matrix[k + i][k + matrix_size - 1];
            tempArray[2] = matrix[k + matrix_size - 1][k + matrix_size - 1 - i];
            tempArray[3] = matrix[k + matrix_size - 1 - i][k];
            matrix[k + i][k + matrix_size - 1] = tempArray[0];
            matrix[k + matrix_size - 1][k + matrix_size - 1 - i] = tempArray[1];
            matrix[k + matrix_size - 1 - i][k] = tempArray[2];
            matrix[k][k + i] = tempArray[3];
        }
        k++;
    }   
}

void testInput(const vector<vector<int>>& input)
{
    for(const auto& array : input)
    {
        for(auto value : array)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> inputMatrix;
    vector<int> row;
    int info;
    while (cin >> info)
    {
        row.push_back(info);
        if (cin.get() == '\n')  break;
    }
    inputMatrix.push_back(row);

    int size = row.size();
    while (inputMatrix.size() < size)
    {
        for (int i = 0; i < size; i++)
        {
            cin >> row[i];
        }
        inputMatrix.push_back(row);
    }

    cout << "The following is your input: \n";
    testInput(inputMatrix);

    rotate(inputMatrix);

    testInput(inputMatrix);
    
    return 0;
}