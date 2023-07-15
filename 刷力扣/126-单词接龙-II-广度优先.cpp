/*
给定一个字典wordList，完成从单词beginWord到单词endWord转化，一个表示此过程的转换序列：
- beginWord -> s1 -> s2 -> ... -> sk这样的单词序列，并满足：
    -- 每对相邻的单词之间仅有单个字母不同。
    -- 转换过程中的每个单词 si（1 <= i <= k）必须是字典wordList中的单词。(注意，beginWord不必是字典wordList中的单词)。
    -- sk == endWord
给你两个单词beginWord和endWord，以及一个字典wordList。
请你找出并返回所有从beginWord到endWord的最短转换序列，如果不存在这样的转换序列，返回一个空列表。
每个序列都应该以单词列表[beginWord, s1, s2, ..., sk]的形式返回。

- 细节：
    -- 所有单词均只有小写字母，字典表中每个单词都不相同
    -- 字典表中每个单词长度相同

- 吐槽：理解题意都需要一个过程

做法：
    - 思路上像是回溯，我去遍历单词表中的每一个单词，去判断是不是只有一单词之差，如果不是，我去判断下一个
    - 如果是，我又有两种选择：
        -- 一是选择这个结果作为下一个，那么要判断的单词就需要更新，然后接着之前的流程
        -- 如果我不要这个结果，那么判断的单词还是原来那个，我接着之前的流程
    - 走到字典的最后，我们判断endWord在不在结果中，如果不在，返回空列表，这个可以不放在回溯中考虑，result直接在函数中判断
    - 这样处理的话，我们在回溯中必然会遇到endWord，在结尾之前遇到了endWord，直接返回即可
    - 最后一个难点在于要求返回最短的序列，因此我们临时保存每一个序列即可：
        -- 如果遇到大于的序列，保存序列的数组不保存这个序列;
        -- 如果遇到长度相等的序列，我们push进去即可
        -- 如果遇到长度更小的序列，我们就要清空这个保存序列的数组了，然后重新保存该序列

难点：
    -- 如果常规回溯，会按照从左往右的顺序进行，这样会限制顺序，因此也会限制答案的可能，这也是dfs的思路，这种思路目前看来不太可行
    -- 考虑广度优先搜索，比如我选中的某个单词，我分别往左右扩散，对于扩散出的符合条件的结果，我们选择接受或者不接受
    -- 这样就完全避免了顺序问题

由于单词互不相同，因此不需要考虑过多的可能

算法是对了，但目前这个广度有限的复杂度太高了

*/
#include "../headfile/io_for_leetcode.h"
#include <set>
using namespace std;

set<vector<string>> result_set;
vector<vector<string>> result;
vector<string> seq;

// 这个函数用来判断是否符合每对相邻的单词之间仅有单个字母不同
bool one_differ(const string& s1, const string& s2)
{
    int differ_count = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] != s2[i]) differ_count++;
        if (differ_count > 1)   break;
    }

    if (differ_count == 1)  return true;
    else return false;
}

void bfs(const string& detect_word, const string& endWord, const vector<string>& wordList, int index)
{
    if (index == wordList.size()) return;
    // 当发现目前要检测的与endWord刚好满足条件时，那可以执行插入操作了，然后返回
    int i = index, j = index + 1;
    while (i >= 0 || j < wordList.size()) {
        if (i >= 0 && one_differ(wordList[i], detect_word)) {
            // 如果匹配的刚好是最后一个，那么就可以直接返回
            if (wordList[i] == endWord) {
                if (result_set.empty()) {
                    seq.push_back(endWord);
                    result_set.insert(seq);  // 为空，则直接加进去
                    seq.pop_back();
                    return;
                }
                else {  // 不为空则判断长度
                        seq.push_back(endWord);
                        int length = (*result_set.begin()).size();
                        if (length == seq.size()) {
                            
                            result_set.insert(seq);
                            seq.pop_back();
                            return;
                        }                       
                        else if (length > seq.size()) {
                            // 清空所有结果，重新添加
                            result_set.erase(result_set.begin(), result_set.end());
                            result_set.insert(seq);
                            seq.pop_back();
                            return;
                        }
                        else {
                            seq.pop_back();
                            return;
                        }    
                }
            }
            // 如果不是，那我们又有两种选择，要这个匹配的，不要这个匹配的
            else {
                // 不要这个，那么直接下一个
                bfs(detect_word, endWord, wordList, index + 1);

                // 要这个
                seq.emplace_back(wordList[i]);
                bfs(wordList[i], endWord, wordList, index + 1);
                seq.pop_back();
            }
        }
        i--;
        if (j < wordList.size() && one_differ(wordList[j], detect_word)) {
            // 如果匹配的刚好是最后一个，那么就可以直接返回
            if (wordList[j] == endWord) {
                if (result_set.empty()) {
                    seq.push_back(endWord);
                    result_set.insert(seq);  // 为空，则直接加进去
                    seq.pop_back();
                    return;
                }
                else {  // 不为空则判断长度
                        seq.push_back(endWord);
                        int length = (*result_set.begin()).size();
                        if (length == seq.size()) {
                            
                            result_set.insert(seq);
                            seq.pop_back();
                            return;
                        }                       
                        else if (length > seq.size()) {
                            // 清空所有结果，重新添加
                            result_set.erase(result_set.begin(), result_set.end());
                            result_set.insert(seq);
                            seq.pop_back();
                            return;
                        }
                        else {
                            seq.pop_back();
                            return;
                        }    
                }
            }
            // 如果不是，那我们又有两种选择，要这个匹配的，不要这个匹配的
            else {
                // 不要这个，那么直接下一个
                bfs(detect_word, endWord, wordList, index + 1);

                // 要这个
                seq.emplace_back(wordList[j]);
                bfs(wordList[j], endWord, wordList, index + 1);
                seq.pop_back();
            }
        }
        j++;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    
    for (const auto& word : wordList)
    {
        if (word == endWord)    // 说明endword存在，可以进行回溯操作
        {
            seq.emplace_back(beginWord);
            bfs(beginWord, endWord, wordList, 0);
            for (const auto& elem : result_set) result.push_back(elem);
            return result;
        }
    }

    return result;  // 如果上面的dfs没执行，说明endWord不存在于字典，当然直接返回空的了
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    input input126;
    auto dict = input126.input_strVec();

    auto output_result = findLadders(str1, str2, dict);

    output output126;

    output126.output_str_vec(output_result);

    return 0;
    
}