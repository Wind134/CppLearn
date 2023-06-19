/* 
* 给定一个非负整数数组nums，你最初位于数组的第一个下标 

* 数组中的每个元素代表你在该位置可以跳跃的最大长度。

* 判断你是否能够到达最后一个下标。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(const vector<int>& nums)
{
    if(nums.size() == 1)    return true;

    if(nums[0] == 0)    return false;

    int left = 1, right = nums[0];  // 第一个区间的位置

    int farest_dis = 0;
    
    while(right < nums.size() - 1)  // 到倒数第二个位置截止即可
    {
        for(int i = left; i <= right; i++)
        {
            farest_dis = min(max(farest_dis, i + nums[i]), (int)nums.size() - 1);   // 取最远，但不超界
        }
        if (farest_dis == right)    return false;
        left = right + 1;
        right = farest_dis;
    }

    return true;
    
}

int main()
{
    vector<int> input;

    int elem_vector;

    while (cin >> elem_vector)
    {
        input.push_back(elem_vector);
        if(cin.get() == '\n')   break;
    }

    cout << boolalpha << canJump(input) << endl;

    return 0;
}