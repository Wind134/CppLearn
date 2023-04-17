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
};

void createEdge (const int& v1, const int& v2, vector<VNode>& v)   // 出点，入点，头结点，用的头插法
{
    auto edgev1 = make_shared<ENode>(ENode(v2));    // 以v1为起始点的边
    auto p1 = v[v1].first;
    v[v1].first = edgev1;
    edgev1->next = p1;
    // auto edgev2 = make_shared<ENode>(ENode(v1)); // 有向图不需要这部分
    // auto p2 = v[v2].first;
    // v[v2].first = edgev2;
    // edgev2->next = p2;
}

struct pointDegree{
    int inDegree, outDegree;
};

int main()
{
    int VNum, ENum;     // 顶点数，边数
    cin >> VNum >> ENum;
    vector<VNode> headArray(VNum);  // 建立n个结点
    vector<pointDegree> pointDegreeV(VNum);
    int edgePoint1, edgePoint2;
    for (int i = 0; i < ENum; i++)
    {
        cin >> edgePoint1 >> edgePoint2;
        createEdge(edgePoint1, edgePoint2, headArray);
    }
    shared_ptr<ENode> p = nullptr;
    for (int j = 0; j < VNum; j++)
    {
        p = headArray[j].first;
        while (p != nullptr)
        {
            pointDegreeV[j].outDegree++;
            pointDegreeV[p->pointInfo].inDegree++;
            p = p->next;
        }    
    }
    for (auto value : pointDegreeV)
    {
        cout << value.inDegree << " " << value.outDegree << endl;
    }
    return 0;
}