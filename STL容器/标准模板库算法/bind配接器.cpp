#include <iostream>
#include <functional>
using namespace std::placeholders;


// 原始函数
int add(int a, int b) {
    return a + b;
}

int main() {
    

    // auto g = bind(f, a, b, _2, c, _1);	// 代表g是有两个参数的可迭代对象
    // 对于g而言，即g(_1, _2); -> 映射为了
    // f(a, b, _2, c, _1);
    // 那么对g(X, Y)的调用等价于
    // f(a, b, Y, c, X);
    // 因此针对下面这个例子，std::bind(add, 2, _2)=>add2(_2)->add(2, _2)，这是不合法的，因为根本没用到占位符_1
    // 而是bind为->std::bind(add, 2, _1)=>add2(_1)->add(2, _1)，然后可以正确调用add(2, 3)
    auto add2 = std::bind(add, 2, _1);  // 绑定add函数的第一个参数为2
    int result = add2(3);  // 调用绑定后的函数对象
    std::cout << "Result: " << result << std::endl;

    return 0;
}
