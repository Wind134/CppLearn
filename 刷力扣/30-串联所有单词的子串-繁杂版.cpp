/* 
* 给定一个字符串s和一个字符串数组words。words中所有字符串长度相同。
* s中的串联子串是指一个包含words中所有字符串以任意顺序排列连接起来的子串。
* 例如，如果words = ["ab","cd","ef"]，那么"abcdef"，"abefcd"，"cdabef"，"cdefab"，"efabcd"，和 "efcdab"都是串联子串。
* "acdbef"不是串联子串，因为他不是任何words排列的连接。

* 返回所有串联字串在s中的开始索引。可以以任意顺序返回答案。
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

bool isEqual(const map<string, int>& m1, const map<string, int>& m2)
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

vector<int> findSubStr(string s, string sub)
{
    vector<int> indexes;
    int pos = 0;

    while((pos = s.find(sub, pos)) != string::npos)
    {
        indexes.push_back(pos);
        pos ++;
    }

    return indexes;
}

vector<int> findSubstring(string s, vector<string>& words)
{
    vector<int> result;

    map<string, int> map_words = countTimes(words);
    int pos;

    int words_size = words.size();
    int size = words[0].size();
    
    // 使用map保证了map中每个string是不同的，因此我们不需要考虑对重复值的处理 
    for(auto it = map_words.begin(); it != map_words.end(); it++)
    {
        string word = it->first;
        vector<int> indexes = findSubStr(s, word);  // 找到了该单词在s中的所有子串
        for(int index : indexes)    // 遍历其中的每一个索引
        {
            if(index + words_size * size > s.size()) break; // 基于该索引获取后续相应长度的所有子串
            else
            {
                vector<string> words_in_s;
                for (int i = 0; i < words_size; i++)
                {
                    words_in_s.emplace_back(s.begin() + index + size * i, s.begin() + index + size * (i + 1));
                }
                
                if (isEqual(map_words, countTimes(words_in_s)))
                {
                    result.push_back(index);
                    // break;
                }
            }
        }
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