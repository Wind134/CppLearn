/* 给定n个考生的分数，将它们从高到低排序，然后输出每个分数对应的排名。 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;  // 元素数目
    cin >> n;
    getchar();
    vector<int> vec;     // 默认初始化，默认大小为0，无元素的值
    int data;
    for (int i = 0; i < n; i++)
    {
        if (cin >> data)    vec.push_back(data); 
        if(cin.get() == '\n')   break;              
    }
    sort(vec.begin(), vec.end(), [](const int &a, const int &b) {return a > b; });  //成绩排序
    int tag = 1;    // 保存同分的个数 
    for (size_t i = 0; i < vec.size(); i++)
    {
        if(i + 1 < n && vec[i] == vec[i + 1])
        {
            tag++;
        }
        else
        {
            for (size_t j = 0; j < tag; j++)
            {
                cout << vec[i] << " " << i + 1 << endl;
            }
            tag = 1;
        }
    }
    return 0;
}