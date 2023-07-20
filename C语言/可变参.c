/*
初步展示了C语言的可变参
*/
#include <stdio.h>
#include <stdarg.h> // 包含可变参功能的头文件

int sum(int num, ...) {
    int result = 0;
    va_list args;   // args是可变参数类型
    va_start(args, num);    // va_start定义的是一个宏，num展示了起始的位置

    for (int i = 0; i < num; i++) {
        int value = va_arg(args, int);
        result += value;
    }

    va_end(args);
    return result;
}

// 为了加强理解，我们针对上述函数进行改进
int new_sum(int start, int num, ...) {
    int init_result = start;
    va_list args;
    va_start(args, num);  // 第二个参数最好是可变参数的前一个参数，定位可变参的起始位

    for (int i = 0; i < num; i++) {
        int value = va_arg(args, int); 
        init_result += value;
    }

    va_end(args);
    return init_result;
}

int main() {
    int total = sum(4, 1, 2, 3, 4);
    printf("Sum: %d\n", total); // 输出 Sum: 10
    
    int new_total = new_sum(4, 5, 1, 2, 3, 4, 5);
    printf("Sum: %d\n", new_total); // 输出 Sum: 19

    return 0;
}
