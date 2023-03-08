#include <iostream>
using namespace std;

int F(int n, int depth)
{
    for (size_t i = 0; i < 4 * depth - 4; i++)
    {
        cout << " ";
    }
    cout <<"n = " << n << endl;       // 打印当前执行F函数时的深度
    if (n <= 2) return 1;
    else
    {
        return F(n - 1, depth + 1) + F(n - 2, depth + 1);
    }
}

int main ()
{
    int n;
    cin >> n;
    F(n, 1);    // 深度从1开始算
    return 0;
}