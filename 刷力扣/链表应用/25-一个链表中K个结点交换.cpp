/* 不难，一个递归解决问题 */
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

    if (count < k)  return head;    // 链表长小于要交换的结点数，则按原样返回头节点

    else    // 建立一个新链表，采用头插法即可
    {
        ListNode* dummy = new ListNode();

        // 下面这个head必不空
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        for (int i = 1; i < k; i++) // 翻转完成，此时的头节点是tempPoint->next
        {
            ListNode* nextNode = curr->next->next;   // 临时保存上一个头结点
            curr->next->next = prev->next;                 // 指向新的头结点
            prev->next = curr->next;       // 新的头节点指向上一个头节点
            curr->next = nextNode;                      // 这样就串起来了
        }

        head = dummy->next;

        // 此时的head结点刚好就是下一个K组的头节点，可以为后续调用递归做准备
        // 再执行一次循环，转到翻转好的链表的最后一个结点
        ListNode* newPartListNode = head;
        for (int i = 1; i < k; i++)
        {
            newPartListNode = newPartListNode->next;
        }

        newPartListNode->next = reverseKGroup(curr->next, k);

        delete dummy;
        return head;
    } 
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