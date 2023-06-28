/*
* 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）

* 思路：思路就是一个很明显的回溯，每个数都面临两种情况，选或者不选

* 对于上一个数与这个数相同的情况，如果上一个数没有被选过，意味着包含这个数的所有子集，必然也出现在包含上一个数的所有子集中
* 因此这个数生成的子集完全可以跳过；
* 但是如果被选过，就不一样了，{1 2 2}与{1 2}完全是不一样的子集，因为第二个2被选过

* 由于只需要考虑上一个，因此初次尝试的建立一个数组的做法是有问题的，因为随着递归的作用深入下去，在数组前面改变的bool会继续对后续递归产生作用
* 而我们所想要的效果是：只关心上一个数组的数是否处理过
* 
* 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result_set;
vector<int> vec_of_result;


void backtrace(bool process, int index, const vector<int>& nums)
{
    if (index == nums.size())
    {
        result_set.push_back(vec_of_result);
        return;
    }
    
    backtrace(false, index + 1, nums);

    if (!process && index > 0 && nums[index] == nums[index - 1])    return; // 直接返回，不需要处理下一个了

    vec_of_result.push_back(nums[index]);
    backtrace(true, index + 1, nums);
    vec_of_result.pop_back();
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    backtrace(false, 0, nums);
    return result_set;
}

int main()
{
    vector<int> input;

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if (cin.get() == '\n')
        {
            cout << "Input Finished!\n";
            break;
        }
    }

    auto result = subsetsWithDup(input);

    for(const auto& vec : result)
    {
        for(auto elem : vec)    cout << elem << " ";
        cout << endl;
    }

    return 0;
}