/* 这个例子展示了private部分的虚函数，以及展示了对该权限下虚函数的重写 */
#include <iostream>

class Base {
private:
    virtual void privateVirtualFunction() {
        std::cout << "Base::privateVirtualFunction()" << std::endl;
    }

public:
    // 调用虚函数
    void publicFunction() {
        privateVirtualFunction();
    }
};

class Derived : public Base {
private:
    // 派生类对虚函数进行了重写，这个操作是完全没问题的
    void privateVirtualFunction() override {
        std::cout << "Derived::privateVirtualFunction()" << std::endl;
    }
};

int main() {
    Base base;
    base.publicFunction();  // 调用 Base::privateVirtualFunction()

    Derived derived;
    derived.publicFunction();  // 调用Derived::privateVirtualFunction()

    return 0;
}
