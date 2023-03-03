#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{	
	int i = 0, j = 42;
	int m = 10, n = 20;
	int *p = &i, *q = &j;
	std::cout << "main函数部分的交换方式：\n";
	std::cout << "初始的指针信息p = "<< p <<"\tq = "<< q <<std::endl;
	int *temp = p;
	p = q;
	q = temp;
	std::cout << "交换指针之后i = " << *p 
	<< "\tj = " << *q << "\n指针信息p = "<< p <<"\tq = "<< q <<std::endl;
	std::cout << "-----------------------------------\n";
	std::cout << "swap函数部分的交换方式：\n";
	std::cout << "初始的值信息m = "<< m <<"\tn = "<< n << std::endl;
	swap(&m, &n);	
	std::cout << "交换后的值信息m = "<< m <<"\tn = "<< n << std::endl;
	return 0;	
}
