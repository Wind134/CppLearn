/* 这份源码很清晰的展示了函数对象的使用 */
#include <iostream>
#include <functional>   // 包含函数对象的头文件

// 函数1：返回类型为int，带两个整数参数
int add(int a, int b) {
    return a + b;
}

// 函数2：返回类型为void，不带参数
void printHello() {
    std::cout << "Hello!" << std::endl;
}

// Lambda表达式：返回类型为float，带一个整数参数
auto multiply = [](int x) -> float {
    return x * 2.5f;
};

int main() {
    // 创建std::function对象，并存储不同类型的可调用对象
    std::function<int(int, int)> func1 = add;
    std::function<void()> func2 = printHello;
    std::function<float(int)> func3 = multiply;

    // 调用并输出结果
    int result1 = func1(2, 3);
    std::cout << "Result1: " << result1 << std::endl;

    func2();

    float result3 = func3(5);
    std::cout << "Result3: " << result3 << std::endl;

    return 0;
}
