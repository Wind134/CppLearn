/* 汉诺塔是一个典型的递归问题，以A、B、C三根柱子为例：
把n个圆盘从A->C的方法=把上面n-1个圆盘从A->B的方法 + 1 + 把B上n - 1个圆盘从移动->C的方法
其中从B->C也等价于从A->C也等价于从A->B，因此数学递推公式可以写成：
f(n) = 2f(n - 1) + 1
----------------------------------------------
但是这道题不仅仅是需要我们求可以移动的次数，并非一个简单的动态规划问题
还需要我们指明详细的运动轨迹，这才是设计递归的难点
根据上面的递推公式，可以得到：移动次数= 2 ^ n - 1。n代表了圆盘的个数
*/
#include <iostream>
#include <cmath>
using namespace std;

void moveWays(int n, char A, char B, char C)
{
    if (n == 0) return; // 当没有圆盘时，啥也不干！
    else
    {
        moveWays(n - 1, A, C, B);   // 我 n - 1个先想办法到B，此时运用递归记得变换顺序，因为相对位置变了
        cout << A << "->" << C << endl;     // 移动最后一个到C
        moveWays(n - 1, B, A, C);   // 移动B柱上的n-1个圆盘
    }  
}

int main ()
{
    int n;
    cin >> n;
    int times = pow(2, n) - 1 ;
    cout << times << endl;
    moveWays(n, 'A', 'B', 'C');
    return 0;
}