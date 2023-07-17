/*
- 生动展示了对象组合的使用，对象组合做好与继承的区分即可，这只是一个用例展示
*/
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
        cout << "then car started." << endl;
    }
};

int main() {
    Car car;
    car.Start();
    return 0;
}
