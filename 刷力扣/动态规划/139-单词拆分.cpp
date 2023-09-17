/**
 * 题目：
 * 给你一个字符串s和一个字符串列表wordDict作为字典。请你判断是否可以利用字典中出现的单词拼接出s。
 * 
 * 注意：
 * 不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
 * 
 * 思路：
 * 设定一个dp_array[i]，表明子串s.substr(0, i)是否可以由字典中出现的单词拼接而成，若可以则为true，否则为false
 * 那么当i = 0时，表明该子串是一个空串，我们认为空串可以拼接，即dp_array[0] = true;
 * 将s.substr(0, i)分成s.substr(0, j)与s.substr(j, i)两部分，其中j < i恒成立
 * 
 * 那么一个大问题就能分解为一个小问题加一个单独的子问题，即：
 * dp_array[i] = dp_array[j] && (子串s.substr(j, i)是否出现在字典中)
 * 
 * 一旦能判定dp_array[i]为true，则我们可以判断下一个位置，当我们取遍了范围中的j都不行，那么该位置只能为false
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

bool wordBreak(string s, const vector<string>& wordDict) {
    int maxLen = 0;
    unordered_set<string> hash;

    // for循环获取字典中最长单词的长度
    for(auto&& word : wordDict) {
        hash.insert(word);
        maxLen = max(maxLen, (int)word.size());
    }

    // dp_array[i] = dp_array[j] && (s[j...i - 1]是否出现在单词中)
    // dp_array[i]表示的是 0~i-1 子串是否能被拆分为若干个wordDict中的单词
    // 其中dp_array[0]表示空串，空串默认true
    vector<bool> dp_array(s.size() + 1);
    dp_array[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = i - 1; j >= 0 && i - j <= maxLen; --j) {
            string right_sub_str = s.substr(j, i - j);
            if (dp_array[j] && hash.find(right_sub_str) != hash.end()) {
                dp_array[i] = true;
                break;
            }
        }
    }

    return dp_array[s.size()];
}

int main() {
    input input139;
    string str;
    cin >> str;
    auto word_dict = input139.input_strVec();

    cout << boolalpha << wordBreak(str, word_dict) << endl;

    return 0;
}