/*
题目：
- 给你一个字符串s，由若干单词组成，单词前后用一些空格字符隔开。
- 返回字符串中最后一个单词的长度。
- 单词是指仅由字母组成、不包含任何空格字符的最大子字符串。

思路：
- 双指针处理，右指针先处理完后面附带的所有空格；
- 左指针，每次遇到一个新的单词就记录索引
- 左指针不断更新直到到right的位置，而在此之前更好记录了上一个单词的位置；
- 解决
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
    int left = 0;
    int right = s.size() - 1;
    while(s[right] == ' ')  right--;    // 锁定右边
    if (right == 0)  return 1;
    int before_last_word_index = -1;
    while(left != right)
    {
        if(s[left] == ' ' && s[left + 1] != ' ') before_last_word_index = left;
        left++;
    }

    return right - before_last_word_index;
}

int main()
{
    string line;
    getline(cin, line);
    cout << lengthOfLastWord(line) << endl;
    return 0;
}