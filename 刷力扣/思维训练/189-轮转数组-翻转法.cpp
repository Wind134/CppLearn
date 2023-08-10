/*
题目：
- 给定一个整数数组nums，将数组中的元素向右轮转k个位置，其中k是非负数。

思路：
- 找规律翻转即可；
*/
#include <iostream>
#include <vector>
using namespace std;

// 调库也可
void reverse(vector<int>& nums, int start, int end)
{
    int mid = (end + start) / 2;

    for (int i = start; i <= mid; i++)
    {
        swap(nums[i], nums[start + end - i]);
    }
}

void rotate(vector<int>& nums, int k)
{
    int size = nums.size();
    if (size == 1 || k % size == 0)  return;
    int real_times = k % size;

    reverse(nums, 0, size - 1);

    reverse(nums, 0, real_times - 1);

    reverse(nums, real_times, size - 1);
}

int main()
{
    vector<int> input;

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if (cin.get() == '\n')  break;
    }

    int k;

    cin >> k;

    rotate(input, k);

    for(int elem : input)   cout << elem << " ";

    cout << endl;

    return 0;
    
}