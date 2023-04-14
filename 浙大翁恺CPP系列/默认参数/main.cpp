// #include "默认参数.h"
void f(int i, int j = 10);		//‘j’应该就直接看作DefaultValue
int main()
{
	f(10, 20);
	return 0;
}