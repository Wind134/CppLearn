/* 删除倒数第n个结点，是否需要获取整个结点的长度呢？ */
#include <iostream>
using namespace std;

// 定义单链表结点
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

ListNode* createListNode(ListNode* head, int array[], int size)
{
    ListNode* movePtr = new ListNode(); // 创建一个不断移动的指针，以指示创建的结点位置
    movePtr->next = head;       // 嘿嘿，指向头结点
    for (int i = 0; i < size; i++)
    {
        ListNode* newNode = new ListNode(array[i]); // 每一个新结点的指针指向的都是nullptr
        movePtr->next->next = newNode;
        movePtr->next = newNode;
    }
    return head;
}

void visitListNode(ListNode* head)
{
    ListNode* moveNode = head;
    while (moveNode->next != nullptr)
    {
        cout << moveNode->next->val << " ";
        moveNode = moveNode->next;
    }
}

int main()
{
    int nums;
    cout << "Please input array nums: ";
    cin >> nums;
    int array[nums];
    int num;
    cout << "Please input array num: ";
    for (int i = 0; i < nums; i++)
    {
        cin >> num;
        array[i] = num;
    }
    ListNode* head = new ListNode();
    createListNode(head, array, nums);
    visitListNode(head);
    int n;
    cout << "\nPlease input the Node to remove: ";
    cin >> n;
    removeNthFromEnd(head, n);
    visitListNode(head);
    return 0;
}
