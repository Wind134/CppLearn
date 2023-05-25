/* 不难，一个递归解决问题 */
#include <iostream>
using namespace std;

// 定义单链表结点，定义了构造函数
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createListNode(ListNode* head, int array[], int size) // 建立的是一个不带头节点的链表
{
    if( size==0 )   return nullptr;
    else
    {
        ListNode* movePtr = new ListNode(); // 创建一个不断移动的指针，以指示创建的结点位置
        movePtr->next = head;       // 嘿嘿，指向头结点
        for (int i = 1; i < size; i++)
        {
            ListNode* newNode = new ListNode(array[i]); // 每一个新结点的指针指向的都是nullptr
            movePtr->next->next = newNode;
            movePtr->next = newNode;
        }
        return head;
    }
    
}

void visitListNode(ListNode* head)
{
    ListNode* moveNode = head;
    while (moveNode != nullptr)
    {
        cout << moveNode->val << " ";
        moveNode = moveNode->next;
    }
}

ListNode* swapPairs(ListNode* head) 
{   
    // 首先处理这俩的边界情况
    if (head == nullptr)    return nullptr;
    if (head->next == nullptr)  return head;

    ListNode* swapNode = head->next;
    head->next = swapPairs(swapNode->next);
    swapNode->next = head;
    return swapNode;
}

int main()
{
    int nums;
    cout << "Please input array nums: ";
    cin >> nums;
    int num;

    int array[nums];

    cout << "Please input array: ";
    for (int i = 0; i < nums; i++)
    {
        cin >> num;
        array[i] = num;
    }

    ListNode* list = new ListNode(array[0]);
    createListNode(list, array, nums);
    
    visitListNode(list);
    cout << endl;
    

    ListNode* resultList = swapPairs(list);
    visitListNode(resultList);

    return 0;
}