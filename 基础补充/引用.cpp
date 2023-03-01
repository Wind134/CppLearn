#include <iostream>
int& Add(const int num1, const int num2)
{
    int sum = num1 + num2;
    return sum;
}
 
int main()
{
    int& ret = Add(1, 2); //int& ret = Add(1, 2);
    std::cout << ret << std::endl;
    std::cout << "Hello World" << std::endl;
    return 0;
}
