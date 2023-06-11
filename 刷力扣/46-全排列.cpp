/* 
* 给定一个不含重复数字的数组nums，返回其所有可能的全排列，可以按任意顺序返回答案。
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
        elem_of_result.push_back(*t);
        auto newnums = nums;
        newnums.erase(find(newnums.begin(), newnums.end(), *t));
        backtrace(newnums, newnums.begin());
        elem_of_result.pop_back();
    }
    
}

vector<vector<int>> permute(vector<int>& nums) 
{
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