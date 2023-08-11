#include <iostream>
#include <cassert>


int main() {
    int a;
    std::cin >> a;

    assert(a > 0);

    std::cout << a << std::endl;
}