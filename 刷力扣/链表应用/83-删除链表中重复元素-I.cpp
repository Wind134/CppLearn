/*
题目：
- 发生重复的只留一个


*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* deleteDuplicates(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)   return head;
    
    // 以下两个指针构成了一个双指针
    ListNode* left = head;   // 定义一个前驱结点
    ListNode* right = head;  // right是一个配合前驱的节点，他会不断的移动

    while(right != nullptr)
    {
        if (right->next != nullptr && right->val == right->next->val)
        {
            right = right->next;
        }
        else
        {
            if (left != right)   // 这个if条件表明要进行删除处理
            {
                if(head->val == head->next->val)    // 头结点开始就有重复项则单独处理
                {
                    ListNode* temp = head;
                    while (temp != right)
                    {
                        ListNode* to_delete = temp->next;
                        delete(temp);
                        temp = to_delete;
                    }
                    head = right;            // 更新头结点
                }
                else    // 常规情况
                {
                    ListNode* temp = left->next;
                    while (temp != right)
                    {
                        ListNode* to_delete = temp->next;
                        delete(temp);
                        temp = to_delete;
                    }
                    left->next = right;            // 链表连接
                }
            }
            left = right;   // 将left与right再次保持一致
            right = right->next;    // 处理下一个节点
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