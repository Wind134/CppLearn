/**
 * 题目：
 * 给你一个非空整数数组nums，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 * 
 * 思路：
 * 能实现上述运算的思路就是位运算；
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

int singleNumber(vector<int>& nums) {
    int res = 0;
    for (auto &&num : nums)
    {
        res ^= num;
    }
    return res;
}

int main() {
    input input136;

    auto vec = input136.input_vector();

    cout << singleNumber(vec) << endl;
}