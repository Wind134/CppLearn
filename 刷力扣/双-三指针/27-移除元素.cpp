/*
题目：
- 移除所有等于某个值val的元素，并且返回新长度

思路：双指针
- left指针没有val值得数组的右边界，right指针作为移动指针不断向右移动
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int size = nums.size();
    if (size == 0) 
    {
        return size;
    }
    
    int left = 0;

    for (int right = 0; right < size; right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }

    return left;
}

int main()
{
    input input27;

    auto vec = input27.input_vector();

    cout << "Input the val: ";
    int val;
    cin >> val;

    cout << removeElement(vec, val) << endl;
    
    return 0;
}