/**
 * 题目：
 * 给定整数数组nums和整数k，请返回数组中第k个最大的元素。
 * 请注意，你需要找的是数组排序后的第k个最大的元素，而不是第k个不同的元素。
 * 你必须设计并实现时间复杂度为O(n)的算法解决此问题。
 * 
 * 思路：
 * 快排变种
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

int findKthLargest_with_heap(const vector<int>& v, int k) {
    priority_queue<int> max_heap;
    for (auto &&n : v)
    {
        max_heap.push(n);
    }

    int res;

    while (k > 0) {
        res = max_heap.top();
        max_heap.pop();
        --k;
    }

    return res;
    
}

int quick_select(vector<int>& vec, int begin, int end, int k) {
    if (begin == end)   return vec[k];
    int partition = vec[begin], i = begin - 1, j = end + 1;
    while (i < j) {
        do ++i; while (vec[i] > partition); // 大于枢轴i就不断后移
        do --j; while (vec[j] < partition); // 小于枢轴j就不断前移
        
        // i，j经过移动之后，此刻i的位置上元素必定小于等于枢轴
        // j位置上的元素必定大于等于枢轴
        // 这种情况进行交换
        // 交换之后必定能把大的放到枢轴左边，小的放到枢轴右边
        // 当然，也含等于
        if (i < j)  swap(vec[i], vec[j]);
    }

    // 经过上面那一波循环处理之后，i > j必定成立

    if (k <= j) return quick_select(vec, begin, j, k);
    else return quick_select(vec, j + 1, end, k);
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quick_select(nums, 0, n - 1, k - 1);
}

int main() {
    input input215;
    auto input_vec = input215.input_vector();

    int k;
    cin >> k;

    cout << findKthLargest(input_vec, k) << endl;
    cout << findKthLargest_with_heap(input_vec, k) << endl;

    return 0;
}