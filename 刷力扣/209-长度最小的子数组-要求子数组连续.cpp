/*
- 给定一个含有n个正整数的数组和一个正整数target 。

- 找出该数组中满足其和≥target的长度最小的连续子数组[numsl, numsl+1, ..., numsr-1, numsr]，并返回其长度。
- 如果不存在符合条件的子数组，返回0。

是大于等于，这样题目就简化多了
    -- 设定两个指针，分别指向窗口的左右两边 
*/
#include "../headfile/io_for_leetcode.h"
#include <climits>
#include <cmath>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;  // 初始起点
    int right = left;
    int res = INT_MAX;    // 初始结果
    while (right < nums.size()) {
        if (nums[left] >= target)  return 1;    // 左边元素等于，直接返回1
        // 如果左边的元素小于目标值，接下来我们可以判断连续的情况了
        else {
            // 如果存在连续，则进行移动处理
            if (right < nums.size() - 1 && abs(nums[right + 1] - nums[right]) == 1) {
                    
                    if (nums[right + 1] - nums[right] == 1) {
                        
                        // 经过下面while这个循环处理，right指向了连续的数中最大的那个
                        while (nums[right + 1] - nums[right] == 1) {
                            right++;
                        }
                        int temp_sum = nums[right];
                        for (int i = right - 1; i >= left; i--) {
                            if ((temp_sum += nums[i]) >= target) {
                                res = res < (right - i + 1) ? res : (right - i + 1);
                                break;
                            }
                        }
                    }
                    else {  // 否则就是-1了
                        bool tag = false;   // 保证if里面的内容只执行一次
                        int temp_sum = nums[right];
                        while (nums[right + 1] - nums[right] == -1) {
                            temp_sum += nums[right + 1];
                            if (temp_sum >= target && !tag) {
                                res = res < (right - left + 2) ? res : (right - left + 2);
                                tag = true;
                            }

                            right++;
                        }
                    }

                    // 尝试判断下一个有序区间
                    left = right + 1;
                    right = left;
            }
            else {
                left++;
                right = left;
            }
            
        }    
    }
    
    return (res == INT_MAX) ? 0 : res;
            
}
        

int main() {
    input input209;
    auto input_vec = input209.input_vector();
    cout << "Input the target: ";
    int t;
    cin >> t;

    cout << minSubArrayLen(t, input_vec) << endl;

    return 0;
}