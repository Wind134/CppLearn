/* 给你一个链表的头节点head，旋转链表，将链表每个节点向右移动k个位置。 */
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
    if (head == nullptr)    return nullptr;
    if (k == 0) return head;
    // 给传入的链表尾部添加一个指向头结点的指针
    ListNode* move_point = new ListNode();  // new一个结点，用来指向链表中的每个结点

    int count = 1;  // 获取结点数量

    move_point->next = head;        // 先指向头结点
    while(move_point->next->next != nullptr)
    {
        count++;
        move_point->next = move_point->next->next;
    }

    if (k % count == 0) return head;    // 倍数则返回本身即可

    move_point->next->next = head;  // 将最后一个结点指向头结点，完成了循环单链表的创建

    // 继续利用move_point
    // 再接下来，直接改变head就好了，同时要销毁最后一个结点指向头结点的那个指针

    for(int i = 0; i < count - k % count + 1; i++)
    {
        move_point->next = move_point->next->next;
    }

    ListNode* new_head = move_point->next;

    move_point->next = new_head;

    // 最后的任务就是把指向该头结点的指针去掉
    for (int i = 1; i < count; i++)
    {
        move_point->next = move_point->next->next;
    }

    move_point->next->next = nullptr;

    delete(move_point);

    return new_head;

}

ListNode* createList(ListNode* head, const vector<int>& input_array)    // 不带指向头结点指针的链表
{
    ListNode* move_point = new ListNode();
    move_point->next = head;
    for (auto it = input_array.begin(); it != input_array.end(); it++)
    {
        move_point->next->val = *it;

        if (it != input_array.end() - 1)    // 在处理最后一个元素之前，每次都需要建立一个新结点
        {
            ListNode* new_node = new ListNode(); // 建立一个新结点

            move_point->next->next = new_node;  // 指针指向的结点又指向这个新结点

            move_point->next = new_node;        // 更新move_point的指向
        }
    }
    delete(move_point);

    return head;
    
}

int main()
{
    vector<int> input;  // 根据输入的数组创建链表

    int input_data;

    while (cin >> input_data)
    {
        input.push_back(input_data);
        if(cin.get() == '\n')   break;
    }

    cout << "Please input k value: ";
    int k;

    cin >> k;

    ListNode* init_head = new ListNode();

    ListNode* list_head = createList(init_head, input);

    // 测试建立是否成功
    init_head = list_head;

    while(init_head != nullptr)
    {
        cout << init_head->val << " ";
        init_head = init_head->next;
    }

    cout << "\nSuccess Established!" << endl;

    ListNode* result = rotateRight(list_head, k);

    init_head = result;

    while(init_head != nullptr)
    {
        cout << init_head->val << " ";
        init_head = init_head->next;
    }

    cout << "\nRotate Success!" << endl;

    return 0;

}