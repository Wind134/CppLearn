/* 数塔就是由一堆数字组成的塔状结构，其中第一行1个数，第二行2个数，第三行3个数，依此类推。
每个数都与下一层的左下与右下两个数相连接。这样从塔顶到塔底就可以有很多条路径可以走，现在需要
求路径上的数字之和的最大值。 
首先解决输入问题，有规律可循，用一个数组处理即可
表达成数学形式即为：第i行的下标为i(i - 1)/2，且第i行的数有i个
-------------------------------------------------------
在思考的过程中发现一个数组不太好定位索引，因此还是决定使用二维数组

此外还有一个比较巧妙之处是，返回值是从底部往上返回的，这个方法特别巧妙
*/

#include <iostream>
#include <algorithm>
using namespace std;


const int numsMax = 21;    // 考虑到下标与之差1
int a[numsMax][numsMax], n;     // n代表的是行数信息

int getMax(int i, int j)        // 对于每个下标索引为(i, j)的数组
{
    if (i == n) return a[n][j];  // 如果到了最后一行，直接就返回最后一行的每个数
    else    // 要不然就
    {
        return max(getMax(i + 1, j), getMax(i + 1, j + 1)) + a[i][j];
    }
}

int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << getMax(1, 1) << endl;
}