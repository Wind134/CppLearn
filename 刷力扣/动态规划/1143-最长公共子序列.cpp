/**
 * 题目：
 * 给定两个字符串text1和text2，返回这两个字符串的最长公共子序列的长度。如果不存在公共子序列，返回0。
 * 一个字符串的子序列是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下(删除某些字符也可以不删除任何字符)后组成的新字符串。
 * 
 * 例如：
 * "ace"是"abcde"的子序列，但"aec"不是"abcde"的子序列。
 * 两个字符串的公共子序列 是这两个字符串所共同拥有的子序列。
 * 
 * 
 * 思路：动态规划
 * 我们假设dp[i][j]是字符串1的[0....i]子串和字符串2的[0.....j]子串的最长公共子序列
 * 
 * 那么显然：dp[i + 1][j + 1]在s1[i + 1]==s2[j + 1]的情况下，应该是dp[i][j] + 1的长度
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int row = text1.size();
    int col = text2.size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1));

    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[row][col];
}

int main() {
    string str1;
    string str2;
    cin >> str1 >> str2;

    cout << longestCommonSubsequence(str1, str2) << endl;

    return 0;
}