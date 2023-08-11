#include <iostream>

// 下面是一个类模板，类模板定义了一个数组
// 数组元素的类型取决于模板参数的类型
template <typename T, int Size>
struct Array {
    using value_type = T;
    T data[Size];
};

// 下面仍然是一个类模板，定义了一个Pair
// first成员与second是不同类型的成员
// (其实即使是相同类型的成员也无妨)
template <typename T, typename U>
struct Pair {
    T first;
    U second;
};

int main() {
    Array<int, 5> arr1;  // 使用非类型模板参数Size表示数组大小，arr是一个大小为5的int型数组
    Array<double, 5> arr2;
    Pair<typename Array<int, 5>::value_type, int> p1;  // 使用typename将Array<int, 3>::value_type标识为类型
    Pair<typename Array<double, 5>::value_type, int> p2;

    for (int i = 0; i < 5; i++)
    {
        std::cin >> arr1.data[i];
    }

    for (int i = 0; i < 5; i++)
    {
        std::cin >> arr2.data[i];
    }
    
    // 这两个是相同类型成员
    p1.first = arr1.data[0];
    p1.second = 0;

    for (auto& num : arr2.data) std::cout << num << " ";

    std::cout << std::endl;

    std::cout << p1.first << " " << p1.second << std::endl;

    p2.first = arr2.data[0];
    p2.second = 0;
    
    std::cout << p2.first << " " << p2.second << std::endl;
    return 0;
}
