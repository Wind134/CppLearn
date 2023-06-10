#include <iostream>
using namespace std;

int main()
{
    class Empty_class
    {
        /* 
        * 函数并不占据类对象的存储空间，此外该类没有虚函数，因此没有指向虚函数表的指针
        * 然而类大小大小不是0，至少为1 
        */
        public:
            void func() { cout << "This is Empty_class::func()!" << endl; }
    };

    class Base
    {
        /* 由于虚函数会维护一个指向虚函数表的指针，在64位的机器上，这么一个指针的大小至少为8字节 */
        public:
            // 函数本身并不占据类对象空间，因此无论多少个虚函数，也就一个指向虚函数表的指针占用类对象的空间
            virtual void func1() { cout << "This is Base::func1()!" << endl; }

            void func2() { cout << "This is Base::func2()!" << endl; }  // 普通函数不占用类对象的空间  
            
            virtual void func3() { cout << "This is Base::func3()!" << endl; }
            virtual ~Base() {}
        private:
            // int data;
            // int add;    
    };

    class Derived : public Base
    {
        public:
            void func1() { cout << "This is Derived::func1()!" << endl; }
            virtual ~Derived () {}
        private:
            int newdata;
            int newadd;

            // 正常来说在添加下面这一行之前，派生类对象的大小应该是24，16加上两个新定义的int变量
            // 因此添加下面这个之后理论上应该是28，但实际上会打印出32，因为要内存对齐，有4字节
            // 会空出来
            int add_one;
            int add_two;    // 添加这行还是32，刚好填满那4字节    
    };

    Empty_class e;

    cout << "sizeof(e) = " << sizeof(e) << endl; 

    Base b;

    cout << "sizeof(b) = " << sizeof(b) << endl;

    Derived d;

    cout << "sizeof(d) = " << sizeof(d) << endl;

    Base* b_ptr = &d;

    b_ptr->func3(); 

    return 0;
}