/*
题目：
- 给你一个无重叠的，按照区间起始端点排序的区间列表。
- 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠(如果有必要的话，可以合并区间)。

思路：
- 先定位左边界，插入进去之后分两边讨论是否需要合并；
- 首先定位插入的位置，这一步考虑使用二分，查找位置(调库实现，嘿嘿嘿，lowerbound)；
- 定位之后合并重复区间，之前的代码看起来就比较繁杂；

Notes：
- 上面的思路初衷是不用额外的存储，但是这样导致的一个问题是区间延展起来不是很方便，因此
- 还是基于空间换时间的方式优化做法

思考：在数学中，分类讨论的思想必然是重要的，但是，分类讨论有一个原则就是：
- 我们划分完子情况后，没有必要再在划分的子情况当中再进行分类讨论吧；
- 做题思路一旦流转到这一步，我们就要好好思考一下我们在分类讨论时的思路了；
- 这道题是一个很好的启示；
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> insert(const vector<vector<int>>& intervals, const vector<int>& newInterval)
{
    if (intervals.empty())  return {{newInterval[0], newInterval[1]}};

    vector<vector<int>> result;

    // 在下面我们直接把要插入的区间转化为[left, right]的形式
    // 如果遇到交叉或者说重合的，我们会不断拓展[left, right]，这样就
    // 直接锚定[left, right]区间即可，而无需死盯着newInterval
    // 避免不必要的讨论
    int left = newInterval[0];
    int right = newInterval[1];

    bool is_insert = false;    // 这个表示[left, right]区间是否插入过，初始是false，表明没有插入过；

    for (int index = 0; index < intervals.size(); index++) {
        // 如果要插入的区间在迭代的区间右边，那么这个区间可以直接插入结果集，不需要考虑额外情况
        if (left > intervals[index][1]) {
            result.push_back(intervals[index]);
        }
        else if (intervals[index][0] > right) {    // 如果要插入的区间完全在要迭代的区间左边
            if (!is_insert) {
                result.push_back({left, right});
                is_insert = true;
            }

            result.push_back(intervals[index]);
        }
        else { // 如果是有重合，则求并集合，随着不断地迭代，min_l和max_r所代表的并区间已经完成
            left = min(left, intervals[index][0]);
            right = max(right, intervals[index][1]);
        }
    }
    if (!is_insert) result.push_back({left, right});
    return result;
}

int main()
{
    input input57;
    output output57;
    auto input_matrix = input57.input_matrix();
    auto target_array = input57.input_vector();


    auto output_res = insert(input_matrix, target_array);

    output57.output_matrix(output_res);
    
    return 0;

}


/* 
if(intervals.size() == 0)
    {
        result.push_back(newInterval);
        return result;
    }

    bool count_tag = true;  // 加入一个计数标志位方便直接插入更新后的newInterval
    int tag_i = 0, count = 0;

    for (int i = 0; i < intervals.size(); i++)
    {
        if(intervals[i][1] < newInterval[0] || intervals[i][0] > newInterval[1])
        {
            if(i != 0 && i == tag_i + count)
                result.push_back(newInterval);  
              

            result.push_back(intervals[i]);

            // 如果else分支未曾执行过，且遍历到了二重数组的最后一个元素
            if(i == intervals.size() - 1 && count_tag)   result.push_back(newInterval);
        }
        else
        {
            if (count_tag)
            {
                tag_i = i;
                count_tag = false;
            }
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            count++;
            // 如果else分支执行了到了最后一个，代表if不会执行，此时特殊处理
            if(i == intervals.size() - 1)   result.push_back(newInterval);
        }
    }
    sort(result.begin(), result.end());
    return result;
*/