/*
- 通过传入指针参数可以改变指向参数指向的值，记住，是可以改变的，但是只能通过取地址符改变；
    -- 如下面的函数1：changeValueByPointer_1，通过改变指针的值是无法改变的；
    -- 如下面的函数2：changeValueByPointer_2，通过'*'运算符实现了改变；
- 还有一种方式是通过修改指向指针的指针变量，从而实现了值的修改
    -- 如下面的函数：modifyPointerWithPointerToPointer_1
    -- 但是函数：modifyPointerWithPointerToPointer_2则衍生出了一个值得思索的结果，这个问题值得思考
    -- 目前还无法解释
*/
#include <iostream>

void changeValueByPointer_1(int* ptr) {
    int v1 = 350;
    ptr = &v1;
}

void changeValueByPointer_2(int* ptr) {
    int v1 = 350;
    *ptr = v1;
}

void modifyPointerWithPointerToPointer_1(int** ptr) {
    int d= 450;
    *ptr = &d;
}

void modifyPointerWithPointerToPointer_2(int** ptr) {
    int* p1 = new int(550);
 
    ptr = &p1;

    delete p1;  // 释放p1指向的那片内存空间
}

int main() {
    int* myPtr = new int(100);  // 动态分配一个int类型的对象，并将其地址赋给myPtr

    changeValueByPointer_1(myPtr);  // 通过修改指针的值无法改变指针指向对象的值
    std::cout << *myPtr << std::endl;  // 输出指针指向的对象的值，应该还是100
    
    changeValueByPointer_2(myPtr);  // 通过取值运算符，改变了指针指向对象的值
    std::cout << *myPtr << std::endl;  // 输出指针指向的对象的值，应该变成了350

    modifyPointerWithPointerToPointer_1(&myPtr);  // 通过指向指针的指针修改指针指向的变量的值
    std::cout << *myPtr << std::endl;  // 输出指针指向的对象的值，应该是450
    
    modifyPointerWithPointerToPointer_2(&myPtr);  // 通过指向指针的指针修改指针指向的变量的值
    std::cout << *myPtr << std::endl;  // 输出指针指向的对象的值，应该还是450，但输出的值是32766，为什么？

       
    return 0;
}