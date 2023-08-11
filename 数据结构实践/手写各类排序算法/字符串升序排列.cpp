/* 输入n个字符串，将它们按字典序从小到大的顺序进行排序 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;  // 元素数目
    cin >> n;
    getchar();          // 缓冲换行符
    vector<string> vec;     // 默认初始化，默认大小为0，无元素的值
    string data;
    for (int i = 0; i < n; i++)
    {
        if (cin >> data)    vec.push_back(data);    // 添加进数组，如果把下面两个条件放在一起写会导致的问题是，最后一个data
        
    }
    sort(vec.begin(), vec.end());
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}