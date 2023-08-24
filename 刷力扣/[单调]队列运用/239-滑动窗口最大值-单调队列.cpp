/*
集合的做法nlogn复杂度略高，考虑新的做法

- 思路：这部分参考了题解中的单调队列算法
- 如果说我们维护一个队列，首先需要思考的是：
- 队列中维护的信息应该是什么？其中的元素是应该递增还是递减，其次单调队列的单调性体现在哪里？
- 思考这么一种情形，假设在索引递增的情况下，如果此时nums中的元素跟着递增，显然会有这么一种情况：
    -- 队列中是要存储窗口中尚未被移除的下标，如果单调性体现在索引的递增性上，显然，对应值递增
    -- 那么最大值肯定是右边这个值，那我们就无法判断这个最大值是不是在新的窗口范围内
    -- 这就不符合我们单调队列的设计，因此，单调队列中的索引值显然递增，且对应的元素值应该递减
*/
#include "../headfile/io_for_leetcode.h"
#include <deque>
#include <algorithm>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int size = nums.size();
    deque<int> q;

    // 获取单调队列中的初始内容，索引递增，元素递减，也就是说，最前面的值是最大的
    for (int i = 0; i < k; i++) {
        while (!q.empty() && nums[i] >= nums[q.back()])   q.pop_back(); // 保证队列元素值递增
        q.push_back(i); // push_back注定索引值会递增(注意双端队列的back，类比vector数组即可)
    }

    vector<int> res = {nums[q.front()]};    // 先保存目前的最大值

    for (int i = k; i < size; i++) {
        while (!q.empty() && nums[i] >= nums[q.back()])   q.pop_back();
        q.push_back(i);
        while (q.front() <= i - k)    q.pop_front();    // 移除不在窗口范围内的索引

        res.push_back(nums[q.front()]);     // 获取最大值
    }

    return res;
}

int main() {
    input input239;
    auto input_vec = input239.input_vector();
    int k;
    cout << "Please input the length of window: ";
    cin >> k;

    auto output_res = maxSlidingWindow(input_vec, k);

    for (auto& elem : output_res)   cout << elem << " ";

    return 0;
}
