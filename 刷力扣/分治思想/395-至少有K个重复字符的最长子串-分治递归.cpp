/*
题目：
- 给你一个字符串s和一个整数k，请你找出s中的最长子串，要求该子串中的每一字符出现次数都不少于k。
- 返回这一子串的长度。
- 如果不存在这样的子字符串，则返回0。


思路：设置一个哈希表，哈希表记录的是字符串中每个字符出现的次数(由于是26个字母，选择数组和map均可)
- ******c****c****，先假设这么一个字符，我们假定k需要出现的次数是3，在这个字符中，出现的次数只有2次(假设其他字符符合)
- 显然，包含c的子串不可能是答案，同时c将可能的答案分为了三部分，每个部分通过左右索引锁定，假设我们要求解的答案是result(left, right, k)
- 假设c的位置分别在c1，c2，那么要求解的问题分为了三部分：result(left, c1 - 1, k)、result(c1 + 1, c2 - 1, k)、result(c2 + 1, right, k)
- 我们要的是上述的答案的最大值，而针对每一个答案，又可以通过上述的方案去处理，这就是递归的本质，为了更好的处理这个情况，我们可以选择将三部分进行逐步求解
- 也就说，对于大区间[left, right]，我们从left开始遍历一次，获取每个字符出现的次数的哈希表，其次，再进行遍历，当遍历到第一个不符合要求的字符：
- 我们就着手求解上面说的result(left, c1 - 1, k)，我们不需要管这部分怎么求，我们就当这部分已经求出来了(递归就是这样，多思考，多理解)，然后
- 在这个区间范围内继续遍历，我们一定会遇到第二个区间[c1 + 1, c2 - 1]，然后这部分同样这么处理.....
- 直到遍历到最后
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int sub_res(const string& s, int left, int right, int k) {
    int hash[26] = {0};

    // 这个for循环用来记录字符出现的次数
    for (int i = left; i <= right; i++)
    {
        hash[s[i] - 'a']++;
    }

    char split_char = 0;    // 初始化字符，这是一个空字符
    for (int i = left; i <= right; i++)
    {
        if (hash[s[i] - 'a'] > 0 && hash[s[i] - 'a'] < k) {
            split_char = s[i];    // 定位到该字符
            break;  // 我们只需要找到第一个这样的字符即可，
        }
    }

    if (split_char == 0) {  // 整个区间就是答案，因为没有找到那么一个字符
        return right - left + 1;
    }


    // 开始按照我们上述的思路去遍历区间了
    int move_index = left;
    int res = 0;    // 区间答案的初始值
    while (move_index <= right) {
        while (move_index <= right && s[move_index] == split_char) {    // 如果字符是在最左边
            move_index++;
        }
        int new_left = move_index;   // 新的子区间左边
        
        // 这个while循环找到新的子区间右边
        while (move_index <= right && s[move_index] != split_char) {
            move_index++;
        }

        int sub_result = sub_res(s, new_left, move_index - 1, k);    // 记得减1(我们不用管这个子区间怎么来的，一定是根据一样的策略来的)

        res = max(res, sub_result); // 求得了第一个子区间的结果，整个while大循环可以使得我们求得整个区间的结果
    }
    
    return res;
}

int longestSubstring(string s, int k) {
    return sub_res(s, 0, s.size() - 1, k);
}

int main() {
    cout << "Please input s && k: ";
    string str;
    int val;
    cin >> str >> val;
    cout << longestSubstring(str, val) << endl;

    return 0;
}