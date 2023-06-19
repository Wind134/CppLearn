/* 
* 给你一个无重叠的，按照区间起始端点排序的区间列表。

* 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠(如果有必要的话，可以合并区间)。
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


vector<vector<int>> insert(const vector<vector<int>>& intervals, vector<int>& newInterval)
{
    vector<vector<int>> result;

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
}

int main()
{
    vector<vector<int>> input;

    string line;    // 输入的某一行

    while (getline(cin, line))
    {
        if(line == "Q" || line == "q" || line == "quit")
        {
            cout << "Please input the array you will insert: ";
            break;
        }

        istringstream iss(line);     // 创建一个流对象

        vector<int> elem_of_input;

        int data;

        while (iss >> data) elem_of_input.push_back(data);

        input.push_back(elem_of_input);
    }

    vector<int> newInterval(2);

    cin >> newInterval[0] >> newInterval[1];

    auto output = insert(input, newInterval);

    for(const auto& vec : output)
    {
        for(auto elem : vec)    cout << elem << " ";
        cout << endl;
    }
    
    return 0;

}