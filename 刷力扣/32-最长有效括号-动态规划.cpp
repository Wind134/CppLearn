/* 
 * 给定一个只包含'('和')'的字符串，找出最长有效括号子串的长度；
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 以下是动态规划的思想：以dp[i]表示下标i字符结尾的最长有效括号的长度，首先将dp数组全部初始化为0；
 * 有效的字串一定以')'结尾，我们只需要求解')'在dp数组中对应位置的值，同时以'('结尾的子串一定不符合"最长有效括号"的规则
 * 因此针对两种情况考虑：
 * - s[i] == ')'而s[i - 1] == '('，也就是字符串形如："....()"，此时的动态规划方程：dp[i] = dp[i - 2] + 2
 * - s[i] == ')'而s[i - 1] == ')'，也就是形如"....))"，此时的动态规划方程：首先是考虑dp[i - 1]，这里的最长
 * 有效长度肯定是dp[i]的一部分，我们将该子串看成sub_s，如果说s足够长，那我们必须考虑i - dp[i - 1]的情况，这里又需要考虑两种：
 * - 索引值i - dp[i - 1] - 1是否是'('，如果是，那么dp[i]至少又可以新增2个长度：dp[i] = dp[i - 1] + 2，此时再往前推：
 * - 索引值i - dp[i - 1] - 2的最长有效子串情况，当然，需要满足i - dp[i - 1] - 2>=0，因此综合来说就是：
 * - dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int longestValidParentheses(string s) 
{
    int dp[s.size()] = {0,};    // 动态规划数组
    int maxlength = 0;

    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')    dp[i] = (i >=2 ? dp[i - 2] : 0) + 2;
            else if (i - dp[i - 1] >= 1 && s[i - dp[i - 1] - 1] == '(') dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2 >= 0) ? 
                    dp[i - dp[i - 1] - 2] : 0) + 2;
        }
        maxlength = maxlength > dp[i] ? maxlength : dp[i];
    }

    return maxlength;
}

int main()
{
    string str;
    cin >> str;
    cout << longestValidParentheses(str) << endl;
    return 0;
}