/*  
- 这份源码很好的展示了拷贝构造函数与拷贝赋值运算符

- 同时也证明了这么一点：拷贝赋值运算符是浅拷贝
- 拷贝构造是深拷贝
*/
#include <iostream>

class MyClass {
private:
    int data;
    int* ptr;
public:
    // 默认构造函数
    MyClass() : data(0) {}

    // 带参数的构造函数
    MyClass(int value) : data(value), ptr(new int(value)) {}

    // 拷贝构造函数
    MyClass(const MyClass& other) : data(other.data), ptr(other.ptr) {}

    // 拷贝赋值运算符重载
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            data = other.data;
            ptr = other.ptr;
        }
        return *this;   // 返回一个指向该对象的引用
    }

    int getData() const {
        return data;
    }

    int* getPtr() const {
        return ptr;
    }

    void alter_data(int value)
    {
        data = value;
    }
};

int main() {
    MyClass obj1(42); // 使用带参数的构造函数初始化 obj1

    // 拷贝构造的参数形式为const引用，这样就避免了形参的再次拷贝，同时又能构造出一个新的对象
    // 所有类型的构造函数都是没有返回类型的，这一点一定要谨记
    MyClass obj2(obj1); // 使用拷贝构造函数初始化 obj2，obj2是obj1的副本

    MyClass obj3 = obj1;

    std::cout << "Show the deep copy and shallow copy: \n";

    std::cout << "obj1 ptr: " << obj1.getPtr() << std::endl; // 输出: 
    std::cout << "obj2 ptr: " << obj2.getPtr() << std::endl; // 输出: ，浅拷贝共享同一个指针
    std::cout << "obj3 ptr: " << obj3.getPtr() << std::endl; 

    std::cout << "Show the copy constructor and copy assignment opertor: \n";

    std::cout << "obj3 data: " << obj3.getData() << std::endl; // 输出: 42

    obj1.alter_data(43);
    
    // 下面这一行代码体现了拷贝赋值的意义所在，由于返回的是引用，因此obj3这个对象可以随着目标的不同而改变
    obj3 = obj1;

    std::cout << "obj1 data: " << obj1.getData() << std::endl; // 输出: 42
    std::cout << "obj2 data: " << obj2.getData() << std::endl; // 输出: 42
    std::cout << "obj3 data: " << obj3.getData() << std::endl; // 输出: 42


    return 0;
}
