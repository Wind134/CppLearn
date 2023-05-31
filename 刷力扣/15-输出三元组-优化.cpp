/* 给你一个整数数组nums ，判断是否存在三元组[nums[i], nums[j], nums[k]]
满足i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 
输出所有符合条件且不重复的三元组
思路：第一反应是采用双指针法
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>&);

int main()
{
    vector<int> nums;
    int num;
    while (cin >> num)
    {
        nums.push_back(num);
        if (cin.get() == '\n')  break;  
    }


    vector<vector<int>> threeSumarray = threeSum(nums);
    for (const vector<int>& i : threeSumarray)
    {
        for(const int& data : i)   cout << data << " ";
        cout << "\n";
    }
    return 0;
}


vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> result; // 默认初始化
    sort(nums.begin(), nums.end());     // 默认升序

    for (int left = 0; left < nums.size() - 2; left++)      // 移动left
    {
        int right = nums.size() - 1;
        for(int medium = left + 1; medium < nums.size() - 1 && medium < right; medium++)
        { 

            while (nums[left] + nums[medium] + nums[right] > 0 && medium + 1 < right)
            {
                right--;    // 大于0时，左移right    
            }
            
            if (nums[left] + nums[medium] + nums[right] == 0)          // 等于0时，添加进result
            {
                result.push_back({nums[left], nums[medium], nums[right]});
                right--;
            }

            while ((medium + 1) < nums.size() - 1 && nums[medium + 1] == nums[medium]) // 去重
                    medium++;  
        }
        
        // 下面这个循环主要是为了跳过重复值
        while((left + 1) < nums.size() - 2 && nums[left+1] == nums[left])   left++;
    }
    return result;
}