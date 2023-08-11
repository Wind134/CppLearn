/*
这是一个使用深拷贝的例子，解决了浅拷贝所带来的问题
*/
#include <iostream>
#include <string>

class Person {
private:
    std::string* name;

public:
    Person(const std::string& n) {
        name = new std::string(n);
    }

    Person(const Person& other) {
        // 分配了一片新的空间，实现了深拷贝
        name = new std::string(*other.name);
    }

    ~Person() {
        delete name;
    }

    void setName(const std::string& n) {
        *name = n;
    }

    std::string getName() const {
        return *name;
    }
};

int main() {
    Person person1("Alice");

    // 对对对，还有一个细节要区分好，像下面这种写法调用的是拷贝构造函数，而不是拷贝赋值运算符，切记
    Person person2 = person1;  // 深拷贝

    // 拷贝赋值运算符应该是：
    // Person person3;
    // person3 = person1;       // 这样才属于拷贝赋值运算符的调用

    person2.setName("Bob");

    std::cout << person1.getName() << std::endl;  // 仍输出"Alice"，不受修改的影响

    return 0;
}
