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

- 最后结果会超时    
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
    
    for (int i = 0; i < size - indexDiff; i++) {
        int left = i, right = left + indexDiff;  // 定义初始的左右指针
        seq_set.erase(seq_set.begin(), seq_set.end());
        for_each(nums.begin() + left, nums.begin() + right + 1, [&seq_set](int x) {seq_set.insert(x);});    // set应该是有序的
    
        // 那接下来就好办了，因为[left, right]区间有序，我们逐个进行判断
        auto it_left = seq_set.begin();
        while (next(it_left) != seq_set.end()) {
            if (*(next(it_left)) - *it_left <= valueDiff)  return true;
            else it_left = next(it_left);
        }  
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
