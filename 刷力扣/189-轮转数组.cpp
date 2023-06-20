/* 
* 给定一个整数数组nums，将数组中的元素向右轮转k个位置，其中k是非负数。
*/
#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k)
{
    int size = nums.size();
    if (size == 1 || k % size == 0)  return;
    int real_times = k % size;

    vector<int> temp_array(real_times, 0);
    for (int i = 0; i < real_times; i++)
    {
        temp_array[i] = nums[size - real_times + i];
    }
    for (int i = size - real_times - 1; i >= 0; i--)
    {
        nums[i + real_times] = nums[i];
    }

    for (int i = 0; i < real_times; i++)
    {
        nums[i] = temp_array[i];
    }
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