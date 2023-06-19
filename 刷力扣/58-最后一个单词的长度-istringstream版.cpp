/* 
* 给你一个字符串s，由若干单词组成，单词前后用一些空格字符隔开。
* 返回字符串中最后一个单词的长度。
* 单词是指仅由字母组成、不包含任何空格字符的最大子字符串。

* istringstream直接上
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int lengthOfLastWord(string s)
{
        istringstream iss(s);
        vector<string> temp;
        string str;
        while(iss >> str)   temp.push_back(str);

        string result = *(temp.end() - 1);
        int size = result.size();
        return size;
}

int main()
{
    string str;
    cin >> str;
    cout << lengthOfLastWord(str) << endl;
    return 0;
}