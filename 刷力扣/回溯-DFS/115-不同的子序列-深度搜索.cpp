/*
- 给你两个字符串s和t，统计并返回在s的子序列中t出现的个数。
- 题目数据保证答案符合32位带符号整数范围。

注意：
    -- 只要在主串中出现的先后顺序没问题，就是合法的子串

思路：
- 步骤是对了，就是最后还是超时了；
- 解决起来应该也不难，记忆化搜索，不必重新递归；   
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int result = 0;

void dfs(const string& str, const string& substr, int index1, int index2)
{
    if (str.size() - index1 < substr.size() - index2)   return;
    if (index2 == substr.size()) {
        result++;
        return;
    }
    if (index1 == str.size())   return;

    if (str[index1] == substr[index2])  // 当前字符匹配的情况下
    {
        dfs(str, substr, index1 + 1, index2 + 1);   // 接受这个匹配的字符，去判断下一个

        dfs(str, substr, index1 + 1, index2);       // 不接受这个匹配的字符
    }
    else    // 如果当前字符不匹配，那只能去匹配下一个
        dfs(str, substr, index1 + 1, index2);
}

    int numDistinct(string s, string t) {
        dfs(s, t, 0, 0);

        return result;
    }

int main()
{
    string str, substr;

    cout << "Input the str and substr: ";
    
    cin >> str >> substr;

    cout << numDistinct(str, substr) << endl;

    return 0;
}