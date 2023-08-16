/* 
* 原方法的时间复杂度是n^2的平方数量级，我们尝试一种优化思路
* 
* 给定了我们一个数组，那么这个数组的长度也就限定了，也就是说，我们需要返回的长度值就[1....size]这么size种可能

* 因此我们设定一个动态规划数组dp[i]，表示的是长度为i的最长递增子序列末尾元素的最小值
* 这个思路的核心之处在于，我们要找到一个严格上升序列的子数组，但我们需要尽可能让序列上升得更慢
* dp[1]的初始值为nums[0]，这个值(不一定是我们那个序列的最小值)，后续可能会不断的更新

* 用vector调内置库函数，舒服，降复杂度；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int lengthOfLIS(const vector<int>& nums) 
{
    if (nums.size() == 0)   return 0;
    vector<int> dp(1, nums[0]);   // 初始数组长度为1，该位置上的值为nums[0]

    for(int i = 1; i <nums.size(); i++)
    {
        if(nums[i] > dp[dp.size() - 1]) dp.push_back(nums[i]);  // 如果这个数比dp数组最后一个值要大，那么push，dp长加1
        else    // 如果更小，那么我们可以看看这个数能放在dp数组的哪个地方，我们对这个位置的要求是，这个位置的数dp[i]必须比nums[i]
                // 要大，而且必须是dp数组中第一个比该数要大的数(vector是不是有一个默认函数可以实现这个目的，不行就只能自己二分了)
        {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            *it = nums[i];  // 注意细节，这里是替换值
        }
    }

    return dp.size();   // 只是需要返回长度，而无须返回返回具体数组，如果是要返回具体数组，答案有多个；

}

int main()
{
    input input300;
    auto vec = input300.input_vector();
    
    cout << lengthOfLIS(vec) << endl;
}