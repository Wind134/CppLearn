/*
 * 移除所有等于某个值val的元素，并且返回新长度
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int size = nums.size();
    if (size == 0) 
    {
        return size;
    }
    
    vector<int> index;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == val) index.push_back(i);
    }
    
    for (int j = 0; j < index.size(); j++)
    {
        nums.erase(nums.begin() + index[j] - j);
    }

    return nums.size();
}

int main()
{
    vector<int> nums;
    int num;

    int val;
    cin >> val;

    while (cin >> num)
    {
        nums.push_back(num);  
    }

    

    int k = removeElement(nums, val);

    cout << k << endl;

    for (auto i : nums)
    {
        cout << i << " ";
    }
    
    return 0;
}