/*
题目：
- 给你一个未排序的整数数组nums, 请找出其中没有出现的最小的正整数。
- 请你实现时间复杂度为O(n), 并且只使用常数级别额外空间的解决方案。


思路：复杂度的限制意味着显然不能先排序解决，选用hash法；
- 一看到这个问题的第一反应就是，肯定需要遍历整个数组，假设数组长为len；
- 没有出现的最小正整数只能出现在哪个范围呢？最小一定是1，最大呢，能大于len + 1这个值吗？
    -- 接下来就是反证法的思想了，假设没有出现的最小正整数是len + 2，那么1 ~ len + 1肯定都出现在数组中；
    -- 而此时长为len + 1，矛盾；
    -- 因此未出现的，最小的正整数，范围只能是[1, len]的值区间；
- 因此，基本的O(n)级别的思路就有了，但题目还要求常数空间，意味着不能通过新建一个数组这种占据空间的方式解决问题；
- 对于一个长度为Size的数组，其中没有出现的正整数只能出现在[1, Size + 1]中，这里又分两种情况：
    -- 其中[1, Size]全部出现符合要求的最小正数为Size + 1；
    -- 如果没有全部出现，则最小正数为[1, Size]中未出现的最小正数；
- 这个时候问题就简单了，将[1, Size]映射为[0, Size - 1]，而[0, Size - 1]可以作为一个哈希表，哈希表中没访问过的最小下标
- 加上1就是我们所求值，如果都访问过，那么返回Size + 1
- 题目要求常数空间，因此我们不能原地建立新的哈希表，而是基于题目中提供的数组nums建立
- 具体怎么做呢？比如说8被访问过，8这个位置的下标不管在哪，我们将数组nums的索引位置7上的那个值做一下改动，将正变为负，
- 这样会不会影响到后续访问位置7上的那个值呢，是会有影响，但我们可以通过取绝对值很轻易的获取原始值
- 每个元素都经历一遍这样的处理之后，最终只要访问过的位置，其上的值都是负的，我们取第一个索引为正的下标，即最小值

- 这个哈希表的精髓在于把目前值映射到了数组索引，这个思想很妙
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;


int firstMissingPositive(vector<int>& nums)
{
    int size = nums.size();
    
    // 第一次循环，将所有的负数变为size + 1
    for (int i = 0; i < size; i++)  if (nums[i] <= 0)   nums[i] = size + 1;

    for (int i = 0; i < size; i++) {
        int num = abs(nums[i]); // 获取绝对正值
        if (num <= size)    nums[num - 1] = -abs(nums[num - 1]); // 处理成绝对负值
    }

    for (int i = 0; i < size; i++) {
        if (nums[i] > 0)    return i + 1;
    }
    
    return size + 1;
}

int main()
{
    input input41;

    auto vec = input41.input_vector();
    cout << firstMissingPositive(vec) << endl;
    return 0;
}    