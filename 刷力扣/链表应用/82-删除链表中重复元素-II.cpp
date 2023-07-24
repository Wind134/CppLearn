/*
题目：
- 发生重复的一律删除
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* deleteDuplicates(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)   return head;
    ListNode* left = head;
    ListNode* right = head;     // right是一个配合前驱的节点
    ListNode* left_prev = nullptr;

    while(right != nullptr)
    {
        if (right->next != nullptr && right->val == right->next->val)
        {
            right = right->next;
        }
        else
        {
            if (left != right && left->val == right->val)  // 需要进行节点的删除处理
            {
                if (head->val == head->next->val)   // 处理头结点的特殊情况
                {
                    ListNode* temp1 = head;
                    ListNode* temp2 = right->next;
                    if (temp2 == nullptr)   return nullptr;

                    while (temp1 != temp2)
                    {
                        ListNode* to_delete = temp1->next;
                        delete(temp1);
                        temp1 = to_delete;
                    }
                    head = temp2;            // 更新头结点
                    right = temp2;
                    left = right;
                }
                else
                {
                    ListNode* temp1 = left;
                    ListNode* temp2 = right->next;

                    while (temp1 != temp2)
                    {
                        ListNode* to_delete = temp1->next;
                        delete(temp1);
                        temp1 = to_delete;
                    }
                    left_prev->next = temp2;
                    right = temp2;
                    left = right;
                }
            }
            else
            {
                left_prev = left;
                right = right->next;
                left = right;
            }
        }
    }

    return head;
}

int main()
{
    input input82;
    auto vec = input82.input_vector();

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