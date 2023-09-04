#include <iostream>
#include <utility>

// 用于测试的函数
void OtherFunction(int&& value) {
    std::cout << "Rvalue reference: " << value + 1 << std::endl;
}

void OtherFunction(const int& value) {
    std::cout << "Lvalue reference: " << value << std::endl;
}

// 使用模板和右值引用推断参数类型并进行完美转发
template <typename T>
void ForwardingFunction(T&& arg) {
    // 在这里可以对参数 arg 做一些操作
    // 然后将它传递给其他函数

    // 假设这里调用了其他函数，将参数 arg 原封不动地传递下去
    OtherFunction(std::forward<T>(arg));
}

int main() {
    int x = 42;
    ForwardingFunction(x);  // Lvalue reference
    ForwardingFunction(123); // Rvalue reference

    return 0;
}
