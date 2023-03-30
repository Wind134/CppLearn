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
    if (!root)  return;     // 递归边界
    if (root->data == x)    root->data = newdata;
    search(root->left_child, x, newdata);    
    search(root->right_child, x, newdata);    
}


// 二叉树的插入，取决于要插入的位置
void insert(Node* &root, int x)     // 应该知道为何需要引用了吧
{
    bool condition = true;      // 看题目要求的插入类型
    if (!root)  // 如果为空，root为空，则!root不为空，执行函数体
    {
        root = newNode(x);  // 创建这个x的结点并把结果赋给x
    }
    if(condition)    insert(root->left_child, x);
    else insert(root->right_child, x);  // 这一步的意义.... 
}

// 一整个二叉树的创建，逻辑上的创建完毕
Node* create(int data[], int n)  // 假设数据存储在data数组中
{
    Node* root = nullptr;   // 初始根节点
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);  // 以此插入
    }
    return root;    // 返回根节点
}