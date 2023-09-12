/**
 * 该例子展示的是在类的成员函数中返回一个shared_ptr智能指针的操作做法；
 * 我们不能直接返回this，否则需要面对悬空指针的问题，也就是对同一片内存空间释放两次；
 */
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {}

    // 返回一个 shared_ptr 指向 MyClass 对象
    // 由于该函数是构造了一个新的对象，因此使用不会报错
    // 我们再设计一个类似，但必然会报错的成员函数
    std::shared_ptr<MyClass> getShared() {
        return std::make_shared<MyClass>(data);
    }

    std::shared_ptr<MyClass> badGetShared() {
        return std::shared_ptr<MyClass>(this);
    }

    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

int main() {
    std::shared_ptr<MyClass> my_p(new MyClass(10));
    
    // 获取一个共享指针指向 obj
    std::shared_ptr<MyClass> sharedObj = my_p->getShared();

    // 错误的方式，这样显然会报错
    std::shared_ptr<MyClass> badWayGet = my_p->badGetShared();

    // 共享指针可以在多处使用 
    sharedObj->printData();

    // 当 sharedObj 超出作用域时，obj 仍然会被销毁
    return 0;
}
