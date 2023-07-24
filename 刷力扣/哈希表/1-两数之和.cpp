/*
题目：梦开始的地方(我说的是这道题)
- 给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
- 你可以假设每种输入只会对应一个答案。
- 但是，数组中同一个元素在答案里不能重复出现。
- 你可以按任意顺序返回答案。

思路：哈希表时间最优，空间复杂度略高；
*/
#include "../headfile/io_for_leetcode.h"
#include <map>
#include <algorithm>
using namespace std;

vector<int> twoSum(const vector<int> &nums, int target)
{
    map<int, int> ele_index;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = ele_index.find(target - nums[i]);
        if (it == ele_index.end())  {   // 如果没找到
            ele_index[nums[i]] = i;
        }
        else return {i, it->second};
    }

    return {};
}

int main ()
{
    input input1;
    auto input_vec = input1.input_vector();
    int target;
    cout << "Please input the target value: ";
    cin >> target;
    auto output = twoSum(input_vec, target);
    for (auto it1 = output.begin(); it1 != output.end(); it1++)
        std::cout << *it1 << " ";
    return 0;
}