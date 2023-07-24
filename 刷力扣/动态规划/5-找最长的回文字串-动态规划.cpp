/*
题目：
- 给你一个字符串s，找到s中最长的回文子串。
- 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

做法：针对每个字符串做中心扩散，方法复杂度应该不低
- 考虑通过动态规划优化，我们设定一个dp矩阵dp_matrix[i][j]，其中的值表明的是s[i]~s[j]的子串是否是回文串；
- 显然dp_matrix[i][i]是true，同时，若s[i] == s[j]且dp_matrix[i + 1][j - 1]是true，则dp_matrix[i][j]为true；
- 针对大小为1的子串是dp_matrix[i][i]，针对大小为2的子串是dp_matrix[i][j](j - i == 1)，这是判断所有子串的基础串；
- 由递推关系式可以知道，我们想要去更新所有的动态规划矩阵，需要从最后一行开始向上遍历，因为所有的值更新都需要知道下一行中前一列的值；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

string longestPalindrome(const string &s) 
{
    int size = s.size();
    vector<vector<bool>> dp_matrix(size, vector<bool>(size, false));
    int len = 1, begin_index = 0;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = i; j < size; j++) {
            if (j == i) dp_matrix[i][j] = true;
            else if (j - i == 1) {
                if (s[j] == s[i]) {
                    dp_matrix[i][j] = true;
                    if (len < 2) {
                        begin_index = i;
                        len = 2;
                    }
                }   
            }
            else // 子串大于2的情况
            {
                if (dp_matrix[i + 1][j - 1] && s[i] == s[j]) {
                    dp_matrix[i][j] = true;
                    if (len < j - i + 1) {
                        begin_index = i;
                        len = j - i + 1;
                    }
                }
            }   
        }
    }
    // cout << begin_index << " " << len << endl; 
    // cout << s.substr(begin_index, len) << endl;

    return s.substr(begin_index, len);
}
int main()
{
    string str;
    cin >> str;
    cout << longestPalindrome(str) << endl;

    return 0;
}