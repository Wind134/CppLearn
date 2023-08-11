#include <iostream>
int main ()
{
	int i = 42;
    int *p = &i;			// 定义一个指向整型变量的指针
	std::cout << "打印p的地址信息：" << p << std::endl
	<< "正常来说，指针p指向的变量i的值：" << *p << std::endl;
	// int *&r = p;	// r是一个指向整型变量的引用。它是一个指针的引用，可以改变指针所指向的地址。
	int* &r = p;	// 改成这样上面的注释更好理解
	r = &i;			// 引用i的地址
	std::cout << "首先我们需要知道的是所定义的r是指针的引用\n" << "打印r地址的信息：" << r << "\n"
	<< "此时，引用指针r指向的变量i的值：" << *r << std::endl;
	*r = 0;
	r++;
	std::cout << "执行*r=0后，变量i的值：" << i << std::endl;
	std::cout << "执行r++后打印p的地址信息：" << p << std::endl;
	std::cout << "p指向的信息被改变了，此时指向p指向的变量的值："
	<< *p << "\n" 
	<< "r作为引用，地址信息没有变化，仍然是：" << r << std::endl;
	return 0;	
}

