/*
- 这个例子展示了移动构造函数的使用：
    -- 移动构造函数的参数必须是右值形式
    -- 移动构造函数适用于一个拥有动态分类资源的类(比如指针指向的内存)
*/
#include <iostream>

class MyResource {
private:
    int* data;
public:
    // 默认构造函数
    MyResource() : data(nullptr) {}

    // 带参数的构造函数，用于分配资源
    MyResource(int size) {
        data = new int[size];   // 分配一个size大小的数组
        std::cout << "Resource allocated." << std::endl;
    }

    // 移动构造函数，将资源转移到新对象上
    // 观察参数，必须是右值形式，同时noexcept则是告知编译器这个过程中不会有意外
    MyResource(MyResource&& other) noexcept {
        data = other.data;  // 把指针拿过来，现在是我的了
        other.data = nullptr;   // 原对象指针置空
        std::cout << "Resource moved." << std::endl;
    }

    // 移动赋值运算符，将资源转移到当前对象上
    MyResource& operator=(MyResource&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            other.data = nullptr;
            std::cout << "Resource moved assignment." << std::endl;
        }
        return *this;
    }

    // 析构函数，释放资源
    ~MyResource() {
        delete[] data;
        std::cout << "Resource deallocated." << std::endl;
    }
};

int main() {

    std::cout << "Show the move constructor: \n";
    // 创建一个临时对象，并移动资源到新对象上
    MyResource temp(10);

    // move函数移除了temp的左值属性
    MyResource obj(std::move(temp));

    MyResource obj1(10);
    MyResource obj2(5);

    std::cout << "---------------------------------- \n";
    std::cout << "Show the move assignment operator: \n";
    // 使用移动赋值运算符将obj2的资源移动到obj1
    obj1 = std::move(obj2);

    // 输出应该只会看到三次构造函数的执行，因为obj来源于拷贝构造
    // 最终会执行四个析构函数，依次是obj2、obj1、obj、temp四个对象的析构
    return 0;
}
