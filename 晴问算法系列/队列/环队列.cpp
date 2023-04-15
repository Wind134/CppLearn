/* 约瑟夫环-队列：每个人绕成一圈，约定一个正整数k，报道k的人离开圈子
离开之后的下一个人继续从1开始报数，报到k序号的人离开；
对于不离开的人，这个过程就是出队再入队的过程而已，离开的人，直接离开即可(输出)
 */
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int count, k;   // 元素数量，约定的k值
    cin >> count >> k;
    queue<int> q;
    for (int i = 1; i <= count; i++)
    {
        q.push(i);
    }
    /* 初始队列构建完成 */
    int tempData;   // 存储队前元素
    while (q.size() != 1)
    { 
        for (int j = 0; j < k; j++)
        {
            tempData = q.front();
            q.pop();
            if (j == k -1 )
            {
                cout << tempData << " "; 
            }
            else    q.push(tempData);
        }
    }
    cout << q.front();
    return 0;
}