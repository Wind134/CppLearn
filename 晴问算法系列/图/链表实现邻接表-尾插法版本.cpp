/* 顺带计算每个顶点的度 */
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class ENode // 边结点
{
public:    
    ENode() { this->next = nullptr; }   // 构造函数
    ENode(int _v) : pointInfo(_v) { this->next = nullptr; } // 带参数的构造函数
    ~ENode() { }
    shared_ptr<ENode> next;  
    int pointInfo;   
};

struct VNode    // 顶点结点
{
    shared_ptr<ENode> first = nullptr; // 指向第一条边，先初始化
    int degree = 0; // 保存每个结点的度
};

void createEdge (const int& startPoint, const int& endPoint, 
vector<VNode>& v, vector<ENode>& p)   // 出点，入点，头结点，用的尾插法，因此多了一个p的结点
{
    auto edgestartPoint = make_shared<ENode>(ENode(endPoint));    // 以startPoint为起始点的边
    if (v[startPoint].first == nullptr) v[startPoint].first = edgestartPoint;
    if (p[startPoint].next == nullptr) p[startPoint].next = edgestartPoint;
    else
    {
        p[startPoint].next->next = edgestartPoint; // 指向最后一个结点，以便使用尾插法
        p[startPoint].next = edgestartPoint;
    }
    v[startPoint].degree++;

    auto edgeendPoint = make_shared<ENode>(ENode(startPoint));
    if (v[endPoint].first == nullptr) v[endPoint].first = edgeendPoint;
    if (p[endPoint].next == nullptr) p[endPoint].next = edgeendPoint;
    else
    {
        p[endPoint].next->next = edgeendPoint; // 指向最后一个结点，以便使用尾插法
        p[endPoint].next = edgeendPoint;
    }
    v[endPoint].degree++;
}


int main()
{
    int VNum, ENum;     // 顶点数，边数
    cin >> VNum >> ENum;
    vector<VNode> headArray(VNum);  // 建立n个结点
    vector<ENode> pVector(VNum);      // 为每个头节点定义一个额外的边结点，其next用来指向最后一个边结点
    int edgePoint1, edgePoint2;
    for (int i = 0; i < ENum; i++)
    {
        cin >> edgePoint1 >> edgePoint2;
        createEdge(edgePoint1, edgePoint2, headArray, pVector);
    }

    shared_ptr<ENode> p = nullptr;
    for (int k = 0; k < VNum; k++)
    {
        p = headArray[k].first;
        cout << k << '(' << headArray[k].degree << ')';
        while (p != nullptr)
        {
            cout << " " << p->pointInfo;
            p = p->next; 
        }
        cout << endl;
    }
    return 0;
}