#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using std::vector, std::map;

vector<int> twoSum(const vector<int> &nums, int target)
{
    map<int, int> element;
    for (size_t i = 0; i < nums.size(); i++)
    {
        element[nums[i]] = i;  // 存下下标索引以及对应值
    }

    for (auto it = element.begin(); it != element.end();it++ )
    {
        std::cout << it->second << std::endl;
    }
    
    for (auto it = element.begin(); it != element.end();it++ )
    {
        std::cout << it->second << std::endl;
        auto find_it = element.find(target - (it->first));
        if (find_it != element.end())
        {
            return {it->second, find_it->second};
        }
    }
    return {};
}

int main ()
{
    // vector<int> array1 = {1, 3, 5};
    vector<int> array1 = {3, 3};
    int target = 6;
    vector<int> output = twoSum(array1, target);
    for (auto it1 = output.begin(); it1 != output.end(); it1++)
        std::cout << *it1 << " ";
    return 0;
}