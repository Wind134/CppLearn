// 我们找字符串中所有回文串的字符
// 更长则更新
   /*  for (int i = 0; i < n; i++)              //这个做法有一个很大的问题就是在i=0时，需要知道i等于1、2、3等情况的状态
    {
        for (int j = i + 1; j < n; j++)
        {
 
            if (j - i == 1)     // 考虑相邻的情况
            {
                if(dp[i][j])
                {
                    maxLen = max(maxLen, 2);
                    if (maxLen <= 2)
                        substring = s.substr(i, 2);
                }
                else
                {
                    maxLen = max(maxLen, 1);
                    if (maxLen <= 1)
                        substring = s.substr(i, 1);
                }
            }
            else
            {
                dp[i][j] = (dp[i + 1][j - 1]&&s[i] == s[j]);      // 这边得到了递推公式
                if (dp[i][j])
                {
                    maxLen = max(maxLen, j - i + 1);
                    cout << maxLen << endl;
                    substring = s.substr(i, maxLen);
                }
            }
        }
    } 
    */
//以上是有问题而废弃的思路，接下来的思路尝试使用中心扩散
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> saveBoundary(const string &s, int left, int right)   // 扩散左右边界
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        left--; // 向左扩散
        right++;    // 向右扩散
    }
    //直到遇到不满足上述条件的情形：到了边界或者不再是回文串
    return {left + 1, right - 1};
}

// 上述函数所保存的应该是字符串的每个元素所能扩散的最大的范围

// 通过动态规划部分的分析，我们知道需要针对字符串长度1和2进行特殊处理

string longestPalindrome(const string &s) 
{
    int start = 0, end = 0;                // 这部分需要不断的更新，根据扩散的范围长度去不断更新
    for (int i = 0; i < s.length(); i++) // 以字符串的每个元素为中心进行扩散
    {
        auto left1 = saveBoundary(s, i, i)[0], right1 = saveBoundary(s, i, i)[1];        // 考虑字符串长度为1的情况
        auto left2 = saveBoundary(s, i, i + 1)[0], right2 = saveBoundary(s, i, i + 1)[1];        // 考虑字符串长度为1的情况

        /* auto left1 = saveBoundary(s, i, i).first, right1 = saveBoundary(s, i, i).second;
        auto left2 = saveBoundary(s, i, i + 1).first, right2 = saveBoundary(s, i, i + 1).second; */

        if(right1 - left1 > end - start)
        {
            // 更新首尾
            start = left1;
            end = right1;
        }
        if(right2 - left2 > end - start)
        {
            // 更新首尾
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}
int main()
{
    /* string s("abab");
    bool tag = isPalindrome(s);
    cout << tag << endl; */
    string s = "ababa";
    cout << longestPalindrome(s) << endl;
}
