/**
题目：
- 丑数就是只包含质因数2、3 和 5的正整数。
- 给你一个整数n，请你判断n是否为丑数。如果是，返回true；否则，返回false。

思路：迭代
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool isUgly(int n) {
    if (n <= 0) return false;
    vector<int> factors = {2, 3, 5};
    for (int factor : factors) {
        while (n % factor == 0) {
            n /= factor;
        }
    }
    return n == 1;
}

int main() {
    int n;
    cin >> n;
    cout << boolalpha << isUgly(n) << endl;

    return 0;
}
