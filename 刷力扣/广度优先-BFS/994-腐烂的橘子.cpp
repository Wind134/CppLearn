/**
 * 题目：
 * 在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：
 * - 值0代表空单元格；
 * - 值1代表新鲜橘子；
 * - 值2代表腐烂的橘子；
 * 每分钟，腐烂的橘子周围4个方向上相邻的新鲜橘子都会腐烂。
 * 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回-1。
 * 
 * 提示：
 * - m == grid.length
 * - n == grid[i].length
 * - 1 <= m, n <= 10
 * - grid[i][j]仅为0、1或2
 * 
 * 思路：广度优先
 * 每次都将周围四个方向上的新鲜橘子看作同一层；
 * 处理完同一层之后处理下一层，直到最后处理完毕；
 * 但在此之前，我们需要将本身已经腐烂的橘子先入队，他们是最开始的一层；
 * 而后才再去处理其他层；
 * 每当一个新鲜橘子腐烂，就将新鲜橘子的数目减1；
 * 处理到最后一层处理完之后，如果新鲜橘子没了；
 * 则返回层数(分钟数)；
 * 否则返回-1；
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty())   return -1;
    int row = grid.size(), col = grid[0].size();

    int res = 0;

    // 分别对应四个方向，上下左右，参照矩阵坐标系
    int direct_row[4] = {-1, 1, 0, 0};
    int direct_col[4] = {0, 0, -1, 1};

    queue<pair<int, int>> orange_point;

    int count = 0;  // 存储好橘子的数量
    
    vector<vector<int>> times(row, vector<int>(col));   // 默认初始化为0，存储每个好橘子腐烂的时间
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == 2)
            {
                orange_point.push(make_pair(i, j)); // 坏橘子统一入队
            }
            if (grid[i][j] == 1)
            {
                ++count;
            }
        }
    }

    while (!orange_point.empty())
    {
        auto front_point = orange_point.front();
        orange_point.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_row = front_point.first + direct_row[i];
            int new_col = front_point.second + direct_col[i];
            if (new_row >= 0 && new_row < row && new_col >= 0 && new_col < col && grid[new_row][new_col] == 1)
            {
                times[new_row][new_col] = times[front_point.first][front_point.second] + 1;
                grid[new_row][new_col] = 2;
                orange_point.push(make_pair(new_row, new_col));
                --count;
                res = times[new_row][new_col];
                if (count == 0) break;
            }
        }
    }
    
    return count ? -1 : res;
}

int main() {
    input input994;
    auto input_matrix = input994.input_matrix();

    cout << orangesRotting(input_matrix) << endl;

    return 0;
}