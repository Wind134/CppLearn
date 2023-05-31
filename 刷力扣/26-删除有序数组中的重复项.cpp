/*
 * 每删除一个元素，后面都要向前移动一个元素，这种做法时间复杂度较高
 * 考虑采用双指针法，效率更高
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int size = nums.size();
    if (size < 2) 
    {
        return size;
    }
    int left = 0;   // 左指针

    int right = left + 1;
    while (right < size)
    {
        if (nums[left] == nums[right])  right++;
        else
        {
            nums[++left] = nums[right];
            right++;
        }
    }
    nums.erase(nums.begin() + left + 1, nums.end());
    return left + 1;
}

int main()
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);  
    }

    int k = removeDuplicates(nums);

    cout << k << endl;

    for (auto i : nums)
    {
        cout << i << " ";
    }
    
    return 0;
}