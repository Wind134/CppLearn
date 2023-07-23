/*
题目：
- 给你一个字符串s、一个字符串t。
- 返回s中涵盖t所有字符的最小子串。如果s中不存在涵盖t所有字符的子串，则返回空字符串"" 。

注意：
- 对于t中重复字符，我们寻找的子字符串中该字符数量必须不少于t中该字符数量。
- 如果s中存在这样的子串，我们保证它是唯一的答案。

思考：
- 在此前的思考中，考虑到了滑动窗口解决问题，但是没有思考到精髓部分，参考了题解，献上自己的思考
- 首先用一个map去处理子串t，将字符与每个字符出现的次数映射起来
- 其次维护一个滑动的窗口，该窗口内的所有内容也用map去存储，但是这个过程是动态的，因为窗口本身会不断的进行移动；
- 检查窗口内的子串存在情况，如果不存在，我们不断拓展子串的右边界，如果存在，我们为了获得更小的区间，会去不断拓展左边界
- 拓展左边界的一点前提是，如果窗口长度已经等于我们要找的子串的长度，显然我们可以直接返回结果
- 如果不是，那就等到窗口拓展到最后字符的时候，返回我们在这个过程中的最小值即可

- 思路大致如此，接下来上代码
*/
#include "../headfile/io_for_leetcode.h"
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

bool check(const map<char, int>& m1, map<char, int>& m2) {    // m1是通过子串生成的map
    for (const auto& elem : m1) {
        if (m2[elem.first] < elem.second)   return false;   // 这一行代码隐藏一个细节问题，如果elem.first的key不存在，会增加，因此不能const
    }

    return true;
}


string minWindow(string s, string t) {
    if (t.size() > s.size())    return "";
    int left = 0, right = -1;
    int real_left = -1;
    int length = INT_MAX;
    map<char, int> t_times, window_times;
    for_each(t.begin(), t.end(), [&t_times](char c) { ++t_times[c]; });  // 将t中字符分发进map
    
    while (right < (int)s.size()) {
        if (t_times.find(s[++right]) != t_times.end())   ++window_times[s[right]];  // right已经自增了
        else {
            if (window_times.empty())   left = right + 1;
        }
        

        while (check(t_times, window_times) && left <= right)   // 如果满足，我们就尝试不断拓展左边界
        {
            if (right - left + 1 == t.size())   return s.substr(left, t.size());    // 等于子串长，那我们就直接返回相应子串，不需要继续迭代
            else {
                if (right - left + 1 < length) {
                    length = right - left + 1;
                    real_left = left;
                }
            }

            if (t_times.find(s[left]) != t_times.end()) --window_times[s[left]];
            left++;
        }
    }

    return real_left == -1 ? "" : s.substr(real_left, length);

}

int main() {
    string str, substr;
    cin >> str >> substr;

    cout << minWindow(str, substr) << endl;
}