#include <iostream>
using namespace std;

struct X;	//前向声明

struct Y
{
	void f(X*);	// X类型的指针做形参
};

struct X
{
private:
	int i;
public:
	void initialized();		// 初始化
	friend void g(X*, int);	// Global friend (全局friend)
	friend void Y::f(X*);	// Struct member friend
	friend struct Z;	// Entire struct is a friend
	friend int h(X*);
};

void X::initialized() {
	i = 0;
}

void g(X* x, int i) {
	x->i = i;
}

void Y::f(X* x) {
	x->i = 47;
}

int h(X* x)
{	
	return x->i;
}

struct Z
{
private:
	int j;
public:
	Z() { cout << "进入Z的构造函数" << endl; }
	~Z() { cout << "执行Z的析构函数" << endl; }
	void set(X* x) { j = x->i; x->i++; } 	
};

int main()
{
	X a;
	a.initialized();
	cout << "1：X::i output is " << h(&a) << endl;
	g(&a, 5);
	cout << "2：X::i output is " << h(&a) << endl;
	Y y;
	y.f(&a);
	cout << "3：X::i output is " << h(&a) << endl;
	Z z;
	z.set(&a);
	cout << "4：X::i output is " << h(&a) << endl;
	return 0;
}

