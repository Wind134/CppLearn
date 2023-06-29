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
    node* new_head = head;
    node* prev = head;
    node* curr = head->next;

    while (curr != NULL)
    {
        prev->next = curr->next;
        curr->next = new_head;
        new_head = curr;

        curr = prev->next;
    }
    
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
