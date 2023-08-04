#include <stdio.h>
#include <stdlib.h>

typedef struct Node // 通过typedef简化写法的步骤
{
    int data;
    struct Node* next;
} node;


void visitList(node* head)
{
    node* move = head;
    while(move != NULL)
    {
        printf("%d ", move->data);
        move = move->next;
    }
}

node* reverseList(node* head)   // 传入的头结点是要翻转的链表节点
{
    node* point_to_head = (node*)malloc(sizeof(node));

    node* move = head;

    if (move != NULL)
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = move->data;
        new_node->next = NULL;
        point_to_head->next = new_node;
        move = move->next;
    }
    while (move != NULL)
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = move->data;
        new_node->next = point_to_head->next;
        point_to_head->next = new_node;
        move = move->next;
    }

    node* result = point_to_head->next;

    free(point_to_head);

    return result;
    
}

node* reverseList_new_method(node* head)   // 传入的头结点是要翻转的链表节点，该方法是直接基于链表原地修改
{
    node* dummy = (node*)malloc(sizeof(node));   // 哑指针，永远指向头结点

    // 假设下面这个head必不空
    node* curr = head;    // curr的初始结点，也是永远不变的那个节点
    dummy->next = curr;
    while (curr->next)
    {
        node* next_node = curr->next->next;     // ->1->2->3为例，这一步保存了3
        curr->next->next = dummy->next;         // curr下一个结点要指向之前的头结点，也就是2指向1
        dummy->next = curr->next;               // 设定好新的头结点
        curr->next = next_node;                 // 接起来了
    }

    node* new_head = dummy->next;

    free(dummy);

    return new_head;
}



node* createList(int a[], int size)
{
    node* head = (node*)malloc(sizeof(node));

    node* move = head;

    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            node* new_node = (node*)malloc(sizeof(node));
            move->data = a[i];
            move->next = new_node;
            move = move->next;
        }
        else
        {
            move->data = a[i];
            move->next = NULL;
        }            
    }

    return head;
}


int main()
{
    int length;
    printf("Please input the length of array: ");
    scanf("%d", &length);

    int array[length];

    for (int i = 0; i < length; i++)    scanf("%d", &array[i]);

    node* head = createList(array, length);

    printf("------------------------\n");

    visitList(head);

    printf("\nList Established!\n");

    node* reverse_head = reverseList(head);
    
    visitList(reverse_head);

    printf("\nList Reversed Success With Method1!\n");

    node* another_reverse_head = reverseList_new_method(head);

    visitList(another_reverse_head);

    printf("\nList Reversed Success With Method2!\n");

    return 0;
    
}
