/*
题目：
- 给你两个单词word1和word2，请返回将word1转换成word2所使用的最少操作数。

- 你可以对一个单词进行如下三种操作：
- 插入一个字符
- 删除一个字符
- 替换一个字符

思路：设定一个动态规划矩阵dp_matrix[m][n]，m为word1的大小，n为word2的大小
- 那么dp_matrix[i][j]的含义应该是：word1开始(0)到第i个位置，匹配word2开始(0)到第j个位置，成功转换所使用的最少操作次数

- 如果word1[i] == word2[j]，那显然dp_matrix[i][j]所代表的次数取决于dp_matrix[i - 1][j - 1]

- 如果word1[i] != word2[j]，我们分几部分考虑：
    -- word1开始到第i - 1个位置，已经匹配到word2开始到第j个位置(dp_matrix[i - 1][j])，这种情况，删除word1[i]这个位置即可
    -- word1开始到第i - 1个位置，已经匹配到word2开始到第j - 1个位置((dp_matrix[i - 1][j - 1]))，这种情况，替换word1[i]这个位置的元素为word[j]即可
    -- word1开始到第i个位置，已经匹配到word2开始到第j - 1个位置((dp_matrix[i][j - 1]))，这种情况，在word1[i]这个位置后插入相应元素即可
    -- 显然，通过这个递推式，可以看出，初始值需要特殊处理
    -- dp_matrix的第一行，word1字符为空，空字符，到word[j]个位置，这个值显然，dp_matrix[0][j] = j，word1不断插入;
    -- dp_matrix的第一列，word1开始(0)到第i个位置转化到空字符所需的最小次数，那么dp_matrix[i][0] = i，word1不断删除;

*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int s1 = word1.size(), s2 = word2.size();
    vector<vector<int>> dp_matrix(s1 + 1, vector<int>(s2 + 1)); // 设定矩阵
    for (int j = 0; j < s2 + 1; j++)    dp_matrix[0][j] = j; 
    for (int i = 0; i < s1 + 1; i++)    dp_matrix[i][0] = i;

    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            if (word1[i - 1] == word2[j - 1])   dp_matrix[i][j] = dp_matrix[i - 1][j - 1];
            else dp_matrix[i][j] = min(min(dp_matrix[i - 1][j - 1], dp_matrix[i][j - 1]), dp_matrix[i - 1][j]) + 1;
        }
    }

    return dp_matrix[s1][s2];
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    cout << minDistance(str1, str2) << endl;

    return 0;
}