/* 
你有足够的长度分别为1,2,3,……,n的长条积木，你有多少种搭出高度为h的上升三角塔（每个积木横着放，高度都为1）
输入为n，h，代表积木块数和高度h
输出方法数：
动态规划递推公式：
ways[h][i] = ways[h - 1][i] + ways[h - 1][i + 1] + .... + height[h - 1][n]
*/
#include <iostream>
using namespace std;

const int H = 40;
const int N = 40;
int height[H][N];

int main()
{
    int n, h;
    while (cin >> n >> h)
    {
        for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ( i==1 ) height[i][j] = 1;   // 第一层的数目给定了
            else
            {
                for (int k = j; k <=n; k++)
                {
                    height[i][j] += height[i - 1][k];
                }
            }
            
        }
    }
    int sum = 0;
    for (int i = 1; i <=n; i++)
    {
        sum += height[h][i];
    }
    cout << sum << endl;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <=n; j++)
            height[i][j] = 0;
    }
    }
    return 0;
}