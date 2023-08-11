#include <iostream>

// 下面是一个类模板，value_type是一个类型的表示
// 该类中又包含一个类Inner，其中又定义了一个value_type为T*类型
template <typename T>
struct MyContainer {
    using value_type = T;

    struct Inner {
        using value_type = T*;
    };
};

// 这是一个函数模板，将Container本身作为一个类型
template <typename Container>
void printValueType() {
    // 使用typename标识嵌套的类型别名value_type
    // 如果没有typename关键字，没人知道value_type是关键字还是
    // 成员变量，同时没有该关键字，编译器默认会将其视为一个静态成员
    // 变量
    typename Container::value_type value;

    std::cout << "Type: " << typeid(value).name() << std::endl;
}

int main() {
    printValueType<MyContainer<int>>();  // 当容器类型为MyContainer时，输出Type:int(实际输出i)

    printValueType<MyContainer<double>::Inner>();  // 当容器类型为Inner时，输出Type:double*(实际输出Pd，一种命名约定而已)

    return 0;
}
