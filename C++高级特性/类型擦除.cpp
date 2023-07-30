/*
下面这个例子初步展示了一个类型擦除的示例
*/
#include <iostream>
#include <vector>
#include <any>
using namespace std;

void for_container() {
    std::vector<std::any> myVector;

    // 添加不同类型的对象到容器中
    myVector.push_back(42);
    myVector.push_back(3.14);
    myVector.push_back(std::string("Hello"));

    // 遍历容器中的对象并根据类型进行处理
    for (const auto& item : myVector) {
        if (item.type() == typeid(int)) {
            std::cout << "Integer value: " << std::any_cast<int>(item) << std::endl;
        } else if (item.type() == typeid(double)) {
            std::cout << "Double value: " << std::any_cast<double>(item) << std::endl;
        } else if (item.type() == typeid(std::string)) {
            std::cout << "String value: " << std::any_cast<std::string>(item) << std::endl;
        } else {
            std::cout << "Unknown type" << std::endl;
        }
    }
}

int main() {
    std::any value;

    value = 42;
    std::cout << "Integer value: " << std::any_cast<int>(value) << std::endl;

    value = 3.14;
    std::cout << "Double value: " << std::any_cast<double>(value) << std::endl;

    value = std::string("Hello");
    std::cout << "String value: " << std::any_cast<std::string>(value) << std::endl;

    cout << "-----------------------" << endl;
    for_container();

    return 0;
}
