/* 
* 给定一个m x n二维字符网格board和一个字符串单词word。
* 如果word存在于网格中，返回true；否则，返回false。

* 规则：单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
* 同一个单元格内的字母不允许被重复使用。

* 思路：有点像走迷宫，只是不再是走到最后一个点，而是能走完一个字符串word的长度
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


void backtrace(const vector<vector<char>>& board, string word, int index, vector<vector<bool>>& tag)
{

    int row = board.size();
    int col = board[0].size();

    if (word.size() > row * col)
    {
        result = false;
        return;
    }


    if (index == word.size() - 1 && word.size() != 1)
    {
        result = true;
        return;
    }

    for (int i = 0; i < row && result == false; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(!tag[i][j] && board[i][j] == word[index])
            {
                if (word.size() == 1)
                {
                    result = true;
                    return;
                }
                tag[i][j] = true;

                for (int k = 0; k < 4; k++)
                {
                    int next_row = i + row_orient[k];
                    int next_col = j + col_orient[k];
                    if (isValid(board, next_row, next_col, tag) && index + 1 < word.size() && 
                    board[next_row][next_col] == word[index + 1] && result == false)
                    {
                        backtrace(board, word, index + 1, tag);
                    }
                        
                }
                tag[i][j] = false;     
            }
        }  
    }
    
}

bool exist(const vector<vector<char>>& board, string word)
{
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> tag_matrix(row, vector<bool>(col, false));
    backtrace(board, word, 0, tag_matrix);
    return result;
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