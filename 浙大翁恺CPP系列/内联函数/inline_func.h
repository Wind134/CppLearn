#pragma once		// 当编译器遇到一个使用#pragma once的头文件时，它会在编译期间检查该头文件是否已被包含，如果已被包含，则直接跳过；
#include <iostream>

inline void f(int i, int j)
{
	std::cout << i << " " << j << std::endl;
}
