#include <iostream>

template <typename T>
void printValue(T value) {
    std::cout << value << std::endl;
}

int main() {
    int x = 5;
    double y = 3.14;

    printValue<int>(x);   // 显式指定模板参数类型为 int
    printValue(y);        // 隐式推导模板参数类型为 double

    return 0;
}
