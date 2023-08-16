/*
题目：
- 给你一个整数n，请你找出并返回第n个丑数。
- 丑数就是只包含质因数2、3和/或5的正整数。

思路：
- 丑数本身不能是除(2 3 5)以外的质数

- 这道题没有思路，看了官解：
- 设置三个指针p_2 p_3 p_5，分别指向质因数为2 3 5的丑数，由于1比较特殊，三个指针的起始位置都放在第一个
- 设定的动态规划数组dp_array[i]表示第i个丑数，为了对应，设定动态规划数组大小为(n + 1)，dp_array[i]表示第i个丑数
- dp[1] = 1;
- dp[2] = min(dp[p_2] * 2, dp[p_3] * 3, dp[p_5] * 5)
- 假设选定的是p_i，那么p_i指针前移1位，可以保证的是i >= p_i，因为只有在dp_array[i]更新之后，才能更新新的指针
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int nthUglyNumber(int n) {
    if (n == 1) return 1;

    vector<int> dp_array(n + 1);

    dp_array[1] = 1;
    int p_2 = 1, p_3 = 1, p_5 = 1;
    for (int i = 2; i <= n; i++) {
        dp_array[i] = min(min(dp_array[p_2] * 2, dp_array[p_3] * 3), dp_array[p_5] * 5);
        if (dp_array[i] == dp_array[p_2] * 2)  p_2++;
        if (dp_array[i] == dp_array[p_3] * 3)  p_3++;
        if (dp_array[i] == dp_array[p_5] * 5)  p_5++;
    }

    return dp_array[n];
}

int main() {
    int seq;
    cin >> seq;
    cout << nthUglyNumber(seq) << endl;

    return 0;
}