/* 本质上还是对KMP算法的具体实现 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getNext(string s, vector<int>& next)
{
    next.push_back(0);    // next数组的第一个值为0
    int prefix_len = 0; // 初始公共前缀长为0，实质上也正好对应了下标位置

    int i = 1;  // 从第二个开始遍历
    while (i < s.length())
    {
        if (s[prefix_len] == s[i])
        {
            prefix_len += 1;    // 自增1
            next.push_back(prefix_len);
            i++;   // i也自增1，开始判断下一个
        }
        else
        {
            if(prefix_len == 0)
            {
                next.push_back(prefix_len);
                i++;
            }
            else
            {
                prefix_len = next[prefix_len - 1];
            }
        } 
    }
    return next;   
}

int strStr(string haystack, string needle) 
{
    vector<int> next;
    next = getNext(needle, next);   // 获取next数组
    int i = 0, j = 0;
    while (i < haystack.length() && j < needle.length())
    {
        if(haystack[i] == needle[j])    i++, j++;
        else
        {
            if (j == 0) i++;
            else
            {
                //i += next[j - 1];
                j = next[j - 1];
            }
        }
    }
    if (j == needle.length())   return i - j;
    else    return -1;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << strStr(s1, s2) << endl;
}