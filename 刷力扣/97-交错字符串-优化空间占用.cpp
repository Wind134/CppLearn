/* 
给定三个字符串s1、s2、s3，请你帮忙验证s3是否是由s1和s2交错组成的。

两个字符串s和t交错的定义与过程如下，其中每个字符串都会被分割成若干非空子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1——————表明差值范围在1以内
交错是s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。

采用动态规划的思路，这道题本身确实是很巧妙：
- 我们假设f(i, j)为s1的前i个元素是否能与s2的前j个元素交错成s3的前(i + j)个元素；
- 到底能不能，取决于两个因素：f(i - 1, j)与f(i, j - 1)
    -- 考虑f(i - 1, j): 如果f(i - 1, j)为true，且s1[i - 1] = s3[i + j - 1]，则f(i, j)为true
    -- 考虑f(i, j - 1): 如果f(i, j - 1)为true，且s2[j - 1] = s3[i + j - 1]，则f(i, j)为true

初始值：f(0, 0)设置为true   

我们将dp_array设定为一维数组，而后减少空间占用的
思路很直接，在s1每遍历一个字母时，更新整个dp_array
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3)
{
    int size1 = s1.size(), size2 = s2.size(), size3 = s3.size();    // 保存三个字符串大小
    if (size1 + size2 != size3) return false;

    vector<bool> dp_array(size2 + 1, false);
    dp_array[0] = true;  // 初始值，s1的前0个字母与s2的前0个字母默认可以组合成一个新的s3
    for (int i = 0; i <= size1; i++)
    {
        for (int j = 0; j <= size2; j++)
        {
            // 由于变成了一维数组，因此之前更新行的部分需要特殊逻辑处理一下，在i的第一轮循环中，下面这行不会执行
            // 也没必要执行，只需要参考j的变化去不断更新即可
            if (i > 0)  dp_array[j] = (s1[i - 1] == s3[i + j - 1]) && dp_array[j];  // 与之前的集合相&

            if (j > 0)  dp_array[j] = (dp_array[j - 1] && s2[j - 1] == s3[i + j - 1]) || dp_array[j];
        }
    }
    
    return dp_array[size2];
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << boolalpha << isInterleave(s1, s2, s3) << endl;
    return 0;
}