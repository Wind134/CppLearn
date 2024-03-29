/* 这道题单独处理一下结点的构造 */
#include "../headfile/io_for_leetcode.h"
#include <queue>
using namespace std;

// 完美二叉树节点
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* buildTreeWithVec_diff(const std::vector<int>& nums, int index = 0) // 给一个默认参数不影响什么吧，这是默认的起始位置
{
    if(index > nums.size() - 1)    return nullptr; // -1代表该节点不存在(注意权值为-1的情况即可)

    Node* root = new Node(nums[index]);

    root->left = buildTreeWithVec_diff(nums, 2 * index + 1);

    root->right = buildTreeWithVec_diff(nums, 2 * index + 2);

    root->next = nullptr;

    return root;
}

// 连接各结点
Node* connect(Node* root) {
    // 空结点的情况
    if (!root)  return nullptr;

    // 如果next指针非空，代表某一层已经连接在了一起
    // 那么该结点的右孩子应该与next指向的结点的左孩子通过next指针相连
    if (root->next)
    {
        if (root->right && root->next->left)    root->right->next = root->next->left;
    }
    // 左右孩子互相连接，由于是完美二叉树，判断左边等同于判断了右边
    if (root->left) root->left->next = root->right;

    // 处理下一行的左孩子
    connect(root->left);

    // 处理下一行的右孩子
    connect(root->right);

    return root;
}

// 这个函数实现了对该类结点的访问，并非题目要考的范围，只是为了自行测试
void visitNode(Node* root)
{
    queue<Node*> node_queue;

    node_queue.push(root);  // 先将根结点入队
    while (!node_queue.empty())
    {
        auto visit_node = node_queue.front();
        while (visit_node)
        {
            if (visit_node->next)   cout << visit_node->val << " ";
            else    cout << visit_node->val << " # ";
            
            if (visit_node->left)   node_queue.push(visit_node->left);
            if (visit_node->right)  node_queue.push(visit_node->right);
            visit_node = visit_node->next;
            node_queue.pop();
        }
    }
}

int main()
{
    input input116;

    auto vec = input116.input_vector();

    auto root = buildTreeWithVec_diff(vec);

    auto result = connect(root);

    // 输出省略掉，一个层序遍历即可
    visitNode(result);

    return 0;
}
