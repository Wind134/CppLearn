#include <iostream>
using namespace std;

class A
{
public:
        A() { i = 0; }
        ~A() {}
        void print() { cout << i << endl; }
        void set(int ii) { i = ii; } 
private:
        static int i;   //如果一个静态的成员函数只能使用静态的成员变量，静态的成员函数没有this？
};

int A::i;   //静态的成员变量一定要多做的一点事情，就是找到一个地方来放置这个变量。

int main()
{
    A a, b;

    a.set(10);
    b.print();  // 打印出来的应该是10，因为i是静态成员，已经被前面的set修改了
    a.set(5);
    b.print();  // 打印出来的应该是5，因为i是静态成员，已经被前面的set修改了
    return 0;
}
