#include <iostream>

using namespace std;

struct Node
{
    int data;   // 假设data为int型
    Node* left_child;
    Node* right_child;
};

Node* root = nullptr;  // 根节点为空

// 创建一个结点
Node* newNode(int v)
{
    Node* newNode = new Node;   // 申请一个node型变量的地址空间
    newNode->data = v;
    newNode->left_child = nullptr;
    newNode->right_child = nullptr;
    return newNode;
}
// 二叉树的查找
void search(Node* root, int x, int newdata)
{
    if (!root)  return;
    if (root->data == x)    root->data = newdata;
    search(root->left_child, x, newdata);    
    search(root->right_child, x, newdata);    
}
