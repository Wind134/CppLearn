/**
题目：
- 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
- 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
- 举例：
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
- 像这种情况，岛屿数量为1，比较显然；
- 我们假设这个矩阵周围所围绕的都是水；

思路：DFS深度搜索，是一个简化版的图
- 当遇到一个1，表明这边就是一个岛，然后判断1的周边；
- 周边有四个方向，上、下、左、右；
- 只要周边有1个方块是1，我们就要沿着这个方块去不断判断；
- 相当于就是沿着四个方向不断去做搜索；
- 为了避免重复的DFS，我们将每个访问过的点都进行修改，可以修改为0或者2；
- 这样不断判断下去到最后，就能搜索完所有连在一起的1；

*/

#include "../headfile/io_for_leetcode.h"
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    int row = grid.size();
    int col = grid[0].size();

    // (i, j)是一个点，我们要访问且访问过，将该点置为0；
    grid[i][j] = '0';
    if (i - 1 >= 0 && grid[i - 1][j] == '1')    dfs(grid, i - 1, j);    // 上
    if (i + 1 < row && grid[i + 1][j] == '1')  dfs(grid, i + 1, j);    // 下
    if (j - 1 >= 0 && grid[i][j - 1] == '1')    dfs(grid, i, j - 1);    // 左
    if (j + 1 < col && grid[i][j + 1] == '1')  dfs(grid, i, j + 1);    // 右
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.empty())    return 0;
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1') {
                ++res;
                dfs(grid, i, j);
            }
        }
        
    }

    return res;
}

int main() {
    input input200;
    auto input_matrix = input200.input_char_matrix();

    cout << numIslands(input_matrix) << endl;

    return 0;
}