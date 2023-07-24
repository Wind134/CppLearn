/*
题目：
- 要求我们删除倒数第n个节点的值
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


ListNode* removeNthFromEnd(ListNode* head, int n)
{
    int length = 1;
    ListNode* tagNode = head->next; 
    while (tagNode->next != nullptr)
    {
        length++;
        tagNode = tagNode->next;
    }
    // 经过上述循环获取了链表长度，我们需要释放的是第length + 1 - n个结点
    // cout << "Length: " << length << endl;

    tagNode = head; // 重新初始化为头结点
    
    for (int i = 0; i < length - n; i++)
    {
        tagNode = tagNode->next;    // tagNode变成了要释放的那个结点之前的结点
    }

    ListNode* temp = tagNode->next;
    tagNode->next = temp->next;
    delete(temp);

    return head;
}


int main()
{
    input input19;
    auto vec = input19.input_vector();

    ListNode* head = createList(vec);
    int n;
    cout << "Please input the Node to remove: ";
    cin >> n;
    removeNthFromEnd(head, n);
    outputList(head);
    return 0;
}
