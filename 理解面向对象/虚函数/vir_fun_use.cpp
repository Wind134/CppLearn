/*
- 这个例子展示了这么一点：对虚函数的重写是可以改变其访问修饰属性的，编译可以正常通过；

- 此外，提及override的用处：在这个例子中override不写也没问题，但建议写上，这样能更好的保证代码的可读性与
- 一致性，表明我这个派生类当中是针对继承而来的虚函数进行重写的，那么代码维护者一看就比较显然
*/
#include <iostream>
using namespace std;

class Base {
public:
    virtual void foo() {
        cout << "I'm from Base, and is public" << endl;
    }
};

class Derived : public Base {
public:
    void call_foo() {
        foo();
    }    
private:
    // 重写的虚函数可以改变访问修饰符的属性
    void foo() override {
        cout << "I'm from Derived, and is private" << endl;
    }
};

int main()
{
    Base b;
    Derived d;
    b.foo();
    d.call_foo();
    return 0;
}
