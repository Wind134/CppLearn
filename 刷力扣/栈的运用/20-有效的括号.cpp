/*
题目：
- 给定一个只包括'('，')'，'{'，'}'，'['，']'的字符串s，判断字符串是否有效。

有效字符串需满足：
- 左括号必须用相同类型的右括号闭合。
- 左括号必须以正确的顺序闭合。
- 每个右括号都有一个对应的相同类型的左括号。

思路：堆栈
- 左括号入栈，碰到对应的右括号就出栈
*/

#include "../headfile/io_for_leetcode.h"
#include <stack>
using namespace std;

bool isValid(const string& s)
{
    stack<char> brackStack;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            brackStack.push(s[i]);
        }
        else   if (!brackStack.empty())
        {
            if ((brackStack.top() == '(' && s[i] == ')')
                || (brackStack.top() == '{' && s[i] == '}')
                || (brackStack.top() == '[' && s[i] == ']')) brackStack.pop();
            else return false; 
        }
        else
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')  return false;
        }
    }
    return brackStack.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
}