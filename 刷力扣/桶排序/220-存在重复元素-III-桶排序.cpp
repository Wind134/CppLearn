/*
题目：
- 给你一个整数数组nums和两个整数indexDiff和valueDiff。
- 找出满足下述条件的下标对 (i, j)：
- i != j,
- abs(i - j) <= indexDiff
- abs(nums[i] - nums[j]) <= valueDiff
- 如果存在，返回 true ；否则，返回false。

思路：学习桶排序
- 我们设定一个桶，桶的大小基于valueDiff，假设valueDiff = 3, {0 1 2 3}这四个元素一定符合条件
- 那为什么不分成{2 3 4 5}呢，因为我们想通过桶元素获取到桶的ID，显然应该遵循{0 1 2 3}的设计，ID = elem / 4;
- 而后确定桶大小为4 = valueDiff + 1，ID = elem / valueDiff + 1;
- 考虑负数，显然，我们也希望{-4 -3 -2 -1}在一个桶中，之所以这样有两个原因，其一在正数部分我们已经确定了桶大小，那么负数部分也应该遵循
- 但是，如果想通过桶元素获取桶ID，显然正数部分的算法不能用了，这个时候怎么办？
- 更改算法为ID = (elem + 1) / valueDiff + 1即可
- 桶ID的获取处理好之后，遍历数组中的元素，在indexDiff的范围内，我们遍历其中每个元素，看看元素对应的桶ID
- 一个桶内的元素必然是可以直接返回
- 非相邻桶之间的元素之间的索引值一定是不符合要求的
- 相邻桶之间的元素要看对应的索引是否在范围内，同时需要满足差的绝对值小于等于valueDiff
*/
#include "../headfile/io_for_leetcode.h"
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

int getID(int num, int size) {  // 注意这个size，是valueDiff加1之后的
    return (num >= 0) ? (num / size) : (num + 1) / size - 1;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int size = nums.size();

    // 桶将一个valueDiff内的int都集中在一起，但由于窗口移动的原因，窗口之外的元素他的桶ID并不是
    // 我们所关心的，因此在进入下一个窗口之后，略出去的那个元素得pop掉，用什么保存呢？用map
    // 从这里也可以看出来，一个桶最多只有一个元素，一旦桶里有两个元素了，代表找到了符合条件的值
    // 如果相邻桶有元素了，由于存在满足条件的可能性，我们此时就需要判断了
    map<int, int> id_elem;  //  桶ID<-->元素值之间的映射

    for (int i = 0; i < size; i++)
    {
        int id = getID(nums[i], valueDiff + 1);

        if (id_elem.count(id))  return true;

        if (id_elem.count(id - 1) && abs(id_elem[id - 1] - nums[i]) <= valueDiff)  return true;

        if (id_elem.count(id + 1) && abs(id_elem[id + 1] - nums[i]) <= valueDiff)  return true;

        id_elem[id] = nums[i];  // 查找完之后更新该桶的值

        if (i >= indexDiff) // 从i = indexDiff开始，处理不需要的桶，因为不能让桶无限增大
            id_elem.erase(getID(nums[i - indexDiff], valueDiff + 1));
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