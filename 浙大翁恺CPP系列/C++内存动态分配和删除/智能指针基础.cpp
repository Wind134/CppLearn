#include <memory>
#include <iostream>
using namespace std;
struct A {
	int i ;
	A() { cout << "construct\n"; }
	~A() { cout << "delete "<< i <<"\n"; }
};
int main()
{
	shared_ptr<A> a(new A);    	// 指向a的智能指针A
	A* b = new A;   			// b是一个指向，指向A，构造两次
	a->i = 1;
	b->i = 2;
	a.reset(b);     			// 执行了一次析构，因为a原来指向的空间由b来指向，a自身被释放了，输出delete 1
	cout << "end\n";
	return 0;					// 脱离main函数体，最后输出delete 2，执行最终的析构，也就是对b的释放
}
