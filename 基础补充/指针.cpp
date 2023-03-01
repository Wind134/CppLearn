#include <iostream>

int main()
{	
	int n = 0, i = 42;
	std::cout << "初始的n = " << n << std::endl;
	int *p = &n, *q = &i;
	*p = 42;
	p = q;
	std::cout << "n = "<<n<<"\np = "<<p<<"\nq = "<<q<<std::endl;
	return 0;	
}
