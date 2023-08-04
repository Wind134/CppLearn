/*
题目：
- 发生重复的一律删除。

思路：
- 我们设定一个临时变量，用于保存结点值，该值的初始值为第一个结点的值，然后不断去遍历；
- 遍历结点，如果结点的值与临时变量保存的值相同，那么就需要删除该结点了；
- 如果下一个不同，则更新临时变量的值，直到遍历结束；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* deleteDuplicates(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)   return head;
    ListNode* prev = new ListNode(0, head); // 指向head
    ListNode* curr = prev;  // 移动的指针

    int val = head->val;

    while(curr->next && curr->next->next)   // 循环时要保证至少有两个结点
    {
        if (curr->next->val == curr->next->next->val)
        {
            int x = curr->next->val;
            while (curr->next && curr->next->val == x) {
                auto temp_node = curr->next->next;  // 临时保存要删除的结点的下一个结点
                delete curr->next;
                curr->next = temp_node;
            }
        }
        else    // 要么到了最后一个结点，要么到了最后一个与left相同的元素的结点
        {
            curr = curr->next;
        }
    }

    auto new_head = prev->next;
    delete prev;

    return new_head;
}

int main()
{
    input input82;
    auto vec = input82.input_vector();

    ListNode* list_head = createList(vec);

    ListNode* result = deleteDuplicates(list_head);

    outputList(result);

    return 0;

}