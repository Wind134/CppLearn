/*
题目：
- 给你一个整数数组nums和一个整数k，判断数组中是否存在两个不同的索引i和j，满足nums[i] == nums[j]且abs(i - j) <= k。
- 如果存在，返回true ；否则，返回false。

思路：
- 我们用一个map，存储数值<->索引间的映射；
- 每遍历到一个元素，我们就相应更新这个元素的索引，只要是从左往右索引，就能保证是最新的索引位置；
- 等碰到下一个相同的元素时，查哈希表，查abs(i - j)是否符合要求，符合要求则找到了目标值；
- 直到遍历完成；
- 本质上就是空间换时间；
*/
#include "../headfile/io_for_leetcode.h"
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> elem_indexs;    // 存储数值<-->索引之间的映射
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (elem_indexs.count(num) && i - elem_indexs[num] <= k)    return true;
        elem_indexs[num] = i;   // 索引会不断更新为更大的
    }

    return false;
}

int main() {
    input input219;
    auto vec = input219.input_vector();
    cout << "Please input the key value: ";
    int k;  cin >> k;
    cout << boolalpha << containsNearbyDuplicate(vec, k) << endl;
}
