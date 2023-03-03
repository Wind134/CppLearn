/* char argv[] 是一个字符串（也可以说是字符数组），而 char *argv[] 是一个字符串指针。
第一个仅仅对应一个字符串，通常使用方法就是直接argv，操作其中某个字符 argv[n]；
第二个可以有多个内容，最常规的main函数根据argc的计数可以读取其内容
比如argv[0], argv[1]等等的字符串 */
#include <iostream>
#include <string>


int main (int argc, char* argv[])
{ 
	std::string str;
	for (auto i = 1; i < argc; ++i)
	{
		str = str + argv[i] + " ";
		std::cout<<argv[++i]<<std::endl;  
   		std::cin>>i;  
	}
	std::cout << str << std::endl;
	return 0;
}
