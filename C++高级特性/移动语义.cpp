#include <iostream>
#include <vector>
#include <chrono>
#include <climits>
#include <algorithm>

int main() {
    std::vector<int> elements(10);
    elements[0] = 1;
    elements[1] = 2;
    elements[2] = 3;
    elements[3] = 4;
    elements[4] = 5;
    int circul = 1000000000;

    // 使用std::make_move_iterator创建移动迭代器
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < circul; i++)    std::move_backward(elements.begin(), elements.begin() + 5, elements.end());
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);

    // 打印程序运行时间
    std::cout << "程序运行时间: " << duration1.count() << " 毫秒" << std::endl;


    // 在空间的头部插入新元素
    // elements[0] = 0;

    // 打印移动后的元素
    for (const auto& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // 使用std::make_move_iterator创建移动迭代器
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < circul; i++)    std::copy_backward(elements.begin(), elements.begin() + 5, elements.end());
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2);

    // 打印程序运行时间
    std::cout << "程序运行时间: " << duration2.count() << " 毫秒" << std::endl;

    // 打印移动后的元素
    for (const auto& element : elements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
