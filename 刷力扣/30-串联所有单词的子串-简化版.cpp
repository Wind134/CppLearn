/* 
* 给定一个字符串s和一个字符串数组words。words中所有字符串长度相同。
* s中的串联子串是指一个包含words中所有字符串以任意顺序排列连接起来的子串。
* 例如，如果words = ["ab","cd","ef"]，那么"abcdef"，"abefcd"，"cdabef"，"cdefab"，"efabcd"，和 "efcdab"都是串联子串。
* "acdbef"不是串联子串，因为他不是任何words排列的连接。

* 返回所有串联字串在s中的开始索引。可以以任意顺序返回答案。

* 这是一个简化版的尝试，优化时间与空间复杂度，思路参考438题

* 时间复杂度基本没得到优化......空间复杂度极度优化
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// 该函数统计words中每个词汇出现的次数
map<string, int> countTimes(const vector<string>& words)
{
    map<string, int> result;

    for(const auto& word: words)    result[word]++;

    return result;
}

bool operator==(const map<string, int>& m1, const map<string, int>& m2)
{
    if (m1.size() != m2.size()) return false;
    else
    {
        for(auto map_it1 = m1.begin(), map_it2 = m2.begin(); map_it1 != m1.end(); map_it1++, map_it2++)
        {
            if(map_it1->first != map_it2->first)    return false;
            else
            {
                if(map_it1->second != map_it2->second)  return false;
            }
        }
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> result;

    int words_size = words.size();
    int size = words[0].size();

    if(s.size() < words_size * size)   return result;   

    map<string, int> map_words = countTimes(words);

    int pos;
    
    vector<string> words_in_s;

    // 这个循环使得我们得到了s长串中与words等大小的字符串数组
    for (int i = 0; i < words_size; i++)
    {
        words_in_s.emplace_back(s.begin()  + size * i, s.begin() + size * (i + 1));
    }

    auto map_s_substr = countTimes(words_in_s);     // 获取了s中子串的映射，一旦获取，后续所有处理都基于该子串


    if(map_words == map_s_substr)   result.push_back(0);
    
    for(auto it = map_s_substr.begin(); it != map_s_substr.end();)
    {
        if(map_words.find(it->first) == map_words.end())   it = map_s_substr.erase(it);
        else
        {
            it->second = 0;
            it++;
        }    
    }

    
    for(int i = 1; i <= s.size() - words_size * size; i++)
    {
        string temp_str1(s.begin() + i , s.begin() + i + size);
        // cout << temp_str1 << endl;
        int count = 0;
        while(map_words.find(temp_str1) != map_words.end() && count < words_size)
        {
            map_s_substr[temp_str1]++;
            count++;
            if (count != words_size)
                temp_str1 = string(s.begin() + i + size * count, s.begin() + i + size * (count + 1));
        }

        if(map_words == map_s_substr)   result.push_back(i);

        for(auto& elem : map_s_substr)  elem.second = 0;
        
    }

    return result;
}

int main()
{
    string s;
    vector<string> words;

    string word;
    cin >> s;

    while (cin >> word)
    {
        words.emplace_back(word);
        if (cin.get() == '\n')  break;
    }

    vector<int> result = findSubstring(s, words);
    
    for (auto& elem : result)   cout << elem << " ";
    return 0;
}