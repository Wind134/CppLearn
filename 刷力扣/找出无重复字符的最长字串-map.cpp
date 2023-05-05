// 找出无重复字符的最长字串，我们先找出无重复字符的字串，再来比较长度
// 如何找出无重复字符的字串呢？
// 遍历string，想办法列出string字串

// 上述过程是自己思考的结果，确实算不上什么比较好的思路
#include <iostream>
#include <unordered_map>

using namespace std;        // 这种写法慎用，默认选取了std的命名空间(cpp源文件可以用，无妨)

int lengthOfLongestSubstring(const string &s) {
        unordered_map<char, int> char_map;          // 用来选取无重复的字符，在map中这些都是保证无重复的
        int ans = 0;                                // 我们需要的最大字符，首先默认为0
        int left = 0;                               // 左端字符
        for(size_t i = 0; i < s.size(); i++)       // 这是起始移动的字符
        {
            if (char_map.find(s[i]) == char_map.end())  // 如果某个值没找到
            {
                char_map[s[i]] = i;                     // 建立映射
            }
            else                                        // 如果某个值找到了，那么
            {
                left = (left > (char_map[s[i]] + 1)) ? left : (char_map[s[i]] + 1);                  // 那么更新左端值，这一步可能出问题
                char_map[s[i]] = i;     // 更新映射
            }
            ans = (i - left + 1 > ans) ? (i - left + 1) : ans;  // 只有更大才会更新，否则不动
            //for (auto it = occ.begin(); it != occ.end(); it++)    cout << *it << endl;    // 打印测试
        }
        return ans;
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
