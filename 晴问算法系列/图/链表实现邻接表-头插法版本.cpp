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

struct VNode    // 头结点
{
    shared_ptr<ENode> first = nullptr; // 指向第一条边，先初始化
    int degree = 0;
};

void createEdge (const int& startPoint, const int& endPoint, vector<VNode>& v)   // 出点，入点，头结点，用的头插法
{
    auto edgestartPoint = make_shared<ENode>(ENode(endPoint));    // 以startPoint为起始点的边
    auto p1 = v[startPoint].first;
    v[startPoint].first = edgestartPoint;
    edgestartPoint->next = p1;
    auto edgeendPoint = make_shared<ENode>(ENode(startPoint));
    auto p2 = v[endPoint].first;
    v[endPoint].first = edgeendPoint;
    edgeendPoint->next = p2;
    v[startPoint].degree++;
    v[endPoint].degree++;
}


int main()
{
    int VNum, ENum;     // 顶点数，边数
    cin >> VNum >> ENum;
    vector<VNode> headArray(VNum);  // 建立n个结点
    int edgePoint1, edgePoint2;
    for (int i = 0; i < ENum; i++)
    {
        cin >> edgePoint1 >> edgePoint2;
        createEdge(edgePoint1, edgePoint2, headArray);
    }
    
    bool tag = true;    // 为了打印空格而设置
    for (auto value : headArray)
    {
        if(tag)
        {
            cout << value.degree;
            tag = false;
        }
        else    cout << " " << value.degree;
    }
    return 0;
}


