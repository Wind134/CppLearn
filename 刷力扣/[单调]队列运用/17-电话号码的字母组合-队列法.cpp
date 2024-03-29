/*
题目：
- 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合(图略，就是那种经典诺基亚手机的九键)


思路：
- 我们通过维护一个队列：对于digits[0]，先将其每个元素入队，将队头元素与下一个digit[i]的
- 每个元素拼接，依次入队，拼接完之后，将这个队头pop出去，继续执行直到队列中所有元素都经历了一次拼接，该操作进行到
- 直到没有下一个digits[i]为止
- 最终队列中的所有元素就是我们需要的所有元素
 */
#include "../headfile/io_for_leetcode.h"
#include <queue>
using namespace std;


vector<string> letterCombinations(const string& digits)
{
    vector<string> res;
    if (digits.size() == 0) return res;
    int queueSize;
    queue<string> resultStr;
    vector<string> intStringMap{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    for (const auto& digit : digits)
    {
        int index = digit - '2';    // 映射索引
        if (resultStr.empty())
        {
            for (int i = 0; i < intStringMap[index].size(); i++)  // 将digit[i]的元素入队
                {
                    resultStr.push(string(1, intStringMap[index][i]));
                }
            queueSize = resultStr.size();    
        }
        else
        {
            for (int i = 0; i < queueSize; i++)
            {
                for (int i = 0; i < intStringMap[index].size(); i++)  // 将digit[i]的元素入队
                {
                    resultStr.push(resultStr.front() + string(1, intStringMap[index][i]));
                }
                resultStr.pop();
            }
            queueSize = resultStr.size();
        }    

    }
    while (!resultStr.empty())
    {
        res.push_back(resultStr.front());
        resultStr.pop();
    }
    return res;
}


int main()
{
    string input_str;
    cin >> input_str;

    auto output_res = letterCombinations(input_str);
    
    output output17;

    output17.output_str_vec(output_res);
    return 0;
}