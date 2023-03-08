/* 给定两个字符串数组，统计第二个数组中的字符串在
第一个字符串数组中出现的次数 */
#include <iostream>
#include <vector>
#include <string>
#include <map>  // 出现次数的映射

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.get();
    vector<string> strs;
    map<string, int> infoMap;
    string element;

    for (int i = 0; i < n; i++)
    {
        cin >> element;
        if (infoMap.find(element) == infoMap.end()) infoMap[element] = 1;   // 不存在则添加进容器
        else infoMap[element] = infoMap[element] + 1;    // 存在则添加一次出现的次数
        strs.push_back(element);
        
    }
    // 元素已经输入数组并保存了映射
    // cin.get();      // 接一下换行符
/*     for (int i = 0; i < n; i++)
    {
        cout<< infoMap[strs[i]] << " \n"[i==n-1];
    } */
    strs.clear();   // 数组已经不需要了，清空
    int m;
    cin >> m;
    /* cout << "m=" << m << endl; */
    cin.get();
    for (int j = 0; j < m; j++)
    {
        cin >> element;
        strs.push_back(element);
    }
    for (int j = 0; j < m; j++)
    {
        if (infoMap.find(strs[j]) == infoMap.end()) cout << 0 << " \n"[j==m-1];
        else    cout<< infoMap[strs[j]] << " \n"[j==m-1];
    }
    return 0;
}