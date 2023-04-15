/* 一个简单的用法示例 */
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int n, data;    // 操作序列的操作次数以及要输入数据
    string action;  // 行为
    queue<int> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> action;
        if (action == "push")
        {
            cin >> data;
            s.push(data);
        }
        else
        {
            if (s.empty())  cout << -1 << endl;
            else
            {
                cout << s.front() << endl;
                s.pop();
            }        
        }
    }
    return 0;
}