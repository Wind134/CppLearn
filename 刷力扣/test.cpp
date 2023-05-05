// 找出无重复字符的最长字串，我们先找出无重复字符的字串，再来比较长度
// 如何找出无重复字符的字串呢？
// 遍历string，想办法列出string字串

// 上述过程是自己思考的结果，确实算不上什么比较好的思路
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;        // 这种写法慎用，默认选取了std的命名空间(cpp源文件可以用，无妨)

int lengthOfLongestSubstring(const string &s) {
        vector<int> m(128, 0);      // 128个ASCII码默认全部赋0，字母与数字一一对应

        int ans = 0;

        int i = 0;

        for (int j = 0; j < s.size(); j++) {
            i = max(i, m[s[j]]);
            m[s[j]] = j + 1;    // 当前位置加1，更新字母的位置信息
            ans = max(ans, j - i + 1);
        }

        return ans;
    }

int main()
{
    string s;
    cin >> s;
    int length = lengthOfLongestSubstring(s);
    // cout << length << endl;
    return 0;
}
