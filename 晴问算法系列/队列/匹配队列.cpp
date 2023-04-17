/* 
现有两个队列q1、q2，假设
q1、q2初始状态下均有n个元素，每个元素为1和2之一，且
q1中元素1的个数与q2中元素1的个数相同、q2中元素2的个数与
q1中元素2的个数也相同。接下来循环执行下面的操作，直到两个队列均为空：
如果q1、q2的队首元素相同，那么将两个队列的队首元素出队；
否则，将的队首元素移至队尾。
问需要执行多少轮操作，才能达成停止条件。 
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int count, times = 0, input;
    queue <int> q1;
    queue <int> q2;
    cin >> count;
    for (int i = 0; i < 2 * count; i++)
    {
        cin >> input;
        if (i < count)  q1.push(input);
        else q2.push(input);
    }
    while (!q1.empty() && !q2.empty())
    {
        times++;
        if (q2.front() != q1.front())
        {
            q2.push(q2.front());
            q2.pop();
        }
        else
        {
            q1.pop();
            q2.pop();
        }
    }
    cout << times << endl;
}