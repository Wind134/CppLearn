#include <iostream>
#include <memory>
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
    CCar (int realprice) : price(realprice) {}
    void setPrice(int realprice)
    {
        price = realprice;
    }
    friend int MostExpensiveCar(CCar cars[], int total);  // 声明友元，因此在函数MostExpensive内部可以调用私有变量
    friend void CDriver::ModifyCar(CCar* pCar);           // 声明友元
    void print()
    {
        cout << "此时的价格为：" << price << endl;
    }
    ~CCar() { };
private:
    int price;
};

void CDriver::ModifyCar(CCar* pCar)     // pCar是指向CCar对象的指针
{
    pCar->price += 1000;            // 汽车改装后价值增加
}
int MostExpensiveCar(CCar cars[], int total)    // 求最贵汽车的价格
{
    int tmpMax = -1;
    for (int i = 0; i<total; ++i)
        if (cars[i].price > tmpMax)
            tmpMax = cars[i].price;
    return tmpMax;
}
int main()
{
    int CarNums = 10;
    CCar* p = new CCar[CarNums];
    CDriver addPrice;
    for (int i = 0; i < CarNums; i++)
    {
        p[i].setPrice(i);   // 通过循环设置价格price
        addPrice.ModifyCar(&p[i]);  // 这只对第一个元素生效啊，加上地址，对每个生效了
        p[i].print();      
    }
    cout << "维修后的车辆最高的价值为：" << MostExpensiveCar(p, CarNums) << endl;
    return 0;
}

