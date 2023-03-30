#include <iostream>

using namespace std;

struct Node
{
    int data;   // 假设data为int型
    Node* left_child;
    Node* right_child;
};

Node* root = NULL;  // 根节点为空

// 创建一个结点
Node* newNode(int v)
{
    Node* newNode = new Node;   // 申请一个node型变量的地址空间
}
