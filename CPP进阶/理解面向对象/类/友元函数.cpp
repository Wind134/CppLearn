#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class CCar;  // 提前声明CCar类，以便后面的CDriver类使用

class CDriver       // 理解为这里封装了改装汽车的方法
{
public:
    void ModifyCar(CCar* pCar);  //改装汽车
};

class CCar
{
public:
    CCar () {}
    CCar (int realprice) : price(realprice) {}  // 初始价格
    // 重设价格
    void setPrice(int realprice)
    {
        price = realprice;
    }
    // 这个函数找到所有的车当中最贵的那一辆，设定为友元，可以直接获取价格信息
    friend int MostExpensiveCar(const vector<CCar>&);
    // 改装完成需要升值，因此也需要设定为友元以获取价格信息
    friend void CDriver::ModifyCar(CCar* pCar);
    void print()
    {
        cout << "改装后的价格为：" << price << endl;
    }
    ~CCar() { };
private:
    int price;
};

void CDriver::ModifyCar(CCar* pCar)     // pCar是指向CCar对象的指针
{
    cout << "--------------\n";
    cout << "汽车正在改装..........\n改装完成\n";
    pCar->price += 1000;            // 汽车改装后价值增加
}
int MostExpensiveCar(const vector<CCar>& cars)    // 求最贵汽车的价格
{
    int tmpMax = -1;
    for (const auto& car : cars)
        tmpMax = tmpMax > car.price ? tmpMax : car.price;
    return tmpMax;
}
int main()
{
    // p指向一个vector对象，该对象类型为CCar，大小为10
    auto p = new vector<CCar>(10);
    CDriver addPrice;
    int init_price;
    for (int i = 0; i < 10; i++)
    {
        cin >> init_price;
        (*p)[i].setPrice(init_price); // 通过循环设置价格price
        addPrice.ModifyCar(&(*p)[i]);  // 这只对第一个元素生效啊，加上地址，对每个生效了
        (*p)[i].print();      
    }
    cout << "维修后的车辆最高的价值为：" << MostExpensiveCar(*p) << endl;
    delete p;
    return 0;
}

