#include <cstdio>

#define PRINT_ARGS(format, ...) printf(format, ##__VA_ARGS__)   // 不加'##'也可以，但是在未传递可变参数的前提下将产生错误，因此建议加上##

int main() {
    PRINT_ARGS("The numbers are: %d, %d, %d\n", 1, 2, 3);
    PRINT_ARGS("The colors are: %s, %s, %s, %s\n", "red", "green", "blue", "yellow");
    return 0;
}

