/* 这道题并非需要调用集合，我只是训练一下集合的用法
事实上不用集合更简单，时间更快 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cin.get();
    set<int> set1, set2;
    vector<int> unionSet;   // 定义三个集合
    int data;
    for (size_t i = 0; i < n; i++)
    {
        cin >> data;
        set1.insert(data);
        unionSet.push_back(data);
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> data;
        set2.insert(data);
        if (set1.find(data) == set1.end())  unionSet.push_back(data);   // 集合1中没有的添加进来
    }
    sort(unionSet.begin(), unionSet.end());
    for (size_t i = 0; i < unionSet.size(); i++)
    {
        cout << unionSet[i] << " \n"[i==unionSet.size() - 1];
    }

    return 0;
}