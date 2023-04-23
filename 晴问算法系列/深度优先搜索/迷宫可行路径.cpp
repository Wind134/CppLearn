/* 现有一个n * m大小的迷宫，其中1表示不可通过的墙壁，0表示平地。
每次移动只能向上下左右移动一格（不允许移动到曾经经过的位置），且只能移动到平地上。
求从迷宫左上角到右下角的所有可行路径的条数。 */
#include <iostream>
#include <vector>
using namespace std;

int rows, lines;
int count = 0;
vector<vector<int>> vec(rows, vector<int>(lines));    // 定义一个迷宫数组
vector<int> x_orient = {0, 0, -1, 1};   // 上、下、左、右移动x坐标的变化情况
vector<int> y_orient = {1, -1, 0, 0};   // 协同上、下、左、右移动y坐标的变化情况

bool isValid(const int& x, const int& y, const vector<vector<int>>& v,
    const vector<vector<int>>& visited)  // 有效的访问点
{
    return (x >= 0 && x < rows && y >= 0 &&
    y < lines && !visited[x][y] && v[x][y] == 0);
}

void DFSMaze(const int& x, const int&y, vector<vector<int>>& visited)
{
    if (x == rows - 1 && y == rows - 1)
    {
        count ++;
        return;
    }
    visited[x][y] = 1;   // 访问了[x][y]，更改标志
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + x_orient[i];
        int nextY = y + y_orient[i];
        if (isValid(nextX, nextY, vec, visited))
        {
            DFSMaze(nextX, nextY, visited);
        }    
    }
    visited[x][y] = 0;  // 这一轮走完了，为了准备下一轮继续归零
}

int main()
{
    cin >> rows >> lines;
    vec = vector<vector<int>>(rows, vector<int>(lines));      // 重赋值
    vector<vector<int>> visited(rows, vector<int>(lines));    // 定义数组确认某点是否访问过
    int data;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < lines; j++)
        {
            cin >> data;
            vec[i][j] = data;
        }    
    }
    DFSMaze(0, 0, visited);
    cout << count << endl;
}