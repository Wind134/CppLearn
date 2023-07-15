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

-- 滚动数组的选择，是选列数组还是行数组
-- 我们观察之前动态规划的特点，逐列向左走，逐行向上走的
-- 如果我们选择嵌套两层循环，那么第一层循环可以从后往前先不断更新一维数组的值
-- 更新完成之后，再在前面的循环中模拟向上走的流程
-- 因为我们选择行数组，即数组大小设置为t + 1
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


int numDistinct(string s, string t) {
    int size1 = s.size(), size2 = t.size();
    if (size1 < size2)  return 0;

    // 整个数组的初始值全为0，然后在后续的循环中处理
    vector<int> dp_array(size2 + 1, 0);

    // 仿照之前二维数组的步骤，我们从最后一个开始
    // i的起始值不重要，因为最外层的循环就是为了表现次数
    for (int i = size1 - 1; i >= 0; i--)
    {
        // 先更新数组中最后一个的值，一定是1，相当于选中子序列为空字符
        dp_array[size2] = 1;
        auto temp_array = dp_array; // 临时存储经过上一轮处理后的值
        for (int j = size2 - 1; j >= 0; j--)
        {
            if (s[i] == t[j])    dp_array[j] = temp_array[j] +  temp_array[j + 1];
            else dp_array[j] = temp_array[j];
            
            // else范围省略即可
        }
    }

    return dp_array[0];
}

int main()
{
    string str, substr;

    cout << "Input the str and substr: ";
    
    cin >> str >> substr;

    cout << numDistinct(str, substr) << endl;

    return 0;
}