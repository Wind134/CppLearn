/* 
题目：
- 给定两个整数n和k，返回范围[1, n]中所有可能的k个数的组合

思路：典型的回溯问题：
- 对于当前某个index的位置，加入它或者不加入它，就这两种情况；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<vector<int>> result;
vector<int> elem_of_result;

void backtrace(int begin, int n, int k)
{
    if (n - begin + 1 < k)   return;    // 不可能组成k个数了，返回
    if (k == 0)
    {
        result.push_back(elem_of_result);
        return;
    }
    

    backtrace(begin + 1, n, k); // 不加入这个数

    elem_of_result.push_back(begin);
    backtrace(begin + 1, n, k - 1); // 加入这个数
    elem_of_result.pop_back();
}

vector<vector<int>> combine(int n, int k) 
{
    backtrace(1, n, k);
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;

    auto result = combine(n, k);
    output output77;
    output77.output_matrix(result);

    return 0;
}