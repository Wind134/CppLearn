/* class Person { 
    Person (const)
 };
class Currency { .... };
class SavingsAccount {
public:
    SavingsAccount(const char* name,
        const char* address, int cents);
    ~SavingsAccount();	//析构函数
    void print();
private:
    Person m_saver;			//使用了一个Person类，上面已定义。
    Currency m_balance;		//使用了一个Currency类，已定义。
}
SavingsAccount::SavingsAccount(const char* name, const char* address,
    int cents) : m_saver(name, address), m_balance(0, cents) {}	//	初始化列表
void SavingsAccount::print() {
    m_saver.print();
    m_balance.print();
} */
/* 当一个类拥有另一个类的对象作为其成员变量时，这就是对象组合 */
#include <iostream>
using namespace std;

class Engine {
public:
    void Start() {
        cout << "Engine started." << endl;
    }
};

class Car {
private:
    Engine engine;

public:
    void Start() {
        engine.Start();
        cout << "Car started." << endl;
    }
};

int main() {
    Car car;
    car.Start();
    return 0;
}
