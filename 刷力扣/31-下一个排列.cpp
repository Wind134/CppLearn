/* 整数数组的下一个排列是指其整数的下一个字典序更大的排列 
 * 下一个序列的原则是，最大的那个数要往前移动一位，然后处理移动
 * 之后的后面的数组，即子序列，可以直接递归，如果是最大的那个序列，则翻转
 * 数组即可；
 * 
 * 上面的思路主要错在，没有考虑到这么一点，就是，我们需要的确实是字典序更大的数
 * 但我们希望这个增加的范围尽可能小，这才是我们的目的数；
 * 算法：从数组最右边开始，与前面最先出现的比最右小的数进行交换；
 * 交换之后，从左边那个被交换的数下一个开始做排序(升序)
 * 如果没有数大于最左边的那个数，那最左边的那个索引加一，重新执行上面那个过程
 * 
 * 上面这个思路还是有缺陷，缺陷在于无法保证这么一点：
 * 我们要尽可能保持在靠右的范围内去做交换，而上述这个思路，完全有可能会涉及到更左边的区域
 * 这样无法满足"增加范围尽可能小"的这么一个特点
 * 
 * 最终绝杀思路：从右往前找，找到第一个升序的相邻元素对(i,j)，这就说明从j开始，后续的一定都是逆序
 * 从[j, end)这个范围，继续从右往左找到第一个满足nums[i] < num[j]的元素，这样就保证了范围绝对靠右
 * 找到上述那个元素之后，交换两个值，交换之后我们可以断定[j, end]一定逆序，进行翻转，则升序，问题解决

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 该函数用来判断整个数是否逆序，逆序是我们要处理的特殊情况
bool testBiggset(const vector<int>& nums)
{
    bool tag = true;
    for (int i = 0; i < nums.size() - 1; i++)   // 防止越界
    {
        if (nums[i] >= nums[i + 1]) continue;
        else
        {
            tag = false;
            break;
        }
    }
    return tag;
}

void nextPermutation(vector<int>& nums)
{
    if (testBiggset(nums))
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = nums.size() - 1; i >= 1; i--)
    {
        if (nums[i] > nums[i-1])
        {
            for(int j = nums.size() - 1; j >= i; j-- )
            {
                if (nums[j] > nums[i - 1])
                {
                    swap(nums[i-1], nums[j]);
                    
                    reverse(nums.begin() + i, nums.end());
                    return;
                }
            }
        } 
    }  
}

int main()
{
    vector<int> array;
    int data;
    while (cin >> data)
    {
        array.push_back(data);
    }

    nextPermutation(array);

    for (const auto& num : array)
    {
        cout << num << " " ;
    }

    return 0;
}