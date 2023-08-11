#include <stdio.h>
#include <stdarg.h>     // 包含使用的宏的头文件

void print_numbers(int num, ...) {
    va_list args;           // args是一个va_list宏变量
    va_start(args, num);    // 将可变参数列表(也就是...的内容)的信息存储到其中

    for (int i = 0; i < num; i++) {
        const char* value = va_arg(args, const char*);  // 参数一个一个一次传给value
        printf("%s ", value);
    }

    va_end(args);
}

int main() {
    // 在这个例子中，第一个参数5代表了可变参数的个数
    print_numbers(5, "I", "love", "you", "very", "much!");

    return 0;
}
