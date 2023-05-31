// 这道题是一个很好的案例，教会我们怎么用链表的结构，帮助理解链表存储的知识
#include <iostream>
#include <vector>
using std::cin, std::cout, std::endl, std::vector;

struct ListNode {           // 定义一个链表节点
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 通过给定的数组创建一个节点
ListNode* creatNode(const vector<int> &v)
{
    ListNode* head = nullptr;
    ListNode* newnode = nullptr;    // 这个用来保存创建的节点
    for(auto it = v.begin(); it != v.end(); it++)
    {
        if(!head)   head = newnode = new ListNode(*it);
        else
        {
            newnode->next = new ListNode(*it);
            newnode = newnode->next;
        }
    }
    return head; 
} 

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode *sum = nullptr, *newNode = nullptr;      // 俩指针默认为空
    int tag = 0;       // 进位标志位，默认不进位
    while (l1 != nullptr || l2 != nullptr)
    {
        int n1 = l1?l1->val:0;
        int n2 = l2?l2->val:0;
        int sum_val = n1 + n2 + tag;  // 这是两个节点的值  
        // 接下来需要处理10进位的情况
        if (sum_val >= 10)
        {
            sum_val -= 10;
            tag = 1;
        }
        else    tag = 0;    // 否则tag值为0，即不进位
        if (!sum)   sum = newNode = new ListNode(sum_val);
        else
        {
            newNode -> next = new ListNode(sum_val);
            newNode = newNode->next;
        }
        if (l1)
            l1 = l1->next;
        if (l2)    
            l2 = l2->next;
    }
    if (tag)
        newNode->next = new ListNode(1);
    return sum;
}
        
int main()
{
    vector<int> v1;
    vector<int> v2;
    int input = 0;
    cout << "Please input array1:\t";
    while (cin >> input)
    {
        /* code */
        v1.push_back(input);
        if (cin.get()=='\n') break;
    }
    cout << "Please input array2:\t";
    while (cin >> input)
    {
        /* code */
        v2.push_back(input);
        if (cin.get()=='\n') break;
    }

    ListNode* creat_l1 = creatNode(v1);
    ListNode* creat_l2 = creatNode(v2);
    ListNode* sumNode = addTwoNumbers(creat_l1, creat_l2);
    cout << "The last result is:\t";
    while (sumNode)
    {
        cout << sumNode->val << " \n"[(!sumNode->next)];
        sumNode = sumNode->next;
    }
    return 0;
}        