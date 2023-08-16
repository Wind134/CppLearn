/*
题目：
- 给你一个整数数组nums，有一个大小为k的滑动窗口从数组的最左侧移动到数组的最右侧。
- 你只可以看到在滑动窗口内的k个数字。
- 滑动窗口每次只向右移动一位。

- 要求返回滑动窗口中的最大值。

- 思路：
- 定义一个集合，该集合保存窗口内的元素，相等的也包含进去，由于集合插入是有序的，因此很方便获取最大值
- 随着窗口的移动，更新集合内的元素，我们用一个临时变量保存窗口的第一个元素即可

- 附注：
- 使用集合是个好办法，只是时间/空间复杂度多少有点高了(考虑尝试优化的思路)
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    int size = nums.size();
    multiset<int> window;
    vector<int> res;

    int out_elem = nums[0]; // 定义在每一次窗口滑动时将要丢出去的元素

    for (int i = 0; i <= size - k; i++) {
        if (window.empty()) for_each(nums.begin(), nums.begin() + k, [&window](int x) { window.insert(x); });
        else {
            window.erase(window.find(out_elem));    // 移除第一个元素
            window.insert(nums[i + k - 1]);         // 插入新元素
            out_elem = nums[i];                     // 更新第一个元素
        }

        res.push_back(*(window.rbegin()));
    }

    return res;
}

int main() {
    input input239;
    output output239;
    auto input_vec = input239.input_vector();
    int k;
    cout << "Please input the length of window: ";
    cin >> k;

    auto output_res = maxSlidingWindow(input_vec, k);

    output239.output_array(output_res);

    return 0;
}