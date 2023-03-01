#include <iostream>
#include <string>
#include <algorithm>

int main ()
{
    std::string line = "qwdv,love";
    auto rcomma = find(line.crbegin(), line.crend(), ',');
    std::cout << std::string(rcomma, line.crbegin()) << std::endl;
}
