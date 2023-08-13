/**
题目：
- 给你一个大小为m x n的二进制矩阵grid。
- 岛屿是由一些相邻的1(代表土地)构成的组合，这里的「相邻」要求两个1必须在水平或者竖直的四个方向上相邻。
- 你可以假设 grid 的四个边缘都被 0（代表水）包围着。
- 岛屿的面积是岛上值为1的单元格的数目。
- 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为0。

思路：DFS深度搜索，是一个简化版的图
- 当遇到一个1，表明这边就是一个岛，然后判断1的周边；
- 周边有四个方向，上、下、左、右；
- 只要周边有1个方块是1，我们就要沿着这个方块去不断判断；
- 相当于就是沿着四个方向不断去做搜索；
- 为了避免重复的DFS，我们将每个访问过的点都进行修改，由于需要获取岛屿大小，因此我们可以修改为2，代表访问过；
- 这样不断判断下去到最后，就能搜索完所有连在一起的1；
- 然后针对每个岛屿的面积求大小
*/

#include "../headfile/io_for_leetcode.h"
using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int& s) {
    int row = grid.size();
    int col = grid[0].size();

    // (i, j)是一个点，我们要访问且访问过，将该点置为0；
    ++s;
    grid[i][j] = 0;
    if (i - 1 >= 0 && grid[i - 1][j])    dfs(grid, i - 1, j, s);    // 上
    if (i + 1 < row && grid[i + 1][j])  dfs(grid, i + 1, j, s);    // 下
    if (j - 1 >= 0 && grid[i][j - 1])    dfs(grid, i, j - 1, s);    // 左
    if (j + 1 < col && grid[i][j + 1])  dfs(grid, i, j + 1, s);    // 右
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if(grid.empty())    return 0;
    int res = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j]) {
                int first_s = 0;
                dfs(grid, i, j, first_s);
                res = max(res, first_s);
            }
        }
        
    }

    return res;
}

int main() {
    input input695;
    auto input_matrix = input695.input_matrix();

    cout << maxAreaOfIsland(input_matrix) << endl;

    return 0;
}