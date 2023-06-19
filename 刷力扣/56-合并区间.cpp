/* 
* 以数组intervals表示若干个区间的集合，其中单个区间为intervals[i] = [starti, endi]。
* 请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。 

* 注意：题目只说明start_i <= end_i，因此存在下一个区间范围更小的情况，这是一个细节
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& v1, const vector<int>& v2)
{
    return *v1.begin() < *v2.begin();
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end(), compare);
    vector<vector<int>> result;
    vector<int> elem_of_result(2, 0);   // 初始化一个数组，数组大小为2，初始值皆为0
    int size = intervals.size();
    int index = 0;
    while (true)
    {
        elem_of_result[0] = intervals[index][0];    // 记下左边的初始值
        elem_of_result[1] = intervals[index][1];    // 记下右边的初始值，该值在下一个循环中需要不断更新
        if(index == size - 1)
        {
            result.push_back(elem_of_result);
            return result;
        }
        for(int i = index + 1; i < size; i++)
        {
            
            if(intervals[i][0] <= elem_of_result[1])
            {
                elem_of_result[1] = max(elem_of_result[1], intervals[i][1]);

                if(i == size - 1)
                {
                    result.push_back(elem_of_result);
                    return result;
                }
            }
            else
            {
                result.push_back(elem_of_result);
                index = i;
                break;
            }
        }
    }
    return result;
}


int main()
{
    vector<vector<int>> input;

    string line;    // 输入的某一行

    while (getline(cin, line))
    {
        if(line == "Q" || line == "q" || line == "quit")    break;

        istringstream iss(line);     // 创建一个流对象

        vector<int> elem_of_input;

        int data;

        while (iss >> data) elem_of_input.push_back(data);

        input.push_back(elem_of_input);
        
    }

    auto output = merge(input);

    for(const auto& vec : input)
    {
        for(auto elem : vec)    cout << elem << " ";
        cout << endl;
    }

    for(const auto& vec : output)
    {
        for(auto elem : vec)    cout << elem << " ";
        cout << endl;
    }
    
    return 0;

}