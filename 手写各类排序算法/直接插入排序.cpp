/* 简单选择排序：将数插入至一个有序序列即可
 */
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
        if (cin >> data)    vec.push_back(data);    // 添加进数组，如果把下面两个条件放在一起写会导致的问题是，最后一个data
        if(cin.get() == '\n')   break;              // 紧接'\n'会导致最后一个data无法push_back
    }
    for (int i = 1; i < vec.size(); i++)            // 第一个肯定是有序的，因此从第二个开始
    {
        int temp = vec[i];    // 有序的保存下来
        int j = i;            // 单独用j保存i，以便下面的循环
        while (j >= 1 && temp < vec[j - 1])     // 满足该条件执行循环
        {
            vec[j] = vec[j - 1];
            j --;
        }
        vec[j] = temp;
    }
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " \n"[i == vec.size() - 1];
    }
    return 0;
}