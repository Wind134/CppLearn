/*
题目：
- 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
- n皇后问题研究的是如何将n个皇后放置在n×n的棋盘上，并且使皇后彼此之间不能相互攻击。
- 给你一个整数n，返回所有不同的n皇后问题的解决方案。
- 每一种解法包含一个不同的n皇后问题的棋子放置方案，该方案中'Q'和'.'分别代表了皇后和空位。


思路：DFS回溯
- 针对矩阵棋盘的每一行a[i]，我们假设"皇后"放在某一行的第j列，即a[i][j] = 'Q'，那么a[i][0]...a[j-1]a[j+1]...a[n - 1]
- 那么针对下一行a[i + 1]，我们需要思考，皇后能放在哪，显然a[i + 1][j]不能放，a[i + 1][j - 1]、a[i + 1][j + 1]都不能放
- 针对这么一个限制条件，我们设计一个函数去检测即可
- 什么时候返回我们的结果呢，当处理到矩阵的最后一行时，返回我们符合条件的结果
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<string>> result;

// 由于我们是从上行往下添加的，因为我们只需要关注上行的情况即可，这里也可以看出来，check函数得与回溯搭配使用
bool check(const vector<string>& matrix, int i, int j)
{
    int size = matrix.size();

    // 判断同一行的左半部分(显然右半部分不用管)，因为判断顺序是从左到右
    for(int k = 0; k < j; k++)  if(matrix[i][k] == 'Q')  return false;

    // 判断同列的上半部分(下半部分显然先不用管)，因为判断顺序是从上到下
    for(int k = 0; k < i; k++)  if(matrix[k][j] == 'Q') return false;

    // 这是一个辅助变量，用来判断对角部分
    int step = 1;

    // 判断左对角
    while(i - step >= 0 && j - step >= 0)
    {
        if (matrix[i - step][j - step] == 'Q')    return false;
        step++;
    }

    // 判断右对角
    step = 1;

    while(i - step >= 0 && j + step < size)
    {
        if (matrix[i - step][j + step] == 'Q')    return false;
        step++;
    }

    return true;
}

void backtrace(vector<string>& matrix, int i)
{
    int count = 0;
    for(int j = 0; j < matrix.size(); j++)
    {
        if(check(matrix, i, j)) // 如果检查之后可以放，就将相应位置置为Q
        {
            count = 1;
            matrix[i][j] = 'Q';
            // cout << "进入了判断语句: "<< matrix[i] << endl;
            if (i + 1 == matrix.size()) // 结束了，加入结果集
            {
                result.push_back(matrix);
            } 
            else backtrace(matrix, i + 1);  // 否则处理下一行
            matrix[i][j] = '.'; // 恢复原状，判断右边那个，在判断以前，左边先归原位
        }
    }
    if (count == 0 || i == matrix.size()) return;   // 遇到不通过的或者判断完最后一行仍然不满足条件的，直接返回
}


vector<vector<string>> solveNQueens(int n)
{
    auto char_matrix = vector<string> (n, string(n, '.'));   // 全初始化为'.'，在合理，合规的地方改成Q
    backtrace(char_matrix, 0);
    return result;
}

int main()
{
    int n;
    cin >> n;

    auto output_res = solveNQueens(n);

    for (const auto& elem : output_res)     // 特殊情况的IO处理就不调库了
    {
        for (auto& elem_elem : elem)    cout << elem_elem << endl;

        cout << "--------------" << endl;
    }

    return 0;
}