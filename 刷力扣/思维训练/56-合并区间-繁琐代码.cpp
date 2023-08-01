/*
题目：
- 以数组intervals表示若干个区间的集合，其中单个区间为intervals[i] = [starti, endi]。
- 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。 

注意：题目只说明start_i <= end_i，因此存在下一个区间范围更小的情况，这是一个细节

思路：
- 先对区间排序，排序之后对于有重叠的区间不断进行拓展，即拓展更大的区间右边的值
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if (intervals.size() == 1)  return intervals;
    // 按左区间的值，从小到大排序
    sort(intervals.begin(), intervals.end(),
    [](const vector<int>& data1, const vector<int>& data2) { return data1[0] < data2[0]; });
    
    vector<vector<int>> result;

    int size = intervals.size();
    // 写一个循环咋这么费劲呢.....
    int begin_index = 0;
    while (begin_index < size) {
        vector<int> elem_of_result(2);   // 初始化一个数组，数组大小为2。
        elem_of_result[0] = intervals[begin_index][0];    // 左边的值由于是按顺序排好的，因此不会有问题，我们需要处理右边的值
        elem_of_result[1] = intervals[begin_index][1];    // 右边的初始值
        if (begin_index == size - 1) {
            result.emplace_back(elem_of_result);
            return result;
        }   
        for (int next_index = begin_index + 1; next_index < size; next_index++) {
            if (intervals[next_index][0] <= elem_of_result[1]) { // 不断拓展含重复的区间长度
                elem_of_result[1] = max(elem_of_result[1], intervals[next_index][1]);
                if (next_index == size - 1) {
                    result.emplace_back(elem_of_result);
                    return result;
                }
            }
            else {
                begin_index = next_index;
                break;
            }
        }
        result.emplace_back(elem_of_result);
    }
    
    
    return result;
}


int main()
{
    input input56;
    output output56;
    auto input_matrix = input56.input_matrix();

    auto output_res = merge(input_matrix);

    output56.output_matrix(output_res);
    
    return 0;

}