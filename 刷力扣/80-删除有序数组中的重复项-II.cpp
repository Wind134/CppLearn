/* 给你一个有序数组nums，请你原地删除重复出现的元素，使得出现次数超过两次的元素只出现两次，返回删除后数组的新长度。
* 第一反应的方案是使用单指针法，但是这样会造成重复移动，效率更低
* 因此尝试采用双指针法，具体的方案步骤就是，双指针的第一个指针指向元素头
* 第二个指针指向第一个不同的元素，一旦两个指针的大于2，进行清除处理

*/
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int left = 0;   // 移动的索引，这是左指针(索引)
    int right = 0;  // 移动的索引，这是右指针(索引)
    while(right < nums.size() - 1)
    {
        if(nums[right] == nums[right + 1])  // 如果相等，右指针持续右移
        {
            right++;
            if (right == nums.size() - 1)   // 需要特殊处理而不能直接退出的部分
                if (right - left >= 2)   nums.erase(nums.begin() + left + 2, nums.end());  // 删除多余的元素
        }
        else    // 判断左右指针相隔的距离
        {
            right++;    // 需要放在循环中
            if (right - left > 2)
            {
                nums.erase(nums.begin() + left + 2, nums.begin() + right);  // 删除多余的元素

                // 由于删除之后，由于元素减少，因此right的元素个数会发生改变，减少的个数为right - left - 2
                int less = right - left - 2;
                right -= less;   
            }
            // 无论if中条件满足与否，left都需要更新
            left = right;
            
        }
    }
    return nums.size();
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

    auto result = removeDuplicates(input);

    cout << result << endl;

    for(auto elem : input)    cout << elem << " ";
    cout << endl;

    return 0;
}