/* 
与上题不同的是，这道题下的二叉树是一颗一般二叉树
具体方案是：先设计一个函数，将每一个结点的左右结点连起来

其次通过一个循环，基于本层处理下一层的连接

- Tips: 做法是对了，尝试再优化下if else？
- 思路应该包括了诸多重复的行为，优化一下
- 首先，那个递归应该不太有必要，我们只要一层一层遍历，如果有左右孩子就先将他们连起来
- 用队列处理这个问题是一个最直观的思路，但是队列会占用空间复杂度
- 下面这个复杂的方法初衷就是为了不用队列；
- 首先，设计的思路是一层一层处理，也就是一张链表一张链表处理；

- 最终写出来的效果还可以
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

Node* buildTreeWithVec_diff(const std::vector<int>& nums, int index = 0) // 给一个默认参数不影响什么吧，这是默认的起始位置
{
    if(index > nums.size() - 1 || nums[index] == -1)    return nullptr; // -1代表该节点不存在(注意权值为-1的情况即可)

    Node* root = new Node(nums[index]);

    root->left = buildTreeWithVec_diff(nums, 2 * index + 1);

    root->right = buildTreeWithVec_diff(nums, 2 * index + 2);

    root->next = nullptr;

    return root;
}


// 连接各结点
// 我之前是怎么想到这么绝妙的思路的呢？
// 我现在咋看不懂我当时的思路呢？
// ？？？
Node* connect(Node* root) {
    // 空结点的情况
    if (!root)  return nullptr;

    Node* begin = root;     // 第一条链表的第一个节点(也就是根节点)
    

    while (begin)   // 每一行的begin，只要该begin不空，说明还没遍历完
    {
        Node* prev = nullptr;   // 每到新的一层就需要更新一下prev
        auto curr = begin;    // 初始化curr为该层链表的第一个节点
        // 接下来应该是针对链表的处理，在处理时，应该在上面提前准备好获取下一个begin节点
        bool tag = false;     // 针对下一层保证只更新一次begin节点

        // 这个while循环用来处理链表
        while (curr) // 只要同一行的next不为空，到这里可以保证该层已经是完整连接起来的链表了
        {
            if (curr->left && curr->right) {
                curr->left->next = curr->right;
                if (!tag) { begin = curr->left; tag = true; }
                prev = curr;
            }
            else if (curr->left || curr->right)
            {
                if (!tag) { 
                    if (curr->left) begin = curr->left; 
                    if (curr->right) begin = curr->right; 
                    tag = true;
                }
                prev = curr;
            }
            curr = curr->next;

            if (!prev || !curr)  continue;   // 该层的连接已完成，不必再连接

            if (prev->right) {  // 左右孩子都有以及只有右孩子都这么处理
                if (curr->left) prev->right->next = curr->left;
                else if (curr->right) prev->right->next = curr->right;
                // 本来还应更新prev，但是在下一轮循环中会自动实现这一步
            }
            // 如果只有左孩子
            else if (prev->left) {
                if (curr->left) prev->left->next = curr->left;
                else if (curr->right) prev->left->next = curr->right;
            }
        }
        if (!tag)    return root;    // 如果整个一圈都没有更新过tag，显然，到了最后一行了
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

    auto root = buildTreeWithVec_diff(vec);

    auto result = connect(root);

    // 输出省略掉，一个层序遍历即可
    visitNode(result);

    return 0;
}


        // // 初始化第一个有孩子结点的根节点，将该节点赋给prev
        // if (begin->left && begin->right) {
        //     begin->left->next = begin->right;
        //     prev = begin;   // 连接下一层不同双亲节点的孩子结点，这是双亲(根)结点1
        //     begin = begin->left;    // 更新下一层链表的头结点
        // }
        // else if (begin->left || begin->right) {
        //     prev = begin;
        //     if (begin->left)    begin = begin->left;
        //     if (begin->right)    begin = begin->right;
        // }