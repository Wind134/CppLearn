#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>

template <typename T>
class Blob {
public:
    Blob(std::initializer_list<T> il);
    void print();
private:
    std::vector<T> data;
};

template <typename T> 
Blob<T>::Blob(std::initializer_list<T> il) {
    for (auto it = il.begin(); it != il.end(); ++it) {
        data.push_back(*it);
    }
}

template <typename T>
void Blob<T>::print() {
    for (auto it = data.begin(); it != data.end(); ++it) {
        std::cout << *it << " "; 
    }
    std::cout << std::endl; 
}

int main() {
    Blob<int> b = {1, 2, 3};   // 使用 initializer_list 构造
    b.print();                  // 1 2 3 
    Blob<std::string> str = {"I", "love", "you"};   // 使用 initializer_list 构造
    str.print();                  
}
