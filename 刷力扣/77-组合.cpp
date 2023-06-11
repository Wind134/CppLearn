/* 
* 给定两个整数n和k，返回范围[1, n]中所有可能的k个数的组合
* 典型的回溯问题：
* 对于当前某个index的位置，加入它或者不加入它，就这两种情况；
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> elem_of_result;

void backtrace(int begin, int n, int k)
{
    if (n - begin + 1 < k)   return;
    if (k == 0)
    {
        result.push_back(elem_of_result);
        return;
    }
    

    backtrace(begin + 1, n, k);

    elem_of_result.push_back(begin);
    backtrace(begin + 1, n, k - 1);
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
    for (const auto& vector : result)
    {
        for (auto& num : vector)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}