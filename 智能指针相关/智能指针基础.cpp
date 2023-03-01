#include<memory>
#include<iostream>
using namespace std;
struct A {
	int i ;
	A() { cout << "construct\n"; }
	~A() { cout << "delete "<< i <<"\n"; }
};
int main()
{
	shared_ptr<A> a( new A);    // 构造一次
	A* b = new A;   // 构造两次
	a->i = 1;
	b->i = 2;
	a.reset(b);     // 执行了一次析构，因为a原来指向的空间被释放了，输出delete 1
	cout << "end\n";
    //最后输出delete 2，最终执行的析构
	return 0;
}

// 这里留下了一个问题，去掉reset那一行，再看看执行的结果，这就跟构造函数有关了
