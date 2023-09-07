/**
 * 题目：
 * 给你一个整数n，返回和为n的完全平方数的最少数量。
 * 完全平方数是一个整数，其值等于另一个整数的平方；
 * 换句话说，其值等于一个整数自乘的积。例如，1、4、9和16都是完全平方数，而3和11不是。
 * 
 * 思路：考虑动态规划做法
 * 假设dp_array[i]是数i满足条件的完全平方数的最少数量。
 * 那么dp_array[j]则取决于j - i是否是完全平方数。因此动态规划的转移方程：
 * dp_array[j] = dp_array[i] + 1     j - i是完全平方数
 * 
 * 显然，dp_array[1] = 1，同时设置动态规划数组的长为(n + 1)，使之与上面的假设完全对应；
 * 同时，我们会认为0也是完全平方数
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

// bool isSquare(int num) {
//     int temp = sqrt(num);
//     return temp * temp == num;
// }


int numSquares(int n) {
    vector<int> dp_array(n + 1);
    for (int i = 1; i <= n; ++i) {
        int minN = INT_MAX;
        for (int k = 1; k * k <= i; ++k) {
            minN = min(minN, dp_array[i - k * k]);
        }
        dp_array[i] = minN + 1;
    }

    return dp_array[n];
}

int main() {
    int n;
    cin >> n;

    cout << numSquares(n) << endl;

    return 0;
}