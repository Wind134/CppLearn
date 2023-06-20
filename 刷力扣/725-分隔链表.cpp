/* 
* 给你一个头结点为head的单链表和一个整数k，请你设计一个算法将链表分隔为k个连续的部分。

* 每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过1。这可能会导致有些部分为null。

* 这k个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。

* 返回一个由上述k部分组成的数组。
*/
#include <iostream>
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

vector<ListNode*> splitListToParts(ListNode* head, int k)
{
    vector<ListNode*> result;
    if (head == nullptr)
    {
        for (int i = 0; i < k; i++) result.push_back(head);
        return result;
    }

    int list_size = 0;

    ListNode* count_ptr = head;
    while(count_ptr != nullptr)
    {
        list_size++;
        count_ptr = count_ptr->next;
    }

    int split_list_len = list_size / k;    // 在均分的情况下，每个子链表可以分配的长度
    int extre_len = list_size % k;         // 多出的链表结点个数

    // 那么对于这些多出的应该如何处理呢？一个一个分给前面即可，所以问题来了，代码应该怎么写
    
    vector<int> list_len(k);    // 建立一个辅助数组
    for (int i = 0; i < k; i++)
    {
        if (extre_len != 0)
        {
            list_len[i] = split_list_len + 1;
            extre_len--;
        }
        else list_len[i] = split_list_len;   // 如果整除，则可以均分
    }


    // 经过上面的处理我们得到了一个子链表长度结点数组，比如[1, 1, 1, 0, 0], [4, 3, 3]
    // 接下来一次将这些子链表的头结点加入数组，后面有用，再用之前定义的
    ListNode* move_ptr = new ListNode();
    move_ptr->next = head;


    for (int i = 0; i < k; i++)
    {   
        if (list_len[i] != 0)   // 不等于0就代表着该部分头结点一定不为空啊
        {
            result.push_back(move_ptr->next);   // 加入结果集(仅加入一次)
            int tag_count = list_len[i];

            for (int i = 0; i < tag_count && move_ptr->next->next != nullptr; i++)
            {
                if(i == tag_count - 1)
                {
                    ListNode* temp = move_ptr->next;
                    move_ptr->next = move_ptr->next->next;
                    temp->next = nullptr;
                }
                else move_ptr->next = move_ptr->next->next;
            }

        }
        else    result.push_back(nullptr);
    }
    return result;
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

    ListNode* list_head = createList(init_head, input); // 不带指向头结点的指针

    auto result = splitListToParts(list_head, k);

    for(const auto& vec : result)   // vec保存的应当是每一个链表的头结点
    {
        init_head = vec;
        while (init_head != nullptr)
        {
            cout << init_head->val << " ";
            
            init_head = init_head->next;
        }
        cout << endl;
    }
    return 0;
}


// 下面这个注释是debug之用
// ListNode* test = head;
// while (test != nullptr)
// {
//     cout << test->val << " ";
//     test = test->next;
// }

// for (auto elem : list_len)   cout << elem << " ";


// ListNode* test = move_ptr;
// while (test -> next != nullptr)
// {
//     cout << test->next->val << " ";
//     test -> next= test->next->next;
// }

// // 测试建立是否成功
// init_head = list_head;

// while(init_head != nullptr)
// {
//     cout << init_head->val << " ";
//     init_head = init_head->next;
// }

// cout << "\nSuccess Established!" << endl;


// 接下来这个while循环用来断每个子链表的链接
// while(tag_count > 0 && move_ptr->next != nullptr)
// {
//     if (tag_count == 1 && move_ptr->next != nullptr)
//     {
//         ListNode* temp_node = move_ptr->next;
//         move_ptr->next->next = nullptr;
//         move_ptr->next = temp_node->next;
//         break;
//     }
//     move_ptr->next = move_ptr->next->next;
//     tag_count--;    
// }   