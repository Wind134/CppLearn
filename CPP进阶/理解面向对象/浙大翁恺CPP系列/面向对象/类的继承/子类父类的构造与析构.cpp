// 子类父类关系.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>

using namespace std;    //这就是使用std的命名空间的意思

class A {
public:
    A(int ii):i(ii) { cout << "调用A类中的构造函数：" << "A::A()" << endl; }       // 这里就注定需要在B类中设置构造函数
    ~A() { cout << "调用A类中的析构函数：" << "A::~A()" << endl; }
    void print() { cout << "调用A类中的print()：" << "A::print()" << i << endl; }     // 这里的i随机给的
    void print(int i) { cout << "调用A类中的print(i)：" << i << endl; print(); }
    void set(int ii) { i = ii; cout << "A类中的i值更改为了：" << i << endl; }
private:
    int i;
};

class B : public A {
public:
    B() : A(16) { cout << "调用B类中的构造函数：" << "B:B()" << endl; }  // 没有这一构造函数会产生报错。
    ~B()  { cout << "调用B类中的析构函数：" << "B:~B()" << endl; }
    void print() { cout << "调用B类中的print()：" << "B:print()" << endl; }   // 代替掉父类中的print
    //void f() { set(20);  print(); }     // 先执行set再执行print
    void f() { set(20); }   // 执行的是A类中的set函数
};
int main()
{
    B b;        // 先调用A的默认构造函数初始化，再调用B的默认构造函数
    b.set(10);  // B中没有set，调用了A的set函数
    //b.print();
    b.f();      // 调用了B的f()，且在f中又调用了set
    b.print();
    cout << "程序运行结束！" << endl;
    return 0;   // 析构函数在return之前执行，且先执行派生类的析构
}