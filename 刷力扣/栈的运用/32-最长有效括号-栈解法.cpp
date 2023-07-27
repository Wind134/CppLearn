/* 
 * 给定一个只包含'('和')'的字符串，找出最长有效括号子串的长度；
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 自行尝试过一个思路，但未能奏效，以下代码为更正后的思路，具体分为两步：
 * 对于每个遇到的'('，我们将下标放入栈中；
 * 对于每个遇到的')'，我们弹出栈顶元素，表明括号匹配
 * - 此时如果栈为空，说明当前的')'为没有被匹配的')'，我们将下标放入栈中来更新"最后一个没有被匹配的右括号下标"
 * - 若栈非空，当前右括号的下标减去(弹出后的)栈顶元素即为"以该右括号为结尾的最长有效括号的长度"
 * - 此外还需要考虑一开始栈为空，第一个字符为左括号的特殊情况，此时会与上述的第二种情况相悖，因为这样最终要减的栈顶元素并不存在(都弹出完了)
 * 此种特殊情况可以通过在栈种加入-1的索引解决；
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s) 
{
    if (s.size() == 0)  return 0;
    stack<int> braceIndex;      // 仅存储左括号索引的栈

    braceIndex.push(-1);

    int index = 0, length = 0;
    while (index < s.size())
    {
        if (s[index] == '(')
        {
            braceIndex.push(index);
        }    
        if (s[index] == ')')
        {
            if (braceIndex.size() == 1)  braceIndex.push(index); 
            else
            {
                if (s[braceIndex.top()] == '(')
                {
                    braceIndex.pop();
                    length = (length > index - braceIndex.top()) ? length : index - braceIndex.top();
                }
                else    braceIndex.push(index);
            }
        }
        index++;
    }
    return length;
}

int main()
{
    string str;
    cin >> str;
    cout << longestValidParentheses(str) << endl;
    return 0;
}