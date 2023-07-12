/* 
与上题不同的是，这道题下的二叉树是一颗一般二叉树
具体方案是：先设计一个函数，将每一个结点的左右结点连起来

其次通过一个循环，基于本层处理下一层的连接

- Tips: 做法是对了，尝试再优化下if else？
*/
#include "../headfile/io_for_leetcode.h"
#include <queue>
using namespace std;
// 特殊结点的数据结构
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

Node* buildTreeWithVec(const std::vector<int>& nums, int index = 0) // 给一个默认参数不影响什么吧，这是默认的起始位置
{
    if(index > nums.size() - 1 || nums[index] == -1)    return nullptr; // -1代表该节点不存在(注意权值为-1的情况即可)

    Node* root = new Node(nums[index]);

    root->left = buildTreeWithVec(nums, 2 * index + 1);

    root->right = buildTreeWithVec(nums, 2 * index + 2);

    root->next = nullptr;

    return root;
}

// 这个函数用来连接所有的左右节点
void connect_l_r_child(Node* root)
{
    if (root->left && root->right)
    {
        root->left->next = root->right;
        connect_l_r_child(root->left);
        connect_l_r_child(root->right);
    }
    else if (root->left)   connect_l_r_child(root->left);
    else if (root->right)   connect_l_r_child(root->right);
    else return;
}

// 连接各结点
Node* connect(Node* root) {
    // 空结点的情况
    if (!root)  return nullptr;

    connect_l_r_child(root);    // 该函数使得所有结点的左右孩子都连接了

    Node* begin = root;
    if (root->left) begin = root->left;
    else if (root->right)   begin = root->right;
    else return root;

    while (begin)   // 每一行的begin，只要该begin不为空即可
    {
        auto prev = begin;
        auto curr = begin->next;
        bool tag = true;    // 初始值代表begin没更改过，这个标志位就是为了少一个循环而设计
        // 这个while循环能够成功串联下一行非左右孩子关系的所有节点
        if (prev->left && tag) {
            begin = prev->left;
            tag = false;
        }
        else if (prev->right && tag)
        {
            begin = prev->right;
            tag = false;
        }
        else ;
        while (curr) // 只要同一行的next不为空，到这里可以保证该层已经是完整连接起来的链表了
        {
            // 这部分更新begin节点
            if (curr->left && tag) {
            begin = curr->left;
            tag = false;
            }
            else if (curr->right && tag)
            {
                begin = curr->right;
                tag = false;
            }
            else ;

            // 如果prev没有左右孩子结点，更新prev结点
            if (!prev->left && !prev->right)    prev = curr;

            // 这部分else包括了左右孩子都有的情况
            else if (prev->right) {
                if (curr->left) prev->right->next = curr->left;

                if (!curr->left && curr->right) prev->right->next = curr->right;
                if (curr->left || curr->right) prev = curr;
            }
            // 最后一个情况只能是只有左孩子了
            else {
                if (curr->left) prev->left->next = curr->left;

                if (!curr->left && curr->right) prev->left->next = curr->right;

                if (curr->left || curr->right) prev = curr;
            }
            curr = curr->next;
        }
        if (tag)    return root;
    }
    return root;
}

// 这个函数实现了对该类结点的访问
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

    auto root = buildTreeWithVec(vec);

    auto result = connect(root);

    // 输出省略掉，一个层序遍历即可
    visitNode(result);

    return 0;
}
