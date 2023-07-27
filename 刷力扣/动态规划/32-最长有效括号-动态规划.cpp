/*
题目：
- 给定一个只包含'('和')'的字符串，找出最长有效括号子串的长度；
- 输入：s = ")()())"
- 输出：4
- 解释：最长有效括号子串是 "()()"

做法：动态规划
- 以dp[i]表示若下标对应字符为')'，它属于最长有效括号的情况下，它的长度，因此首先将dp数组全部初始化为0；
- 首先需要明确的一点是：但凡是有效的括号，他们一定是簇拥在一个区域，这个原则很重要，基于这个原则去讨论问题；
- 已确认下标i对应的字符是')'，显然，需要讨论前一个字符的可能：
    -- 如果s[i - 1] == '('，也就是字符串形如："....()"，此时的动态规划方程：dp[i] = dp[i - 2] + 2；
    -- 如果s[i - 1] == ')'，也就是形如"....))"，此时的动态规划方程又需要做诸多考虑：
        --- 我们假设dp[i - 1]有一个长度，由于这是一个右括号，那么显然这个长度范围内所有的括号字符也需要分两种情况讨论：
            --- 这个右括号是被匹配了的，形如"))))())"，此时i这个位置到底能不能匹配取决于s[i - dp[i - 1] - 1]是否是'('：
            --- 是否被匹配，如果沿用上述的动态规划数组的设定，显然不合理，因此动态规划数组需要更新定义
                ---- 如果是，则 dp[i] = dp[i - dp[i - 1] - 1] + 2, 还需要加上dp[i - 1）(细节，因为前面的那部分并没有算上，索引下标需要 >= 0)
                ---- 如果不是，dp[i] = dp[i - 1];
            --- 这个右括号没有被匹配，形如"))()))", 显然仍然是dp[i] = 0，由于是0，相当于不用考虑(因为已初始化)；
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) 
{
    vector<int> dp_array(s.size(), 0);

    int maxLen = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ')')    // 只有此种情况需要考虑
        {
            if (s[i - 1] == '(') {
                dp_array[i] = ((i >= 2) ? dp_array[i - 2] : 0) + 2;
            }
            else if (i - dp_array[i - 1] >= 1 && s[i - dp_array[i - 1] - 1] == '(') {
                dp_array[i] = dp_array[i - 1] + ((i - dp_array[i - 1] - 2 >= 0) ? dp_array[i - dp_array[i - 1] - 2] : 0) + 2;
            }

            maxLen = max(maxLen, dp_array[i]);
        }
    }
    return maxLen;
}

int main()
{
    string str;
    cin >> str;
    cout << longestValidParentheses(str) << endl;
    return 0;
}