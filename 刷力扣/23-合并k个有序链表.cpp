/* 难度不小 */
#include <iostream>
#include <vector>
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

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    if (lists.size() == 0)  return nullptr;

    for (int i = lists.size() - 1; i >= 0; i--)     // 清除所有为空指针的元素
    {
        if (lists[i] == nullptr)   lists.erase(lists.begin() + i);
    }
    if(lists.size() == 0)   return nullptr;

    int minIndex = 0;

    for (int i = 0; i < lists.size(); i++)
    {
        minIndex = (lists[i]->val < lists[minIndex]->val) ? i : minIndex;
    }
    // 搞定头节点
    ListNode* head = lists[minIndex];
    ListNode* pointNode = new ListNode();
    pointNode->next = head;

    lists[minIndex] = lists[minIndex]->next;
    pointNode->next->next = mergeKLists(lists);
    pointNode->next = pointNode->next->next;

    return head;
}

int main()
{
    int n;
    cout << "Please input array nums: ";
    cin >> n;
    vector<ListNode*> lists(n, new ListNode());
    for (int i = 0; i < n; i++)
    {
        int nums;
        cout << "Please input " << i + 1 << "th array nums: ";
        cin >> nums;
        int array[nums];
        cout << "Please input array: ";
        for (int j = 0; j < nums; j++)
        {
            int num;
            cin >> num;
            array[j] = num;
        }
        cout << endl;
        ListNode* listi = new ListNode(array[0]);
        createListNode(listi, array, nums);
        lists[i] = listi;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     visitListNode(lists[i]);
    //     cout << endl;
    // }
    

    cout << endl;


    ListNode* mergeList = mergeKLists(lists);
    visitListNode(mergeList);

    return 0;
}