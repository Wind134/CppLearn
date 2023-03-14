/* 两个集合S(n个正整数)、T(m个正整数)，分别从两个集合取两个数，满足：
a<=b，不放回，最多可进行多少次这样的操作？

思路：由于是集合，因此可以确定没有重复数字，题目中要求最多，那么
对于集合S而言，如果我找出一个最大的，看看T中有没有符合要求的，没有
那么集合S就往前走一个，有的话那集合S和T一起往前走一个 */
#include <iostream>
#include <algorithm>
using namespace std;

const int MaxNum = 100000;
int S[MaxNum], T[MaxNum];

int main()
{
    int count = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> T[j];
    }
    sort(S, S + n);
    sort(T, T + m);
    int i = n - 1, j = m - 1;
    while (i >=0 && j >=0)
    {
        if(S[i] > T[j]) i--;
        else
        {
            count++;
            i--;
            j--;
        } 
    }
    cout << count << endl;
    return 0;   
}