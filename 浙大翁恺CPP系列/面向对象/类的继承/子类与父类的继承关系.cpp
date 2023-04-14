#include <iostream>
using namespace std;

class A
{
public:
    A():i(10) { };
    int i;
};

class B: public A {
private:
    int j;
public:
    B():j(30) {}
    void f() {cout << "B.j = " << j << endl; }
};

int main()
{
    A a;
    B b;
    cout << a.i << " " << b.i << endl;  // b会向外作用域去寻找变量i
    cout << sizeof(a) << " " << sizeof(b) << endl;  // B类要继承A类的资源，所以会更大一些
    A *p = &a;
    cout << "a对象的指针p为：" << p << "，a对象的中变量i的值：" << p->i << endl;
    p->i = 20;
    cout << "输出的A类中的a.i为" << a.i << endl;        // a.i发生了改变，因为通过指针更改了a.i的值。
    B *q = &b;
    cout << "b对象的指针p为：" << q << endl;
    q->f();
    cout << q->i << endl;
    return 0;
}
