/*
题目：
- 给你一个整数数组nums和两个整数indexDiff和valueDiff。
- 找出满足下述条件的下标对(i, j)：
    -- i != j
    -- abs(i - j) <= indexDiff
    -- abs(nums[i] - nums[j]) <= valueDiff
- 如果存在，返回true；否则，返回false。
- 相对于上面一题，多了个valueDiff的条件；

思路：
- 维护一个窗口，窗口大小为indexDiff + 1
- 对这个窗口内的元素做排序，之后定义指针left，指向窗口左端；
    -- 求每个相邻区间的元素差，相邻区间一定是最小的；
    -- 其他情况，得到符合要求的答案，return结果即可；
- 如果最终的复杂度是O(nk)，Leetcode那边提示会超时；
- 因此我们要想法利用集合常量时间查找的特性，优化寻找目标值的时间；
    -- 针对窗口右边值的x，我们在窗口范围内寻找区间大于等于x - valueDiff的最小值，且该值小于等于x + valueDiff]，则目标值已锁定；
    -- 对于数组中每个值，我们都做此寻找，直到遍历完成...
    -- 窗口的值的大小为indexDiff + 1，注意这一点细节；
- 这么处理之后，集合set有序无序都不重要了    
- 彻底弄清楚思路之后，可以优化代码的写法了；原代码写得太离谱
*/
#include "../headfile/io_for_leetcode.h"
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int size = nums.size();
    set<int> window;
    for (int i = 0; i < size; ++i) {
        // 针对集合调用lower_bound与使用泛型算法调用lower_bound的时间复杂度还不一样？
        // 下面这个写法在LeetCode超时
        auto it = lower_bound(window.begin(), window.end(), nums[i] - valueDiff);    // lower_bound含等于，切记同时要求元素有序，因此不能用无序数组
        if (it != window.end() && *it <= (nums[i] + valueDiff)) return true;

        window.insert(nums[i]);
        if (i >= indexDiff) window.erase(nums[i - indexDiff]);
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
