#include <iostream>
using namespace std;

class A
{
public:
    int i;
    void f(A* p);
};

struct B
{
    int i;
};

void A::f(A* p ) {
    cout << p->i << endl;
    p->i = 20;
    cout << p->i << endl;
}


void f(struct B* p)
{
    p->i = 30;
    cout << p->i << endl;
};
int main() {
    A a;
    A aa;
    B b;
    a.i = 10;
    cout << a.i << endl;    //变量a可以直接访问i
     // a.f();
     a.f(&a);   //报错？ 改成a.可以解决问题，而不是A::，不然会报：非静态成员引用必须与特定对象相对。
     f(&b);
     aa.i = 100;
    // aa.f();
    return 0;
};