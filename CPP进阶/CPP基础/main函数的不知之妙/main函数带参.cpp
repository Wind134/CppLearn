/*
这个例子展示了带参数的main函数，参数在编译后的程序后添加
*/
#include <iostream>
#include <string>
int main (int argc, char *argv[])
{ 
	std::string str;
	for (auto i = 1; i < argc; ++i)
		str = str + argv[i] + " ";
	std::cout << str << std::endl;
	return 0;
}