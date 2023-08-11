/*
经过输出结果可以看出的是，在new A[10]的过程中，会连续调用10次构造函数
也就是说，类中的构造函数首先被执行；
在for循环内部执行A类中的两个方法，这里导致A发生改变；
最后离开main的范围之后做析构，释放掉给A对象分配的i，所以有我们看得到的A的变化；
之所以要用tag去看构造函数的执行过程是因为i作用不到构造函数，不信可以改成A试试；
*/

#include <iostream>
using namespace std;
static int tag = 0;     //全局静态变量应该是相当于可以被全局调用，理解为其不存在于类空间

class A {
private:
    int i;        // 默认传值为0
public:
    A() {           // 构造函数，程序刚开始就调用
        cout << "A::A(" << tag++ << ")" << endl;
    }
    ~A() { cout << "A::~A(), i=" << i << endl; }            //析构函数，最后才调用
    void set(int i) {
        this->i = i;
    }
    void f() {
        cout << "This is the "<< i + 1 << "th time output \"hello\" " << endl;
    }
};

int main()
{
    A* p = new A[10];   //p是属于A类型的对象，A[10]代表由10个A类型对象组成的数组
    for (int i = 0; i < 10; i++)
    {
        p[i].set(i);    //根据输出结果来看像是堆栈
        p[i].f();
    }
    delete[] p;
}
