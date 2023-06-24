/* 
* 给定一个m x n二维字符网格board和一个字符串单词word。
* 如果word存在于网格中，返回true；否则，返回false。

* 规则：单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
* 同一个单元格内的字母不允许被重复使用。

* 思路：剪枝处理的思路是，先获取起始点，如果该初始点路不通，再寻找下一个初始点
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool result = false;

// 分别对应上下左右四个方向
int row_orient[4] = {-1, 1, 0, 0};
int col_orient[4] = {0, 0, -1, 1};

// 判断有效点
bool isValid(const vector<vector<char>>& board, int i, int j, const vector<vector<bool>>& tag)
{
    int row = board.size();
    int col = board[0].size();
    return (i >= 0 && i < row && j >= 0 && j < col && !tag[i][j]);
}


void backtrace(const vector<vector<char>>& board, const string& word, int i, int j, int index, vector<vector<bool>>& tag)
{
    int row = board.size();
    int col = board[0].size();

    if (index == word.size() - 1)
    {
        result = true;
        return;
    }

    if (word.size() > row * col)
    {
        result = false;
        return;
    }

    for (int k = 0; k < 4; k++)
    {
        int new_row = i + row_orient[k];
        int new_col = j + col_orient[k];

        // 下面这个if保证了只有存在符合要求的条件才会去递归
        if(isValid(board, new_row, new_col, tag) && board[new_row][new_col] == word[index + 1])
        {
            tag[new_row][new_col] = true;
            backtrace(board, word, new_row, new_col, index + 1, tag);
            tag[new_row][new_col] = false;
        }
    }
}

bool exist(const vector<vector<char>>& board, const string& word)
{
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> tag_matrix(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == word[0])
            {
                tag_matrix[i][j] = true;
                backtrace(board, word, i, j, 0, tag_matrix);
                tag_matrix[i][j] = false;
            }
            if (result) return true;
        }
    }    
    return false;
}

int main()
{
    int m, n;
    string word;

    cout << "Please input the m & n & word: ";
    cin >> m >> n >> word;

    cin.get();
    string line;

    char input_data;

    vector<vector<char>> input;

    while (m != 0 && getline(cin, line))
    {
        istringstream iss(line);    // istringstream对象可以提取输入行中的相应类型
        
        vector<char> vec_of_input;
        
        while (iss >> input_data)
        {
            vec_of_input.push_back(input_data);
        }

        input.push_back(vec_of_input);
        m--;   
    }

    cout << boolalpha << exist(input, word) << endl;
    
    return 0;
}