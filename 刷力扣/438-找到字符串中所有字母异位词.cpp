/*
* 给定两个字符串s和p，找到s中所有p的异位词的子串，返回这些子串的起始索引。

* 不考虑答案输出的顺序。

* 异位词指由相同字母重排列形成的字符串(包括相同的字符串)。 

* 我们可以考虑同时算长串以及短串的映射值
*/
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// map<char, int> get_strMap(const string& str)
// {
//     map<char, int> char_map;
//     for(char c : str) char_map[c]++;
//     return char_map;
// }

// // 下面这个函数时间复杂度为常数级
// bool isEqual(const map<char, int>& m1, const map<char, int>& m2)
// {
//     if (m1.size() != m2.size()) return false;
//     else
//     {
//         for(auto map_it1 = m1.begin(), map_it2 = m2.begin(); map_it1 != m1.end(); map_it1++, map_it2++)
//         {
//             if(map_it1->first != map_it2->first)    return false;
//             else
//             {
//                 if(map_it1->second != map_it2->second)  return false;
//             }
//         }
//     }
//     return true;
// }

bool operator==(const vector<int> v1, const vector<int> v2)
{
    if (v1.size() != v2.size()) return false;

    int size = v1.size();

    for (int i = 0; i < size; i++)
    {
        if(v1[i] != v2[i])  return false;
    }

    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> result;

    if(p.size() > s.size()) return result;

    vector<int> map_array_p(26, 0);
    vector<int> map_array_s(26, 0);

    int p_size = p.size();

    for(int i = 0; i < p.size(); i++)
    {
        map_array_p[p[i] - 'a']++;
        map_array_s[s[i] - 'a']++;
    }


    if(map_array_p == map_array_s)   result.push_back(0);

    for(int i = 0; i < s.size() - p_size; i++)
    {
        // 这俩行的理解：i代表的是移动的次数(短串移动的次数)，一共能移动(s.size() - p_size - 1次)
        // s[i] - 'a'代表随着p的移动，s与p相对照的字串也发生变化，但不管怎么变化，随着一次一次的移动
        // s中与p同样大小的子串的第一个字符就要去掉1次，也就是该位置字符出现的次数要少一次，这个字符是
        // 什么呢？是s[i]，而新覆盖的字符出现次数就要多一次，这个多一次的字符是哪个呢？s[i + index]
        // s = a b a c d a b s a    p = a b a c
        // a b a c
        // a b a c a c d a b s a
        //   b a c a
        // a b a c a c d a b s a 
        //     a c a c
        // a b a c a c d a b s a 
        // 可以看到，消失掉的字符是a，新出现的是a
        map_array_s[s[i] - 'a']--;
        map_array_s[s[i + p_size] - 'a']++;

        if(map_array_s == map_array_p)   result.push_back(i + 1);
    }

    return result;
}

int main()
{
    string long_str, str;

    cin >> long_str >> str;

    auto result = findAnagrams(long_str, str);

    for(auto elem : result) cout << elem << " \n"[elem == *(result.end() - 1)];
}
