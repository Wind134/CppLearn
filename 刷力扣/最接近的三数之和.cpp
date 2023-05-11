/* 返回一个最接近target的三数之和 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int threeSumClosest(vector<int>&, int);

int main()
{
    vector<int> nums;
    int num, target;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.get() == '\n')  break;  
    }

    cin >> target;

    int sum = threeSumClosest(nums, target);
    cout << sum << endl;
    return 0;
}


int threeSumClosest(vector<int>& nums, int target) 
{
    int left = 0;       // 最左边的变量
    sort(nums.begin(), nums.end()); // 将数组进行排序
    int subValue = pow(2, 31) - 1;
    int result = nums[0] + nums[1] + nums[nums.size() - 1];
    // int initValue = abs(nums[0] + nums[1] + nums[nums.size() - 1] - target);
    while (left < nums.size() - 2)
    {
        int right = nums.size() - 1;
        int medium = left + 1;
        while (right > medium)
        {
            int sum = nums[left] + nums[medium] + nums[right];
            if (sum - target > 0)
            {
                right --;
                if (abs(sum-target) < subValue)
                {
                    subValue = abs(sum-target);
                    result = sum;
                }
            }
            else  if (sum - target == 0)
            {
                return sum;
            }
            else
            {
                medium++;
                if (abs(sum-target) < subValue)
                {
                    subValue = abs(sum-target);
                    result = sum;
                }
            }
        }
        left++;
    }
    return result;
}
