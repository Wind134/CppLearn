/*
题目：
- k个结点之间每每交换

思路：
- 不难，一个递归解决问题
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;

int getsize(ListNode* head)
{
    int size = 0;
    ListNode* curr = head;
    while (curr != nullptr)
    {
        size++;
        curr = curr->next;
    }
    return size;
}

ListNode* reverseKGroup(ListNode* head, int k)  // head是带头节点的 
{   
    // 首先处理这俩的边界情况，如果头指针为空，则直接返回空
    if (head == nullptr)    return nullptr;

    int count = getsize(head);  // 用于统计结点个数

    ListNode* dummy = new ListNode(0, head);   // 哑指针，永远指向头结点

    if (count < k)  return head;    // 链表长小于要交换的结点数，则按原样返回头节点

    else    // 反转这k个结点
    {
        ListNode* curr = head;    // curr的初始结点，也是永远不变的结点...
        for (int i = 1; i < k; i++)
        {
            ListNode* next_node = curr->next->next; // ->1->2->3为例，这一步保存了3
            curr->next->next = dummy->next;         // curr下一个结点要指向之前的头结点，也就是2指向1
            dummy->next = curr->next;               // 设定好新的头结点
            curr->next = next_node;                 // 接起来了
        }
        // 此时的curr->next刚好就是下一个K组的头节点，可以为后续调用递归做准备
        curr->next = reverseKGroup(curr->next, k);
    }
    head = dummy->next;
    delete dummy;

    return head;
}

int main()
{
    input input25;
    auto vec = input25.input_vector();

    int k;
    cout << "Please input swap nums: ";
    cin >> k;
    
    ListNode* list = createList(vec);

    ListNode* resultList = reverseKGroup(list, k);
    outputList(resultList);

    return 0;
}