/*
总体思路比较简单，对于目标数而言，当数组中的值i小于这个目标数target的时候，记i出现的次数为cnt[i]，那么
cnt[i]<=i，当这个数大于或等于target的时候，则有cnt[i]>i，target刚好就是我们的分界线
*/
#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) 
{
    int ltimes = 1, rtimes = nums.size() - 1;   // 这两个变量分别代表最小和最大可能出现的次数
    int target = 0;     // 目标数
    while (ltimes <= rtimes)    // 走
    {
        int mid = (ltimes + rtimes) / 2;    // 基于出现的次数的二分查找，次数是有序的
        int count = 0;                       // 保存出现的次数
        for (int i = 0; i < nums.size(); i++)
        {
            count += (nums[i] <= mid);      // 自右向左结合，count要么+1，要么+0，
        }
        // 经过上述的一轮循环，得到了所有小于等于mid的数的个数
        if (count <= mid)   // 如果得到的个数是小于等于mid，那说明mid肯定不是目标数，目标数在mid右侧
        {
            ltimes = mid + 1;
        }
        else    // 否则目标数在左侧
        {
            rtimes = mid - 1;
            target = mid;   // 保存上一轮的mid，其实就是保存最终的mid
        }
    }
    return target;
}

int main ()
{
    vector<int> array1 = {1, 3, 4, 4};
    vector<int> array2 = {1, 2, 4, 4, 3};
    int target = findDuplicate(array2);
    cout << "数组中重复的数为：" << target << endl;
    return 0;
}