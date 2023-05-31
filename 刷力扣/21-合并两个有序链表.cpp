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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)   // 都不带指向头节点的指针
{
    if(list1 == nullptr)    return list2;
    if(list2 == nullptr)    return list1;
    ListNode* list = new ListNode();    // 新链表的头节点
    ListNode* list1Node = list1;
    ListNode* list2Node = list2;
    if (list1Node->val < list2Node->val)
    {
        list = list1Node;
        list1Node = list1Node->next;
    }
    else
    {
        list = list2Node;
        list2Node = list2Node->next;
    }

    ListNode* listNode = new ListNode();
    listNode->next = list;

    while (list1Node != nullptr && list2Node != nullptr)
    {
        if (list1Node->val < list2Node->val)
        {
            listNode->next->next = list1Node;
            listNode->next = list1Node;
            list1Node = list1Node->next;
        }
        else
        {
            listNode->next->next = list2Node;
            listNode->next = list2Node;
            list2Node = list2Node->next;
        }
    }
    if(list1Node == nullptr)
    {
        while(list2Node != nullptr)
        {
            listNode->next->next = list2Node;
            listNode->next = list2Node;
            list2Node = list2Node->next;
        }   
    }

    if(list2Node == nullptr)
    {
        while(list1Node != nullptr)
        {
            listNode->next->next = list1Node;
            listNode->next = list1Node;
            list1Node = list1Node->next;
        }
    }
    return list;
}

int main()
{
    int nums1;
    cout << "Please input array1 nums: ";
    cin >> nums1;

    int nums2;
    cout << "Please input array2 nums: ";
    cin >> nums2;
    
    int array1[nums1];
    int num;
    int array2[nums2];

    cout << "Please input array1: ";
    for (int i = 0; i < nums1; i++)
    {
        cin >> num;
        array1[i] = num;
    }


    cout << "Please input array2: ";
    for (int i = 0; i < nums2; i++)
    {
        cin >> num;
        array2[i] = num;
    }
    ListNode* list1 = new ListNode(array1[0]);
    createListNode(list1, array1, nums1);
    
    visitListNode(list1);
    cout << endl;
    
    ListNode* list2 = new ListNode(array2[0]);
    createListNode(list2, array2, nums2);

    ListNode* mergeList = mergeTwoLists(list1, list2);
    visitListNode(mergeList);

    return 0;
}