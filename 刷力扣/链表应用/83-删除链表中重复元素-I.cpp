/*
题目：
- 发生重复的只留一个；

思路：逐个遍历，但是会采用双指针；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr)   return head;    // 考虑了空链表以及只有一个结点的特殊情况
    
    // 以下两个指针构成了一个双指针
    ListNode* left = head;   // 定义一个前驱结点
    ListNode* right = head;  // right是一个配合前驱的节点，他会不断的移动

    while(right != nullptr)
    {
        if (right->next != nullptr && right->val == right->next->val)
        {
            right = right->next;
        }
        else    // right要么到了最后一个结点，要么到了最后一个与left结点值相同的那个结点
        {
            if (left != right)   // 这个if条件表明要进行删除处理
            {
                auto delete_head = left->next;  // 临时保存left指向的下一个结点，这个子链表后续要删除
                left->next = right->next;       // left要保留，且下一个结点指向right的下一个结点
                right->next = nullptr;          // 子链表的最后一个结点指向空
                // 删除操作，迭代删除
                while (delete_head) {
                    auto temp_head = delete_head->next;
                    delete delete_head;
                    delete_head = temp_head;
                }
            }
            right = left->next;    // 处理下一个节点
            left = right;
        }
    }

    return head;
}


int main()
{
    input input83;
    auto vec = input83.input_vector();

    ListNode* list_head = createList(vec);

    // 测试建立是否成功
    ListNode* init_head = list_head;

    while(init_head != nullptr)
    {
        cout << init_head->val << " ";
        init_head = init_head->next;
    }

    cout << "\nSuccess Established!" << endl;

    ListNode* result = deleteDuplicates(list_head);

    outputList(result);

    cout << "Delete Success!" << endl;

    return 0;
}