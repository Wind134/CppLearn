#include <iostream>

// 示例1：使用单参数构造函数进行类型转换
class MyInt {
private:
    int value;
public:
    MyInt(int val) : value(val) {}

    int getValue() const {
        return value;
    }
};

// 示例2：使用带有explicit关键字的构造函数进行类型转换
class MyFloat {
private:
    float value;
public:
    explicit MyFloat(float val) : value(val) {}

    float getValue() const {
        return value;
    }
};

int main() {
    // 示例1：使用单参数构造函数进行类型转换
    MyInt obj1 = 42; // 使用单参数构造函数将 int 类型转换为 MyInt 类型

    std::cout << "obj1 value: " << obj1.getValue() << std::endl; // 输出: 42

    // 示例2：使用带有 explicit 关键字的构造函数进行类型转换
    // MyFloat obj2 = 3.14; // 错误！使用 explicit 构造函数时，必须显式进行类型转换
    
    MyFloat obj2(3.14);

    std::cout << "obj2 value: " << obj2.getValue() << std::endl; // 输出: 3.14

    return 0;
}
