/* 发生重复的只留一个点 */
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

ListNode* deleteDuplicates(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)   return head;
    
    // 以下两个指针构成了一个双指针
    ListNode* left = head;   // 定义一个前驱结点
    ListNode* right = head;  // right是一个配合前驱的节点

    int count = 0;  // 代表左右指针的距离，默认是1

    while(right != nullptr)
    {
        if (right->next != nullptr && right->val == right->next->val)
        {
            right = right->next;
            count++;
        }
        else
        {
            // 判断right与left之间相隔的距离
            if(count >= 1)  // 如果count大于等于1，则必定有重复，需要进行处理
            {
                ListNode* temp = right;
                right = right->next;
                ListNode* temp_head = left->next;    // 临时保存要清除的头结点
            
                temp->next = nullptr;          // 要删除的链表的最后一个指针指向空
                left->next = right;            // 链表连接

                // 释放已删除的结点空间
                while (temp_head != nullptr) 
                {
                    ListNode* to_delete = temp_head;
                    temp_head = temp_head->next;
                    delete to_delete;
                }
                // 释放完毕，重新初始化count
                count = 0;
                left = right;
            }
            else    // 进入了else，表明不需要进行释放处理，因此常规更新left以及right
            {
                right = right->next;
                left = right;
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

    ListNode* result = deleteDuplicates(list_head);

    init_head = result;

    while(init_head != nullptr)
    {
        cout << init_head->val << " ";
        init_head = init_head->next;
    }

    cout << "\nDelete Success!" << endl;

    return 0;

}