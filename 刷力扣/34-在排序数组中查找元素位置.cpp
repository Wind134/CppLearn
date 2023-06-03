/* 更具体来说：
 * 在排序数组中查找元素的第一个和最后一个位置；
 * 要求时间复杂度为logn，基本思路是二分是没什么问题的
 * 左边的尽量往左扩散，直到遇到不是我们要找的那个数或者到达开头
 * 右边的尽量往右扩散，直到遇到不是我们要找的那个数或者到达末尾
 * 起初版本的算法过于繁杂，先附于后，尝试一种新的算法：
 * 常规的二分就是为了寻找某个值，但我们这道题的二分是找两个东西：
 * (nums[leftIndex-1] < target && nums[leftIndex] == target)
 * (nums[rightIndex+1] > target && nums[rightIndex] == target)
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(const vector<int>& nums, int target)
{
    if(nums.size() == 0)    return {-1, -1};

    int leftIndex = -1, rightIndex = -1;    // 初始值都取-1

    // 全是相同数的情况
    if(*nums.begin() == target && *(nums.end() - 1) == target)
    {
        return {0, (int)nums.size() - 1};   // 需要进行一次类型转换
    }

    else if (*nums.begin() == target)    // 如果第一个值等于目标，则仅仅找rightIndex
    {
        leftIndex = 0;
        int i = 0, j = nums.size() - 1; // 循环用
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] > target) // 目标只能在左范围内
            {
                j = mid - 1;
                if (nums[j] == target)  return {leftIndex, j};
            }
            else if (nums[mid] == target)
            {
                if (nums[mid + 1] > target) return {leftIndex, mid};
                else i = mid + 1;
            }
        }     
    }

    else if ( *(nums.end() - 1) == target)// 如果最后一个值等于目标，则仅仅找leftIndex
    {
        rightIndex = nums.size() - 1;
        int i = 0, j = nums.size() - 1; // 循环用
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] < target) // 目标只能在左范围内
            {
                i = mid + 1;
                if (nums[i] == target)  return {i, rightIndex};
            }
            else if (nums[mid] == target)
            {
                if (nums[mid - 1] < target) return {mid, rightIndex};
                else j = mid - 1;
            }
        }     
    }

    else   
    {
        int i = 1, j = nums.size() - 2;

        // 先找(nums[leftIndex-1] < target && nums[leftIndex] == target)
        while (i <= j)
        {
            int mid1 = (i + j) / 2;
            if (nums[mid1 - 1] < target && nums[mid1] == target)
            {
                leftIndex = mid1;
                break;
            }
            if ((nums[mid1 - 1] == target && nums[mid1] == target) || nums[mid1] > target)
            {
                if (mid1 == 2 && nums[1] == target)
                {
                    leftIndex = 1;
                    break;
                }
                j = mid1 - 1;
                continue;
            }
            if (nums[mid1] < target)    i = mid1 + 1;
        }

        i = 1, j = nums.size() - 2;

        // 找右边界
        while (i <= j)
        {
            int mid2 = (i + j) / 2;
            if (nums[mid2 + 1] > target && nums[mid2] == target)
            {
                rightIndex = mid2;
                break;
            }
            if ((nums[mid2 + 1] == target && nums[mid2] == target) || nums[mid2] < target)
            {
                if (mid2 == nums.size() - 3 && nums[nums.size() - 2] == target)
                {
                    rightIndex = nums.size() - 2;
                    break;
                }
                i = mid2 + 1;
                continue;
            }
            if (nums[mid2] > target)    j = mid2 - 1;
        }
    }
    return {leftIndex, rightIndex};
}
int main()
{
    vector<int> array;
    int data;

    int target;
    while (cin >> data)
    {
        array.push_back(data);
        if (cin.get() == '\n')  break;
    }

    cin >> target;

    vector<int> result = searchRange(array, target);

    for (const auto& num : result)
    {
        cout << num << " " ;
    }

    return 0;
}

/* 
if (*nums.begin() == target && *(nums.end() - 1) != target)    // 如果第一个值等于0，则仅仅找最右
    {
        leftIndex = 0;
        int i = 0, j = nums.size() - 1; // 循环用
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] > target) // 目标只能在左范围内
            {
                j = mid - 1;
                if (nums[j] == target)  return {leftIndex, j};
            }
            else if (nums[mid] == target)
            {
                if (nums[mid + 1] > target) return {leftIndex, mid};
                else i = mid + 1;
            }
        }     
    }

    else if (*nums.begin() != target && *(nums.end() - 1) == target)    // 如果第一个值等于0，则仅仅找最右
    {
        rightIndex = nums.size() - 1;
        int i = 0, j = nums.size() - 1; // 循环用
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] < target) // 目标只能在左范围内
            {
                i = mid + 1;
                if (nums[i] == target)  return {i, rightIndex};
            }
            else if (nums[mid] == target)
            {
                if (nums[mid - 1] < target) return {mid, rightIndex};
                else j = mid - 1;
            }
        }     
    }

    else    // 最后一种情况就是左右都不等于，这个时候开始找边界
    {
        leftIndex = 0;
        int lefti = 0, leftj = (nums.size() - 1) / 2;   // 负责找左边界
        int righti = (nums.size() - 1) / 2 + 1, rightj = nums.size() - 1;   // 负责找右边界

        if (nums[leftj] > target)   // 这种情况下说明都在左边
        {
            leftj--;
            while (lefti <= leftj)
            {
                int midleft = (lefti + leftj) / 2;
                if (nums[midleft] == target && nums[midleft + 1] > target)  rightIndex = midleft;
                if (nums[midleft] == target && nums[midleft - 1] < target)  leftIndex = midleft;
            }
        }
        
        return {leftIndex, rightIndex};
    }
    return {-1, -1};
}
 */