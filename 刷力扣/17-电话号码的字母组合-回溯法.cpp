/* 定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合
可以观察到：能返回的字母组合的个数：digits[0].size()*...*digits[i-1].size()
考虑采用回溯算法；
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void backTrace(vector<string>&, const vector<string>&, const string&, int, string&);


vector<string> letterCombinations(const string& digits)
{
    vector<string> results;
    string result;
    vector<string> intStringMap{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int resultNums = 0;
    if (digits.size() == 0) return {""};
    else    backTrace(results, intStringMap, digits, 0, result);
    return results;
}

void backTrace(vector<string>& combinations, const vector<string>& Map, const string& digits,
                int i, string& combination)
{
    if (i == digits.length())   // 代表走完了digits的长度
    {
        combinations.push_back(combination);
    }
    else
    {
        const string& letters = Map[digits[i] - '2'];
        for (const auto letter : letters)
        {
            combination.push_back(letter);
            backTrace(combinations, Map, digits, i + 1, combination);
            combination.pop_back(); // 弹出最后一个压进去的
        }
    }
}

int main()
{
    string input;
    cin >> input;
    for (const auto& output : letterCombinations(input))
    {
        cout << output << " ";
    }
    return 0;
}