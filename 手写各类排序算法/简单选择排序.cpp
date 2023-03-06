/* 简单选择排序：在第i轮排序时选出其中a[i - 1] ~ a[n - 1]的
最小元素 */
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
    // cout << "看看默认数组大小为" << vec.size() << endl;
    int data;
    for (int i = 0; i < n; i++)
    {
        if (cin >> data)    vec.push_back(data);    // 添加进数组，如果把下面两个条件放在一起写会导致的问题是，最后一个data
        if(cin.get() == '\n')   break;              // 紧接'\n'会导致最后一个data无法push_back
    }
    for (int i = 0; i < vec.size(); i++)
    {
        int temp = vec[i];    // 第一个数
        int index = i; 
        for (int j = i + 1; j < vec.size(); j++)
        {
            // 记录最小值的下标索引
            if (vec[j] <= temp)
            {
                temp = vec[j];
                index = j;    // 更新临时变量
            }   
        }
        swap(vec[i], vec[index]);     // 交换，交换，不是相等！    
    }
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " \n"[i == vec.size() - 1];
    }
    
    return 0;
}