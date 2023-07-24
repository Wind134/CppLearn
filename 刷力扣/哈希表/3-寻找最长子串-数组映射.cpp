/*
题目：
- 给定一个字符串s，请你找出其中不含有重复字符的最长子串的长度。

思路：这个问题的处理思路还是哈希表；
- 在对字符串中信息迭代时，同时维护哈希表，每去到一个新的窗口，哈希表都需要重新更新
- 需要思考的一点是，真的需要全部更新吗？
- 假设某字符出现的次数大于等于2次，那么下一个起始的位置是不是必须要大于或等于字符出现的次数呢？

-- 以abcabcbb为例，在一轮迭代的过程中，我们需要明确的是，保存在哈希表中的值是什么呢？
-- 是每个字符出现的下一个位置的索引，为什么需要保存下一个呢，假设我们先前保存了某个字符的下一个索引；
-- 然后我们随着迭代的进行，迭代到上面第二个a，这个时候right的位置是在a这个位置，left是不是得动动，因为a出现过了
-- 那么这个即将需要更新的位置就应该是第一个a的下一个位置；
-- 这个时候可能会想，那如果我遇到的是b呢，不是abca，而是abcb，在遇到第二个b之前，第一个b的索引位置是不是已经被记录了；
-- 那么起点同样会更新，因此，可以看出，这种处理方式，遇到任何一个相同的字符都会进行更新，窗口长也在这个过程中被不断的延申到最大
-- 最后，随着迭代器终止，返回我们需要的长度

-- 核心思想就是在迭代的过程中看到两个相同的就准备更新窗口，所以也有些类似滑动窗口的思想，随着每一次迭代的进行不断更新窗口长
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(const string &s) {
    vector<int> hash(128, 0);      // 128个ASCII码默认全部赋0，字母与数字一一对应

    int ans = 0;
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
        left = max(left, hash[s[right]]);   // max保证不会退回之前发生过的重复值的所在位置
        hash[s[right]] = right + 1;         // 当前位置加1，更新字母的位置信息
        ans = max(ans, right - left + 1);   // left与right分别是窗口的左右两端
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;
    int length = lengthOfLongestSubstring(s);
    cout << length << endl;
    return 0;
}
