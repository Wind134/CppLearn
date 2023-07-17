#include <iostream>
#include <string>
using namespace std;

static int objectCount = 0;     // 静态变量

class HowMany
{
public:
    HowMany() { objectCount++; print("调用的构造函数的类型为HowMany()");}         //不带参数的构造
    HowMany(int i) { objectCount++; print("调用的构造函数的类型为HowMany(int)"); }        //参数是int类型的拷贝构造
    HowMany(const HowMany& o) {objectCount++; print("调用的类型为拷贝构造HowMany(HM)"); }   //参数是对象的拷贝构造
    //HowMany(const HowMany& o) {objectCount++; print("HowMany(HM)"); }
    void print(const string& msg = "") {
        if(msg.size() != 0) cout << msg << ": " << "objectCount = " << objectCount << endl;
    }
    ~HowMany()  {
        objectCount --;
        print("执行析构~HowMany()");
    }
};

// Pass and return BY VALVE:
HowMany f(HowMany x) {
    cout << "进入函数f()" << endl;
    x.print("x argument inside f()");
    cout << "离开函数f()" << endl;
    return x;       //返回的x的类型是HowMany类型，同时执行对x的析构
}

int main(int argc, char const *argv[])
{
    HowMany h;  // 第一次调用这个类的构造函数，因为变量h。
    h.print("after construction of h");
    //HowMany h2(10);   // 经过了int类型的构造函数。
    //HowMany h2 = h; // 没有经过构造函数，直接赋值。
    HowMany h2 = f(h);   // 这一步是初始化，经过了构造函数。第二、三次调用这个类的构造函数，因为变量h2与变量h--函数内调用 
    // 上一这一行还值得细细讨论，这写法相当于是列表初始化，即相当于 HowMany h2(f(h)); 那自然是执行对象参数的拷贝复制了。 
    // 更准确来说，是通过合成的拷贝复制运算符去实现，该部分会调用拷贝构造函数
    h.print("after call to f()");
    return 0;
}

