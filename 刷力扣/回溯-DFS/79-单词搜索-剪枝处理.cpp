/*
题目：
- 给定一个m x n二维字符网格board和一个字符串单词word。
- 如果word存在于网格中，返回true；否则，返回false。

规则：
- 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
- 同一个单元格内的字母不允许被重复使用。

思路：
- 剪枝处理的思路是，先获取起始点，如果该初始点路不通，那显然没有再回溯下去的必要了；
- 再有就是在回溯中要将已经回溯过的点临时标记一下，以免重复计算
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;
bool result = false;

// 分别对应上下左右四个方向
int row_orient[4] = {-1, 1, 0, 0};
int col_orient[4] = {0, 0, -1, 1};


void backtrace(vector<vector<char>>& board, const string& word, int i, int j, int index)
{
    int row = board.size();
    int col = board[0].size();

    if (index == word.size() - 1)
    {
        result = true;
        return;
    }
    for (int k = 0; k < 4; k++) // 四个方向
    {
        int new_row = i + row_orient[k];
        int new_col = j + col_orient[k];

        // 下面这个if保证了只有存在符合要求的条件才会去递归
        if(new_row >= 0 && new_row < row && new_col >= 0 && new_col < col &&
            board[new_row][new_col] != '0' && board[new_row][new_col] == word[index + 1])
            {
                char temp = board[i][j];
                board[i][j] = '0';
                backtrace(board, word, new_row, new_col, index + 1);
                board[i][j] = temp;
                if (result) return;
            }
    }
}

bool exist(vector<vector<char>>& board, const string& word)
{
    int row = board.size();
    int col = board[0].size();
    if (word.size() > row * col)    return false;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (board[i][j] == word[0])
            {
                backtrace(board, word, i, j, 0);
            }
            if (result) return true;
        }
    }    
    return false;
}

int main()
{
    input input79;
    auto char_matrix = input79.input_char_matrix();

    string word;

    cin >> word;

    cout << boolalpha << exist(char_matrix, word) << endl;
    
    return 0;
}