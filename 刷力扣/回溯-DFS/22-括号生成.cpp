/*
题目：
- 数字n代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。

思路：回溯
数字n代表生成括号的对数，设计一个函数，用于能够生成所有可能的并且有效的括号组合。
观察规律，我们可以知道的是，当我们遍历到一个位置的时候，余下位置的左括号一定小于等于右括号
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> res;

void dfs(const string& str, int left, int right)    // left与right分别是左右括号的数目
{
    if(left == 0 && right == 0) // 两者同时为0，说明左括号右括号刚好都用完了
    {
        res.push_back(str);
        return;
    }

    // 看到这里可能回想，为什么不直接设定条件为left < right呢？因为left是先插进去的，我们起码要
    // 等待后续')'的使用再说，也就是说这里存在不确定性
    // 而等到left小于0，'('都用完了，我们又再用了一次这个符号，显然，不可能匹配，因此可以直接返回
    // 至于left > right就刚好是另一种情况了，这种情况我们不用讨论，因为在dfs里')'是后用的，用了之后
    // 我们可以直接判断left与right的关系，用完之后如果存在这种关系，直接就可以判定不可能
    if (left < 0 || left > right)
    {
        return;
    }
    dfs(str + '(', left - 1, right);
    dfs(str + ')', left, right - 1);
}

vector<string> generateParenthesis(int n)   // 给定了括号对数，我们遍历所有，符合要求的添加进入
{
    dfs("", n, n);  // 初始时给定的左右括号个数是相等的
    return res;
}



int main()
{
    int n;
    cin >> n;
    vector<string> result = generateParenthesis(n);
    for(const auto& element : result)   cout << element << " ";
    return 0;
}