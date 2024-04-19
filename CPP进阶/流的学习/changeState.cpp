#include <iostream>
#include <ios>

int main() {
    // 假设初始流状态为goodbit
    std::ios_base::iostate state = std::ios_base::goodbit;

    // 读取当前流状态
    state = std::cout.rdstate();

    // 下面应该是输出0，全0
    std::cout << "Old stream state: " << state << std::endl;

    // 使用位操作将所需位复位来生成新的状态
    // eof位被置位，eofbit是00000010，这是eofbit对应的一个固定常数，明白吗？？？
    state &= ~std::ios_base::eofbit; // 将 eofbit 复位（清除）

    // 复位之后
    std::cout << "Reset stream state: " << state << std::endl;

    state |= std::ios_base::failbit; // 将 failbit 置位

    // 打印修改后的状态
    std::cout << "New stream state: " << state << std::endl;

    return 0;
}
