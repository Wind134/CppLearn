/* 数字n代表生成括号的对数，设计一个函数，用于能够生成所有可能的并且有效的括号组合。
观察规律，我们可以知道的是，当我们遍历到一个位置的时候，余下位置的左括号一定小于等于右括号
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void dfs(const string& str, int left, int right, vector<string>& res)    // left与right分别是左右括号的数目
{
    if(left == 0 && right == 0) // 两者同时为0，说明左括号右括号刚好都用完了
    {
        res.push_back(str);
        return;
    }
    if (left < 0 || left > right)
    {
        return;
    }
    dfs(str + '(', left - 1, right, res);
    dfs(str + ')', left, right - 1, res);
}

vector<string> generateParenthesis(int n)   // 给定了括号对数，我们遍历所有，符合要求的添加进入
{
    vector<string> result;
    dfs("", n, n, result);
    return result;
}



int main()
{
    int n;
    cin >> n;
    vector<string> result = generateParenthesis(n);
    for(const auto& element : result)   cout << element << " ";
    return 0;
}