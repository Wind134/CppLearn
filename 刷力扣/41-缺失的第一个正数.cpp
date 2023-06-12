/* 
* 给你一个未排序的整数数组nums, 请找出其中没有出现的最小的正整数。
* 请你实现时间复杂度为O(n), 并且只使用常数级别额外空间的解决方案。
* 思路：这就意味着显然不能先排序解决，选用hash法
* 对于一个长度为Size的数组，其中没有出现的正整数只能出现在[1, Size + 1]中，这里又分两种情况，其中[1, Size]全部出现
* 此时符合要求的最小正数为Size + 1；
* 如果没有全部出现，则最小正数为[1, Size]中未出现的最小正数；
* 这个时候问题就简单了，将[1, Size]映射为[0, Size - 1]，而[0, Size - 1]可以作为一个哈希表，哈希表中没访问过的最小下标
* 加上1就是我们所求值，如果都访问过，那么返回Size + 1
* 题目要求常数空间，因此我们不能原地建立新的哈希表，而是基于题目中提供的数组nums建立
* 具体怎么做呢？比如说8被访问过，8这个位置的下标不管在哪，我们将数组nums的索引位置7上的那个值做一下改动，将正变为负，
* 这样会不会影响到后续访问位置7上的那个值呢，是会有影响，但我们可以通过取绝对值很轻易的获取原始值
* 每个元素都经历一遍这样的处理之后，最终只要访问过的位置，其上的值都是负的，我们取第一个索引为正的下标，即最小值
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


int firstMissingPositive(vector<int>& nums)
{
    int size = nums.size();
    for (auto& i : nums)
    {
        if (i <= 0) i = size + 1;   // 小于等于0的值统统处理为Size + 1，这样就不受负数影响了
    }

    for (int i = 0; i < size; i++)
    {
        int num = abs(nums[i]);     // 由于要经过转负处理，我们通过取绝对值获取初始值，从而进行正常判断

        if (num <= size)            // 只要访问的值在[1, size]之间
            nums[num - 1] = -abs(nums[num - 1]);    // 正->负，之所以加绝对值还是因为要获取初始值(因为存在相同值的情况)
    }

    for (int i = 0; i < size; i++)
    {
        if(nums[i] > 0) return i + 1;
    }
    return size + 1;
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
    cout << firstMissingPositive(input) << endl;
    return 0;
}    