/*  
* 给定一个长度为n的0索引整数数组nums。初始位置为nums[0].
* 每个元素nums[i]表示从索引i向前跳转的最大长度。换句话说，如果
* 你在nums[i]处，你可以跳转到任意nums[i + j]处:
    0 <= j <= nums[i] 
    i + j < n
* 返回到达nums[n - 1]的最小跳跃次数。
* 起初思路是采用回溯递归，但该方法会超时，递归层数太多
* 因为动态规划的思路，我们要的是从第一个跳到最后的最小的次数：
* 针对起始位置nums[0]，在num[0]~nums[nums[0]]的位置都能一步到，那就是说
* step[nums[0]] = min(step(nums[0],...,nums[nums])) + 1;这里导致最终超时
* 如果采用贪心策略，我尽可能尝试跳到最远距离，1~nums[0]的点都将是0的下一个起跳点，这就是说，每次跳跃的
* 起点都是一个范围，这个范围的右边界能大于等于nums.size() - 1便达到了我们最终的结果

* 2 3 1 1 4 3 5 2 1 3 1 7为例：
* 第一个范围是3 1
* 第二个范围是1 4
* 第三个范围是3 5 2 1
* 第四个范围是3 1 7
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int jump(const vector<int>& nums) 
{
    // [startPoint, endPoint]组成了一个范围
    if (nums.size() == 1)   return 0;
    
    // 第一个范围是nums[0]本身
    int startPoint = 1;
    int endPoint = nums[0];
    int farest_pos = 0;
    int step = 1;   
    
    // 虽然有两层循环，但时间复杂度就是O(n)
    while(endPoint < nums.size() - 1)
    {   
        for (int i = startPoint; i <= endPoint; i++)
        {
            farest_pos = min((int)nums.size() - 1, max(farest_pos, nums[i] + i));
            // 如果最远距离能到nums.size() - 1，接下来都不用算了，直接返回
            if(farest_pos == nums.size() - 1)   return ++step;
        }

        // 确认了最远距离之后，更新范围
        startPoint = endPoint + 1;
        endPoint = farest_pos;
        step++;   
    }
    return step;
}

int main()
{
    vector<int> input;

    int data;

    while (cin >> data)
    {
        input.push_back(data);
        if (cin.get() == '\n')
        {
            break;
        }
    }
    cout << jump(input) << endl;
    return 0;
}