/*
- 给你两个字符串s和t，统计并返回能出现t的s的子序列个数。
- 题目数据保证答案符合32位带符号整数范围。

注意：
    -- 只要在主串中出现的先后顺序没问题，就是合法的子串
    -- 假设s为rabbbit，t为rabbit;
    -- rabb it与rabbit与rab bit都是合法的；

思路：
回溯暴力会导致超时，因此尝试使用动态规划，我们假设一个矩阵dp_matrix[s][t]，且矩阵dp_matrix[i][j]表示
- s[i:...]的子序列中t[j:...]出现的个数，寻找动态规划矩阵往往是最关键的一个步骤；
- 我们最终需要返回的，就是dp_matrix[1][1]，也就是从主串和子串的第一个位置开始能匹配到结尾的个数

- 假设我们考虑子串第t，即t[t:...]个位置，也就是等于t长度的字符串位置，相当于空字符，那么空字符肯定属于主串字符的一个子串
- 且这种子串针对s中任意的开始字符，有且只有一个

- 然后讨论递推关系式：首先要明白的一点是，是从后往前做推导的；
- 如果s[s] = t[t]，表明第t个位置开始能匹配，那么这个位置的个数要分两种情况：
    -- 我选择匹配这个位置，此时，匹配的子序列个数：dp_matrix[s + 1][t + 1]
    -- 我不匹配这个位置（因为存在这种可能），此时匹配的子序列个数：dp_matrix[s + 1][t]，即从s + 1开始匹配
    -- 这两种情况的方法数，都需要加上去，dp_matrix[s][t] = dp_matrix[s + 1][t + 1] + dp_matrix[s + 1][t]；
- 如果s[s] ！= t[t]，那么只能从s + 1开始匹配，此时子序列个数dp_matrix[s + 1][t]
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


int numDistinct(string s, string t) {
    int size1 = s.size(), size2 = t.size();
    vector<vector<int>> dp_matrix(size1 + 1, vector<int>(size2 + 1, 0));    // 多定义一个大小
    for (int i = 0; i <= size1; i++) {
        dp_matrix[i][size2] = 1;
    }
    for (int i = size1 - 1; i >= 0; i--)
    {
        for (int j = size2 - 1; j >= 0; j--)
        {
            if (s[i] == t[j])    dp_matrix[i][j] = dp_matrix[i + 1][j] + dp_matrix[i + 1][j + 1];
            else dp_matrix[i][j] = dp_matrix[i + 1][j];
        }
    }
    output test;
    test.output_matrix(dp_matrix);

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