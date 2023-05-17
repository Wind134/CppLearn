/* 定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合
我们通过维护一个队列：对于digits[0]，先将其每个元素入队，将队头元素与下一个digit[i]的
每个元素拼接，依次入队，拼接完之后，将这个队头pop出去，继续执行直到队列中所有元素都经历了一次拼接，该操作进行到
直到没有下一个digits[i]为止
最终队列中的所有元素就是我们需要的所有元素
 */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


vector<string> letterCombinations(const string& digits)
{
    vector<string> results;
    int queueSize;
    queue<string> resultStr;
    vector<string> intStringMap{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (digits.size() == 0) return {};
    // else if (digits.size() == 1)
    // {
    //     for (int i = 0; i < intStringMap[digits[0] - '2'].size(); i++)  // 将digit[i]的元素入对
    //         {
    //             results.push_back(string(1, intStringMap[digits[0] - '2'][i]));
    //         }
    //     return results;    
    // }
    else
    {
        for (const auto& digit : digits)
        {
            if (resultStr.empty())
            {
                for (int i = 0; i < intStringMap[digit - '2'].size(); i++)  // 将digit[i]的元素入队
                    {
                        resultStr.push(string(1, intStringMap[digit - '2'][i]));
                    }
                queueSize = resultStr.size();    
            }
            else
            {
                for (int i = 0; i < queueSize; i++)
                {
                    for (int i = 0; i < intStringMap[digit - '2'].size(); i++)  // 将digit[i]的元素入队
                    {
                        resultStr.push(resultStr.front() + string(1, intStringMap[digit - '2'][i]));
                    }
                    resultStr.pop();
                }
                queueSize = resultStr.size();
            }    
        }
    }
    while (!resultStr.empty())
    {
        results.push_back(resultStr.front());
        resultStr.pop();
    }
    return results;
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