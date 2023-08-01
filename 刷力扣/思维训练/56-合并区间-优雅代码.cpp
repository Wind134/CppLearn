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
    if (intervals.size() == 0)  return {};
    // 按左区间的值，从小到大排序
    sort(intervals.begin(), intervals.end(),
    [](const vector<int>& data1, const vector<int>& data2) { return data1[0] < data2[0]; });
    
    vector<vector<int>> result;

    for (int i = 0; i < intervals.size(); ++i) {
        int l_value = intervals[i][0], r_value = intervals[i][1];
        
        // 如果结果集为空，或者加入结果集的尾部数组右区间确定比当前左区间要短，则区间可加入结果集
        if (result.empty() || result.back()[1] < l_value) result.push_back({l_value, r_value});
        // 否则，就要更新尾部数组右区间的值
        else result.back()[1] = max(result.back()[1], r_value);
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