/*
题目：
- 给定一个字符串s和一个字符串数组words。words中所有字符串长度相同。
- s中的串联子串是指一个包含words中所有字符串以任意顺序排列连接起来的子串。
- 例如，如果words = ["ab","cd","ef"]，那么"abcdef"，"abefcd"，"cdabef"，"cdefab"，"efabcd"，和 "efcdab"都是串联子串。
- "acdbef"不是串联子串，因为他不是任何words排列的连接。
- 返回所有串联字串在s中的开始索引。可以以任意顺序返回答案。

这是一个简化版的尝试，优化时间与空间复杂度，思路参考438题

结果：时间复杂度基本没得到优化......空间复杂度极度优化

思路：
- 在主串中的查找，以words中每个词汇的长度为基准；
- 大体上是没什么问题

- 但这个做法第二次尝试还是超时了......不过代码精简得很不错
- 主要是后面leetcode新增了一个特殊案例的插入，这个案例中，words字典中全是重复的字符
    -- words中字符重复，这种情况我们单独处理
    -- 感觉优化后也没彻底解决问题.....
*/

#include "../headfile/io_for_leetcode.h"
#include <map>

using namespace std;

// 该函数统计words中每个词汇出现的次数，这个映射中要求词汇不能重复
map<string, int> countTimes(const vector<string>& words)
{
    map<string, int> result;

    for(const auto& word: words)    result[word]++;

    return result;
}

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> result;

    int s_length = s.size();
    int words_size = words.size();
    int word_len = words[0].size();

    if(s_length < words_size * word_len)   return result;   

    map<string, int> map_words = countTimes(words);


    int begin = 0;
    while(begin <= s_length - words_size * word_len)
    {
        auto temp = map_words;
        for (int j = 0; j < words_size; j++) {  // j代表的是比较的次数
            int index_begin = begin + j * word_len;
            int index_end = begin + (j + 1) * word_len;
            string temp_str(s.begin() + index_begin , s.begin() + index_end);
            if (temp.count(temp_str) != 0 && temp[temp_str] > 0) {  
                if (j == words_size - 1)
                    result.push_back(begin);
                temp[temp_str]--;
            }
            else    break;
        }

        // begin的变化代表着窗口的滑动，如果滑出的单词等于滑入的单词，且前一个已匹配，那么就不需要再操作哈希表了，直接通过单个词汇判断
        // begin的变化代表着窗口的滑动，如果滑出的单词等于滑入的单词，且前一个已匹配，那么就不需要再操作哈希表了，直接通过单个词汇判断
        if (word_len == 1 && temp.size() == 1 && temp.begin()->second == 0) {
            while (begin + 1 <= s_length - words_size * word_len && string(s.begin() + begin, s.begin() + begin + 1) == 
            string(s.begin() + begin + words_size, s.begin() + begin + words_size + 1)) {
                result.push_back(begin + 1);
                begin++;
            }
            begin = words_size * word_len + 1;
        } else {
            begin++;
        }

    }
    
    return result;
}

int main()
{
    string s;
    cout << "Input the str: ";

    cin >> s;
    
    input input30;

    auto words = input30.input_strVec();

    vector<int> result = findSubstring(s, words);
    
    output output30;
    output30.output_array(result);
    return 0;
}

/* 

下面是一串废弃的解法.....处理相同的情况的方案.....
if (map_words.size() == 1 && map_words.begin()->second == words_size) { // 特殊情况
        int i = 0;
        while (i <= s_length - words_size * word_len)
        {
            auto temp = map_words;
            for (int j = 0; j < words_size; j++) {  // j代表的是比较的次数
                int index_begin = i + j * word_len;
                int index_end = i + (j + 1) * word_len;
                string temp_str(s.begin() + index_begin , s.begin() + index_end);
                if (temp.count(temp_str) != 0 && temp[temp_str] > 0) {  
                    if (j == words_size - 1)
                        result.push_back(i);
                    temp[temp_str]--;
                }
                else {
                    i = index_end;
                    break;
                }
            }
            
            if (temp.begin()->second == 0) { // 表明全部匹配了
                // 直接比较单个字符，若匹配，则一直添加
                string next_str = string(s.begin() + i + words_size * word_len, s.begin() + i + (words_size + 1)* word_len);
                while (i + word_len <= s_length - words_size * word_len && next_str == temp.begin()->first) {
                    result.push_back(i + word_len);
                    i += word_len;
                    next_str = string(s.begin() + i + words_size * word_len, s.begin() + i + (words_size + 1)* word_len);
                }

                i += word_len;
            }
        }


*/