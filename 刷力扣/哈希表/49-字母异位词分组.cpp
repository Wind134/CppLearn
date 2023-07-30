/*
题目：
- 给你一个字符串数组，将字母异位词组合在一起，可以按任意顺序返回结果列表。
- 字母异位词是由重新排列源单词的所有字母得到的一个新单词。

思路：
- 起初的做法是：利用集合的直接访问特性去判断一致性，但忽略了：ono以及non这么一种特殊情况，集合无法判断，因此尝试使用map
- 使用之后Leetcode提示超时，应该是由于O(n^2)的时间复杂度造成的(因为每个都需要去判断是否符合规则)，思考新算法
- 之前算法主要的问题在于：把判断字符串相等与生成最后的数组分开来处理了，这样在针对输入的字符串数组的处理上必定难以避免O(n^2)的复杂度

- 优化后的方案：两个字符串相等，那么针对字符串本身去排序后的结果一定是一样的
- 因此主要的方法就是先针对给定的字符串遍历，将排序结果一致的字符串都放在一个数组中
- 我们对input中每个字符串做查找的时候，进行排序，排序结果一样的，放入某个位置
- 这样只需要经过一次循环遍历即可；
- 实现这么一个排序查找的方案就是：用map，map中的key是排序字符串，value则是符合异位关系的字符串数组

- 本质上也就是空间换时间的操作
*/
#include "../headfile/io_for_leetcode.h"
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    vector<vector<string>> result;
    
    unordered_map<string, vector<string>> store_map;

    for (auto& str : strs)
    {
        string temp_str = str;
        sort(temp_str.begin(), temp_str.end());
        store_map[temp_str].push_back(str);
    }

    for (auto elem : store_map)
    {
        // 但在一般情况下，emplace_back比push_back更高效。
        // 这是因为emplace_back可以直接在容器内部构造对象，而不需要进行额外的拷贝或移动操作。
        result.emplace_back(elem.second);
    }

    return result;
}

int main()
{
    input input49;

    auto str_vec = input49.input_strVec();
    auto res = groupAnagrams(str_vec);

    output output49;
    output49.output_str_matrix(res);

    return 0;
}

// // 判断两个字符串之间关系的函数
// bool strRelation(const string& s1, const string& s2)
// {
//     if (s1.size() != s2.size()) return false;
//     vector<int> hashTable1(26, 0);    // 数组用作s1映射
//     vector<int> hashTable2(26, 0);    // 数组用作s2映射

//     for(int i = 0; i < s1.size(); i++)
//     {
//         if(s1[i] != s2[i])
//         {
//             int index1 = s1[i] - 'a';
//             int index2 = s2[i] - 'a';
//             hashTable1[index1]++;
//             hashTable2[index2]++;
//         }
//     }

//     // 接下来判断两个集合中的元素是否相同

//     for (int i = 0; i < 26; i++)
//     {
//         if(hashTable1[i] != hashTable2[i])  return false;
//     }
    
//     return true;
// }