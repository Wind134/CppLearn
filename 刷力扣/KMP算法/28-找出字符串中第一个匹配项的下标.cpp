/*
题目：
- 给你两个字符串haystack和needle，请你在haystack字符串中找出needle字符串的第一个匹配项的下标(下标从0开始)。
- 如果needle不是haystack的一部分，则返回-1。

思路：KMP算法的实践
- KMP算法的关键之处在于获取要匹配的子串的next数组，因此我们需要捋清next数组的定义：
- next[index]数组表示的是从索引0开始，长度为index + 1的字符子串，他们的最长公共前后缀；
- 那什么是最长公共前后缀呢？以abaabab为例：
    -- 前缀：[a ab aba abaa abaab abaaba]，之所以是前缀，所以不能包括自身；
    -- 后缀: [a ab bab abab aabab baabab]，这是后缀
    -- 从上面可以看出的是，最长的，公共的前后缀，只能是2了
    -- 这个最长公共前缀有什么作用呢？作用就在于当我们去匹配字符时，可以直接从上面的第一个ab，跳到最后一个ab
- 那next[0]必然为0(前后缀都是空)，next[1]表示字符ab的最长公共前后缀，依次类推
- 因此第一步就是先求出这个next数组：而且next的索引得从1开始，同样以abaabab为例：next[0] = 0;
    -- 在推导之前，我们可以先去规律性的想一些东西：假设现在是这么一种情况：*******c
    -- 假设前面*号那段长为index，且next[index - 1] = v已求出，接下来就是求next[index]
    -- next[index - 1] = v表明子串s的子串s[0...index - 1]他的最长公共前后缀串的长为v
    -- 那如果字符c对应的下标为index->s[index] = s[v]，也就是最长公共子串长为v的子串接下来的那个字符如果与c相等
    -- 那么next[index]就一定可以确定长度为(v + 1)，怎么理解这个东西，举个例子
        --- abcabca，abcabc的最长公共子串为3，由于接下来的那个字符串a与最长公共前后缀子串后的那个字符串a相等，因此，更新最长子串为4
    -- 如果s[index] != s[v]，那就考虑最长公共前后缀的长v的值了：
        -- 如果该值为0，显然，接下来只能为0；
        -- 如果不为0，显然我们需要更新最长前后缀v的值了，因为新增的那个字符已经成为了一个变数，这个时候索引也不能移动
        -- 它要等到该位置上的前缀值更新之后才能动，也就是说，index的移动是跟着next数组的更新走的  
        -- 显然，在遇到这种情况时，最长前缀要减1，然后再执行上面s[index]与s[v - 1]的判断，如果不行，再继续走这个流程
*/
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
            i++;   // i也自增与next的push_back操作同步进行
        }
        else    // 如果这两个关键位上的字符判断不相等
        {
            if(prefix_len == 0) // 则根据前后缀的长来更新next数组
            {
                next.push_back(prefix_len);
                i++;
            }
            else    // 长度不为0那就处理next数组的长
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
        else    // 如果遇到了不匹配的字符
        {
            if (j == 0) i++;    // 如果子串的第一个就不匹配
            else    // 如果不是子串的第一个字符不匹配，那就直接移动子串，都去比较新的字符
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