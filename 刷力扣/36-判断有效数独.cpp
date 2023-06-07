/* 
 * 请你判断一个 9 x 9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
 * 数字1-9在每一行只能出现一次。
 * 数字1-9在每一列只能出现一次。
 * 数字1-9在每一个以粗实线分隔的3x3宫内只能出现一次。
 * 思路：借助一个外标记数组是否可行？
 * 具体思路：借助三个外标记数组，二维行数组记录每一行每个数字出现的次数
 * 二维列数组记录每一列数组的每个数字出现的次数
 * 三维数组记录每一个小九宫格每个数字出现的次数
*/
#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) 
{
    int rows[9][9];
    int cols[9][9];
    int subboxes[3][3][9];

    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    memset(subboxes, 0, sizeof(subboxes));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                int index = board[i][j] - '0' - 1;
                rows[i][index] ++;
                cols[j][index] ++;
                subboxes[i / 3][j / 3][index]++;
                if (rows[i][index] > 1 || cols[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1) 
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> input;
    vector<char> row;
    char info;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> info;
            row.push_back(info);
        }
        input.push_back(row);
    }
    cout << boolalpha << isValidSudoku(input) << endl;
}