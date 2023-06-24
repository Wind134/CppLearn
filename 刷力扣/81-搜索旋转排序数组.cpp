/* 
* 已知存在一个按非降序排列的整数数组nums，数组中的值不必互不相同。

* 在传递给函数之前，nums在预先未知的某个下标k（0 <= k < nums.length）上进行了旋转，使数组
* 变为[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标从0开始计数）。
* 例如，[0,1,2,4,4,4,5,6,6,7]在下标5处经旋转后可能变为[4,5,6,6,7,0,1,2,4,4]。
* 给你旋转后的数组nums和一个整数target，请你编写一个函数来判断给定的目标值是否存在于数组中。
* 如果nums中存在这个目标值target，则返回true，否则返回false。

* 你必须尽可能减少整个操作步骤。

* 不管数组怎么旋转，如果我们采用二分的方式去处理，这个经过旋转的数组在二分法的那个点左右两端必定有一边是有序的
* 基于此处理即可
*/
#include <iostream>
#include <vector>
using namespace std;

bool search(const vector<int>& nums, int target)
{
    if (nums.size() == 0)   return false;
    if (nums.size() == 1)   return nums[0] == target;
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target) return true;

        // 下面是全局有序的情况，这种可能性是存在的，比如以0或者nums.size() - 1的下标旋转
        // 但是下面的问题出现在，if中的判断语句是有问题的，因为此前的初始nums并非互不相同
        // 因此即便是满足下面的条件，也无法断定整个区间一定有序
        // 那if中这种情况如何处理呢，很简单，left进1，right退1，因为相应位置上的值相同
        if (nums[left] == nums[mid] && nums[mid] == nums[right])
        {
            left++, right--;
        }
        else if (nums[left] <= nums[mid])   // 如果是左区间可能有序(注意是可能有序，原因同上)
        {
            if (nums[left] <= target && target < nums[mid])    // 如果是这种情况，表明左区间一定有序
            {
                right = mid - 1;    // 直接去左区间找
            }
            else   // 能执行else，说明nums[left] > target || target >= nums[mid]，不管是什么情况，都不可能在左区间
            {
                left = mid + 1;     // 直接去右区间找
            }
        }
        else    // 假设是右区间可能有序(这段分析可能有问题)
        {
            if (nums[mid] < target && target <= nums[nums.size() - 1])    // 判断是不是在可能有序的右区间，二分处理
            {
                left = mid + 1;
            }
            else   // 能执行else，说明上面的二分查找未找到目标值，那就只能去左边查找
            {
                right = mid - 1;
            }
        }    
    }
    
    return false;
}

int main()
{
    vector<int> input;

    int input_data;

    int target;
    cout << "Please Input The Target: ";
    cin >> target;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if (cin.get() == '\n')
        {
            cout << "Input Finished!\n";
            break;
        }
    }

    cout << boolalpha << search(input, target) << endl;

    return 0;
}