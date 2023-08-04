/*
题目：
- 要求我们删除倒数第n个节点的值

思路：
- 直接的思路就是遍历两次，定位到倒数第k个结点；
- 但是有一种更优化的思路就是，设定快慢两个指针，让快指针先走k - 1次
- 如果快指针还没到最后一个结点，接下来慢指针和快指针同步行走，直到快指针遍历到链表的最后一个结点
- 如果刚好到了最后一个结点，直接删除慢指针所对应的那个结点

- 题目已经确保n小于等于结点个数
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* slowNode = new ListNode(0, head); 
    ListNode* fastNode = head; 
    for (int i = 1; i < n && fastNode->next; ++i)   fastNode = fastNode->next;

    if (!fastNode->next) {  // 直接返回
        slowNode->next = head->next;
        delete head;
        auto new_node = slowNode->next;
        delete slowNode;
        return new_node;
    }
    else {
        while (fastNode->next) {
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }
    }

    ListNode* temp = slowNode->next;
    slowNode->next = temp->next;
    delete(temp);
    return head;
}


int main()
{
    input input19;
    auto vec = input19.input_vector();

    ListNode* head = createList(vec);
    outputList(head);
    int n;
    cout << "Please input the Node to remove: ";
    cin >> n;
    ListNode* new_node = removeNthFromEnd(head, n);
    outputList(new_node);
    return 0;
}
