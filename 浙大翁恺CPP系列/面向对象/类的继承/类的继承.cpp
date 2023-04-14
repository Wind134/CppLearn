// 类的继承.cpp 
#include <iostream>

using namespace std;

class A {
public:
    A() { cout << "执行构造函数A::A()" << endl; }
    ~A() { cout << "执行析构函数A::~A()" << endl; }
    void print() { cout << "执行A::f()，A类中i的值为：" << i << endl; }     //  这里的i随机给的
protected:          //  代表是受保护的，子类B可以调用，但外函数main无法调用。
    void set(int ii) { i = ii; }
private:
    int i;
};

class B : public A{
public:
    void f() { set(20);  print(); }     //先执行set再执行print。
};
int main()
{
    B b;    // B没有附带构造与析构诶，执行的是默认构造与析构吗？
    b.print();
    b.f();
    return 0;
}