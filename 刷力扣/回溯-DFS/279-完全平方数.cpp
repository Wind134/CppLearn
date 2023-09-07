/**
 * 题目：
 * 给你一个整数n，返回和为n的完全平方数的最少数量。
 * 完全平方数是一个整数，其值等于另一个整数的平方；
 * 换句话说，其值等于一个整数自乘的积。例如，1、4、9和16都是完全平方数，而3和11不是。
 * 
 * 思路：
 * 最直接的思路就是生成1~n之间的数的平方值，然后用多数之和的方法来解决这个问题
 * 能解决这个问题，但是即便很努力的去剪枝了还是超时
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;
vector<int> square_num;
int res = INT_MAX;

vector<int> res_vec;

void backtrace(const vector<int>& v, int target, int index) {
    if (target == 0) {
        res = min(res, (int)res_vec.size());
        // for_each(res_vec.begin(), res_vec.end(), [](int n) { cout << n << " "; });
        // cout << endl;
        return;
    }

    for (size_t i = index; i < v.size() && res_vec.size() + 1 < res; i++)
    {
        if (target - v[i] < 0)  continue;
        res_vec.push_back(v[i]);
        backtrace(v, target - v[i], i);
        res_vec.pop_back();
    }
    
}

int numSquares(int n) {
    for (int i = 1; i * i <= n; ++i) {
        square_num.push_back(i * i);
    }
    sort(square_num.rbegin(), square_num.rend());
    backtrace(square_num, n, 0);

    return res;
}


int main() {
    int n;
    cin >> n;

    cout << numSquares(n) << endl;

    return 0;
}