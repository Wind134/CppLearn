/*
* 给你一个链表的头节点head和一个特定值x，请你对链表进行分隔，使得所有小于x的节点都出现在大于或等于x的节点之前。

* 你应当保留两个分区中每个节点的初始相对位置。
*/
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

ListNode* partition(ListNode* head, int x)
{
    if (head == nullptr)    return nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = head;

    // 经过这个while循环过后，我们定位到了第一个大于等于x的结点
    while (curr != nullptr && curr->val < x)
    {
        prev = curr;
        curr = curr->next;
    }


    // 在这个地方，curr所代表的结点为第一个大于等于x的值的结点
    // 而prev代表的是该结点之前的那个结点
    ListNode* move = curr;
    while (move != nullptr)
    {
        if (move->next != nullptr && move->next->val >= x)  // 在该结点下一个指针不为空的前提下进行判断
        {
            move = move->next;
        }
        else if (move->next == nullptr) // 代表到了最后一个结点
        {
            break;
        }
        else    // 这部分代表的情况是：move->next->val < x
        {
            ListNode* temp = move->next->next;
            if (prev == nullptr)    // 如果prev为空，说明头结点已经是大于等于的了，需要特殊处理
            {
                move->next->next = head;
                head = move->next;
                move->next = temp;
                
                // 更新prev 
                prev = head;
            }
            else
            {
                move->next->next = prev->next;
                prev->next = move->next;
                move->next = temp;

                // 最后别忘记更新一下prev
                prev = prev->next;
            }
        }
    }

    return head;
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

    int target;

    cout << "Input the target: ";
    cin >> target;

    ListNode* result = partition(list_head, target);

    init_head = result;

    while(init_head != nullptr)
    {
        cout << init_head->val << " ";
        init_head = init_head->next;
    }

    cout << "\nProcess Success!" << endl;

    return 0;

}