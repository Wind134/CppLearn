/*
大根堆是一颗完全二叉树，每个父节点的值一定都大于等于其子节点的值；

实现一个大根堆可以使用数组，数组中第一个元素为根节点，其余元素按从上到下从左到右的顺序填充；

用C语言实现，就当复习巩固；

大根堆是一颗完全二叉树，因此我们可以方便的利用数组处理下标
*/
#include <stdio.h>
#include <stdlib.h>

// 定义一个树的节点
typedef struct maxHeap
{
    int data;
    struct maxHeap* left;
    struct maxHeap* right;
} heap;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 建立大根堆的算法
heap* buildMaxheap(int array[], int length, int index) {
    if (index >= length)    return NULL;

    heap* root = (heap*)malloc(sizeof(heap));

    root->data = array[index];
    // heap_array[index] = root;
        
    int left = 2 * index + 1, right = 2 * index + 2;
    root->left = buildMaxheap(array, length, left);
    // heap_array[left] = root->left;
    root->right = buildMaxheap(array, length, right);
    // heap_array[right] = root->right;
    if (root->left && root->left->data > root->data)  {
        swap(&(root->left->data), &(root->data));
        swap(&(array[index]), &(array[left]));
        // swap(&(heap_array[left]->data), &(heap_array[index]->data));
    }
    if (root->right && root->right->data > root->data)  {
        swap(&(root->right->data), &(root->data));
        swap(&(array[index]), &(array[right]));
        // swap(&(heap_array[right]->data), &(heap_array[index]->data));
    }

    return root;
}

// 插入一个大根堆的算法，假设已经存在一个大根堆，我插入一个元素，插入之后仍然是一个大根堆
// 首先应该是先将元素放入末尾，是否需要数组的长度信息，不然不好遍历
// 基于层次遍历找到第一个叶节点(除了层次遍历是否还有更可靠的办法)
// 可以在建立大根堆的时候维护一个数组，数组内的元素即为指向heap节点的指针
// 但是这样就只能保证插入一次，还不算一个优秀的算法
// 引入队列或许好不少
heap* insertElem(int elem, heap* heap_array[]) {
    // if (!root) {    // 为空的情况
    //     root->data = elem;
    //     root->left = NULL;
    //     root->right = NULL;
    //     return;
    // }

    heap* new_node = (heap*)malloc(sizeof(heap));
    new_node->data = elem;
    new_node->left = NULL;
    new_node->right = NULL;


    int begin = 0;
    while (heap_array[2 * begin + 1] && heap_array[2 * begin + 2]) {
        begin++;
    }

    if (!heap_array[2 * begin + 1]) heap_array[begin]->left = new_node;
    else    heap_array[begin]->right = new_node;

    if (heap_array[begin]->data >= new_node->data) return heap_array[0];

    else {  // 否则就要一层一层向上了
        swap(&(heap_array[begin]->data), &(new_node->data));
        begin = begin / 2;
        while (begin > 0 || heap_array[begin / 2]->data < heap_array[begin]->data) {
            swap(&(heap_array[begin]->data), &(heap_array[begin / 2]->data));
            begin /= 2;
        }
        return heap_array[0];
    }
}

void preOrder(heap* root) {
    if (!root)  return;

    printf("%d ", root->data);

    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(heap* root) {
    if (!root)  return;
    inOrder(root->left);

    printf("%d ", root->data);


    inOrder(root->right);
}


int main()
{
    int len;
    int* array; // 存储数组元素的首地址
    printf("Please input the length of array: ");
    scanf("%d", &len);
    heap* heap_array[len];

    array = (int *)malloc(len * sizeof(int));

    if (!array) {
        printf("Allocation failed!\n");
        return -1;
    }

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &array[i]);
    }

    heap* root = buildMaxheap(array, len, 0);

    preOrder(root);

    printf("\n");

    inOrder(root);
    
    return 0;
}
