#include <iostream>
#include <string>


int main (int argc, char *argv[])
{ 
	std::string str;
	for (auto i = 1; i < argc; ++i)
	{
		str = str + argv[i] + " ";
	}
	std::cout << str << std::endl;
	return 0;
}
