/*
题目：
- 给你一个整数数组nums和一个整数k ，判断数组中是否存在两个不同的索引i 和 j，满足nums[i] == nums[j]且abs(i - j) <= k。
- 如果存在，返回true ；否则，返回false。

思路：
- 于某个元素开始，找下一个与之相同的元素的位置；
- 如果找到的位置<=k，返回结果即可，如果超过k，不必再继续遍历下去，已无可能
- 这样遍历下去的时间复杂度，k * O(n)
- 可能存在重复遍历，是否有优化的策略，不必重复扫描
- 空间换时间，用一个map保存数组中每一个多次出现的元素的索引即可
*/
#include "../headfile/io_for_leetcode.h"
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> elem_indexs;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (elem_indexs.count(num) && i - elem_indexs[num] <= k)    return true;
        elem_indexs[num] = i;
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
