/* 
* 给定一个可包含重复数字的序列nums，按任意顺序返回所有不重复的全排列。
* 
* 回溯问题：
* 对于当前某个index的位置，加入它或者不加入它，就这两种情况；
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
vector<int> elem_of_result;

void backtrace(const vector<int>& nums, vector<int>::iterator it)
{
    if (it == nums.end())
    {
        result.push_back(elem_of_result);
        return;
    }

    for (auto t = it; t != nums.end(); t++)
    {
        if (t > it && *t == *(t-1)) continue;   // 去重操作，重复值没必要处理
        
        elem_of_result.push_back(*t);
        auto newnums = nums;
        newnums.erase(find(newnums.begin(), newnums.end(), *t));
        backtrace(newnums, newnums.begin());
        elem_of_result.pop_back();
    }
    
}

vector<vector<int>> permute(vector<int>& nums) 
{
    sort(nums.begin(), nums.end());
    backtrace(nums, nums.begin());
    return result;
}

int main()
{
    vector<int> input;

    int data;

    while (cin >> data)
    {
        input.push_back(data);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    

    auto result = permute(input);
    for (const auto& vector : result)
    {
        for (auto& num : vector)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}