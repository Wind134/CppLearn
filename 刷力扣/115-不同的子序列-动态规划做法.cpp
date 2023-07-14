/*
- 给你两个字符串s和t，统计并返回在s的子序列中t出现的个数。
- 题目数据保证答案符合32位带符号整数范围。

注意：
    -- 只要在主串中出现的先后顺序没问题，就是合法的子串

回溯暴力会导致超时，因此尝试使用递归，我们假设一个矩阵dp_matrix[s][t]
- 从主串的第s个位置，子串的第t个位置开始，到子串结尾，能匹配的子串(序列)个数
- 我们最终需要返回的，就是dp_matrix[1][1]，也就是从主串和子串的第一个位置开始能匹配到结尾的个数

- 假设我们考虑第t个位置，也就是超过t长度的字符串位置，相当于空字符，那么空字符肯定属于主串字符的一个子串

然后讨论递推关系式：
如果s[s] = t[t]，表明第t个位置开始能匹配，那么这个位置的个数要分两种情况：
- 我选择匹配这个位置，此时，匹配的子序列个数： dp_matrix[s + 1][t + 1]
- 我不匹配这个位置（因为存在这种可能），此时匹配的子序列个数：dp_matrix[s + 1][t]，即从s + 1开始匹配
如果s[s] ！= t[t]，那么只能从s + 1开始匹配，此时子序列个数dp_matrix[s + 1][t]

// ....以此类推

初始值s[s.size()][t.size()] = 1;    // 这个表示的就是空字符与空字符，它就是匹配的
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


int numDistinct(string s, string t) {
    int size1 = s.size(), size2 = t.size();
    vector<vector<int>> dp_matrix(size1 + 1, vector<int>(size2 + 1, 0));
    dp_matrix[size1][size2] = 1;
    for (int i = size1 - 1; i >= 0; i--)
    {
        for (int j = size2 - 1; j >= 0; j--)
        {
            if (s[i] == t[j])    dp_matrix[i][j] = dp_matrix[i + 1][j] + dp_matrix[i + 1][j + 1];
            else dp_matrix[i][j] = dp_matrix[i + 1][j];
        }
    }

    return dp_matrix[0][0];
}

int main()
{
    string str, substr;

    cout << "Input the str and substr: ";
    
    cin >> str >> substr;

    cout << numDistinct(str, substr) << endl;

    return 0;
}