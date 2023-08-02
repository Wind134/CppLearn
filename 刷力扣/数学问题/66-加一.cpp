/*
题目：
- 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
- 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
- 你可以假设除了整数0之外，这个整数不会以零开头。

思路：从后往前推即可，更改下代码，更优雅；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    if (digits.empty()) return {1};

    int size = digits.size();
    int iter_index = size - 1;
    
    // 以下是原地修改
    while (iter_index >= 0) {
        ++digits[iter_index];
        if (digits[iter_index] < 10) return digits;
        else {
            digits[iter_index] -= 10;
            if (iter_index == 0) digits.insert(digits.begin(), 1);
        }
        --iter_index;
    }

    return digits;
}

int main()
{
    input input66;
    output output66;
    auto input_vec = input66.input_vector();

    auto output_res = plusOne(input_vec);
    output66.output_array(output_res);

    return 0;
}