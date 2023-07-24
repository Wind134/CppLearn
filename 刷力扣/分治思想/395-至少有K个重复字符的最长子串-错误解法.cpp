/*
题目：
- 给你一个字符串s和一个整数k，请你找出s中的最长子串，要求该子串中的每一字符出现次数都不少于k。
- 返回这一子串的长度。
- 如果不存在这样的子字符串，则返回0。


思路：设置两个map，一个记录每个字符出现的次数，一个记录每个字符对应的索引下标
- 对于主串s，设定初始索引为size - 1，这样在处理字符的时候，可以确保记录的是最早出现的那个索引(这样好像效果不大，步骤舍弃)
- 记录每个字符出现次数的map是必要的，这是后续判断的依据
- 其后通过滑动窗口的思想解决问题，窗口的两个指针初始都在0的位置，右指针向右移动，直到遇到不符合要求的字符，此时记录长度
- 更新新的窗口，就是说，将left指针与right指针移动到该字符的下一个位置，由于不符合要求的字符可能有多个
- 我们需要对map进行一定处理，出现次数小于k的全都要留下，其余的erase
*/
#include "../headfile/io_for_leetcode.h"
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool check(const unordered_map<char, int>& m, int k) {
    for (const auto& elem : m) {
        if (elem.second < k)    return false;
    }
    
    return true;
}

int longestSubstring(string s, int k) {
    unordered_map<char, int> char_int, window_char_int;

    for (char& c : s) char_int[c]++;

    // // for_each(char_int.begin(), char_int.end(), [&char_int](auto elem) { if (elem.second < k) char_int.erase(elem); })
    for (auto it = char_int.begin(); it != char_int.end();) {
        if (it->second >= k) it = char_int.erase(it);
        else ++it;
    }

    // for_each(char_int.begin(), char_int.end(), [&char_int](auto elem) { cout << elem.first << " "; });

    int res = 0;
    int left = 0, right = 0;
    int size = s.size();
    while (right < size) {
        if (char_int.find(s[right]) == char_int.end()) {    // 只要是可能符合规定的字符，尽可能延长区间值
            ++window_char_int[s[right++]];
        } 
        if (char_int.find(s[right]) != char_int.end() || right == size) {   
            if (check(window_char_int, k)) {    // 判断区间是否符合要求，符合则更新长度，否则继续判断下一个区间
                res = max(res, right - left);
            }
            right++;
            left = right;
            window_char_int.erase(window_char_int.begin(), window_char_int.end());
        }
    }

    return res;
}

int main() {
    cout << "Please input s && k: ";
    string str;
    int val;
    cin >> str >> val;
    cout << longestSubstring(str, val) << endl;

    return 0;
}