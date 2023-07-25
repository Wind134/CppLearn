/*
题目：
- 给你一个整数数组nums，判断是否存在三元组[nums[a], nums[b], nums[c], nums[d]]
- 满足a、b、c、d互不相同的条件，同时还满足 nums[a] + nums[b] + nums[b] + nums[d] == 0 
- 输出所有符合条件且不重复的四元组

思路：第一反应是采用多指针法(这样做的局限性在于，如果是5个6个....呢)
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, const int& target) 
{
    vector<vector<int>> result; // 默认初始化
    long long int longtarget = static_cast<long long int>(target);
    if (nums.size() < 4)
    {
        return result;   
    }
    sort(nums.begin(), nums.end());     // 默认升序

    for (int a = 0; a < nums.size() - 3; a++)      // 第一个下标a
    { 
        for(int b = a + 1; b < nums.size() - 2; b++)
        {
            int d = nums.size() - 1;        // 最后一个下标d 
            for (int c = b + 1 ; c < nums.size() - 1 && c < d; c++) // 限定了循环内部的条件
            {
                long long int aValue = static_cast<long long int>(nums[a]);
                long long int bValue = static_cast<long long int>(nums[b]);
                long long int cValue = static_cast<long long int>(nums[c]);
                long long int dValue = static_cast<long long int>(nums[d]);
                if ((aValue+ bValue + cValue + dValue) > longtarget && c + 1 < d)
                {
                    cout << aValue << " " << bValue << " " << " " << cValue << " " << dValue << endl;
                }  
                while ((aValue+ bValue + cValue + dValue) > longtarget && c + 1 < d)
                {
                    d--;    // 大于0时，左移最后一个下标d
                    dValue = static_cast<long long int>(nums[d]);    
                }
            
                if (nums[a] + nums[b]  == target - (nums[c] + nums[d]))    // 等于target时，添加进result
                {
                    result.push_back({nums[a], nums[b], nums[c], nums[d]});
                    d--;
                }
                while (c < d - 1 && nums[c + 1] == nums[c]) // 去重
                        c++;  
            }
            while (b < nums.size() - 3 && nums[b + 1] == nums[b]) // 去重
                        b++; 
        }
        // 下面这个循环主要是为了跳过重复值
        while(a < nums.size() - 4 && nums[a+1] == nums[a])   a++;
    }
    return result;
}

int main()
{
    input input18;
    auto vec = input18.input_vector();
    int target;
    cout << "Input the target: ";
    cin >> target;

    auto threeSumarray = fourSum(vec, target);
    output output18;
    output18.output_matrix(threeSumarray);
    return 0;
}


