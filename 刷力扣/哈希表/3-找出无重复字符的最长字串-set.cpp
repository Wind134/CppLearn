/*
思路：
同样是哈希映射，但这个做法相比数组更好理解
*/
#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;        // 这种写法慎用，默认选取了std的命名空间(cpp源文件可以用，无妨)

int lengthOfLongestSubstring(const string &s) {
        if (s.size() == 0)  return 0;
        unordered_set<char> char_set;
        int maxLong = 0;                            // 初始化最大长度
        int left = 0;                               // 左端字符
        for(int i = 0; i < s.size(); i++)           // 这是起始移动的字符
        {
            while (char_set.find(s[i]) != char_set.end())  // 如果某个值找到了，说明有重复，不能用了
            {
                char_set.erase(s[left]);
                left++;
            }
            maxLong = max(maxLong, i - left + 1);
            char_set.insert(s[i]);
        }
        return maxLong;
    }

int main()
{
    string s;
    cin >> s;
   // s = " ";
    int length = lengthOfLongestSubstring(s);
    cout << length << endl;
    return 0;
}
