/* 这是一个递归结合动态规划的问题，比较有启发价值
对于对n级台阶而言，上层台阶的办法数会等于：
f(n) = f(n - 1) + f(n - 2)
即上两层台阶的方法加上上一层台阶的方法！
 */

#include <iostream>
using namespace std;

int upStairs(int n)
{
    if (n == 1) return 1;
    else if ( n == 2)   return 2;
    else    return upStairs(n - 1) + upStairs(n - 2);
}

int main ()
{
    int n;
    cin >> n;
    cout << upStairs(n) << endl;
    return 0;
}