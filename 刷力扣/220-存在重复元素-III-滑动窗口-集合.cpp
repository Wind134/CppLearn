/*
题目：
- 给你一个整数数组nums和两个整数indexDiff和valueDiff。
找出满足下述条件的下标对(i, j)：
    -- i != j
    -- abs(i - j) <= indexDiff
    -- abs(nums[i] - nums[j]) <= valueDiff

如果存在，返回true；否则，返回false。

思路：
- 维护一个窗口，窗口大小为indexDiff + 1
- 对这个窗口内的元素做排序，之后定义指针left，指向窗口左端
    -- 求每个相邻区间的元素差，相邻区间一定是最小的
    -- 其他情况，得到符合要求的答案，return结果即可

- 最后结果会超时(集合的处理方式稍微改变一下，就不超了)    
*/
#include "../headfile/io_for_leetcode.h"
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int size = nums.size();
    

    // 考虑特殊情况
    if (size == indexDiff) {
        sort(nums.begin(), nums.end());    // 区间排序

        int val_left = 0;
        while (val_left < size - 1) {
            if (nums[val_left + 1] - nums[val_left] <= valueDiff)  return true;
            else ++val_left;
        }
        return false;
    }

    multiset<int> seq_set;

    for_each(nums.begin(), nums.begin() + indexDiff, [&seq_set](int x) { seq_set.insert(x); });    // set应该是有序的
    for_each(seq_set.begin(), seq_set.end(), [](int x) { cout << x << " "; });
    for (auto it = seq_set.begin(); it != seq_set.end(); it++) {
        if (next(it) != seq_set.end() && *next(it) - *it <= valueDiff)  return true;
    }
    int first_insert = nums[0];
    
    for (int i = indexDiff; i < size; i++) {
        int right = i - 1;  // 定义初始的左右指针
        int left = i - indexDiff; 

        // 在集合中找符合要求的值
        auto iter = seq_set.lower_bound(nums[i] - valueDiff);
        if (iter != seq_set.end() && *iter <= nums[i] + valueDiff)  return true; 
        // seq_set.erase(seq_set.begin(), seq_set.end());  // 时间的优化点：是不是不需要erase所有的，只需要删除最近添加的那个数即可
        // 改进点在于缩小窗口，假设要判断的元素是x：那我们要查找的元素应该是在[x - valueDiff, x + valueDiff]之间
        // 只需要在集合中找到大于等于(x - valueDiff)的最小值y，将y与(x + valueDiff)比较
        
        seq_set.erase(first_insert);
        seq_set.insert(*(nums.begin() + i));
        first_insert = *(nums.begin() + left + 1);

        // for_each(seq_set.begin(), seq_set.end(), [](int x) { cout << x << " "; });

          
    }
    return false;
}
    

int main() {
    input input219;
    auto vec = input219.input_vector();
    cout << "Please input the indexDiff & valueDiff: ";
    int indexDiff, valueDiff;  cin >> indexDiff >> valueDiff;
    cout << boolalpha << containsNearbyAlmostDuplicate(vec, indexDiff, valueDiff) << endl;
}
