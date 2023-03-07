#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cin.get();
    set<int> set1, set2;
    vector<int> set;   // 定义三个集合
    int data;
    for (size_t i = 0; i < n; i++)
    {
        cin >> data;
        set1.insert(data);
    }
    for (size_t i = 0; i < m; i++)
    {
        cin >> data;
        set2.insert(data);
        if (set1.find(data) != set1.end())  set.push_back(data);
    }
    for (size_t i = 0; i < set.size(); i++)
    {
        cout << set[i] << " \n"[i==set.size() - 1];
    }
    return 0;
}