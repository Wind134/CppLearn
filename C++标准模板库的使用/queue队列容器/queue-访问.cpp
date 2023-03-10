#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;


//定义
//queue < typename > name;

int main()
{
    queue<int> q;
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }
    cout << q.front() << " " << q.back() << endl;
    return 0;
}