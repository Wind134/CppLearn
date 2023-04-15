#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int lNode, rNode;
};


int main()
{
    int count;
    cin >> count;
    queue<int> q;
    vector<Node> vNode(count);  // 调用默认构造函数？
    Node data;
    for (int i = 0; i < count; i++)
    {
        cin >> data.lNode >> data.rNode;
        vNode[i] = data;
    }
    q.push(0);          // 先将根节点入队
    bool tag = true;    // 控制最后一位的空格
    while (!q.empty())
    {
        if (tag)
        {
            cout << q.front();
            tag = false;
        }    
        else    cout << " " << q.front();   // 输出访问节点
        if (vNode[q.front()].lNode != -1)   q.push(vNode[q.front()].lNode); // 访问节点的左节点存在，入队左节点
        if (vNode[q.front()].rNode != -1)   q.push(vNode[q.front()].rNode); // 访问节点的右节点存在，入队右节点
        q.pop();    // 访问过的元素，出队    
    }
    return 0;   
}