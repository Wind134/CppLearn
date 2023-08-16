/**
题目：
- 丑数就是只包含质因数2、3 和 5的正整数。
- 给你一个整数n，请你判断n是否为丑数。如果是，返回true；否则，返回false。

思路：递归
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool isUgly(int n) {
    if (n == 1) return true;
    if (n % 2 && n % 3 && n % 5)    return false;
    if (!(n % 2)) {
        bool res = isUgly(n / 2);
        if (!res)   return false;
    }
    if (!(n % 3)) {
        bool res = isUgly(n / 3);
        if (!res)   return false;
    }
    if (!(n % 5)) {
        bool res = isUgly(n / 5);
        if (!res)   return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cout << boolalpha << isUgly(n) << endl;

    return 0;
}
