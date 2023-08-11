#include <string>
#include <queue>
#include <iostream>
using namespace std;

//基本数据类型的优先级设置
//priority_queue<int> q;
//priority_queue< int, vector<int>, less<int> > q;  // 如果想要调整优先级顺序，less<int> -> greater<int>

//结构体的优先级设置，涉及到运算符重载，也就是说在这个结构体内部，price越小的才代表了那个'<'号。
/*
struct fruit {
    string name;
    int price;
    friend bool operator < (friut f1, friut f2)     //重载小于号运算符，从而实现优先级的更改

    {
        return f1.price < f2.price;
    }
}
*/

//另外一种更改优先级的写法

struct fruit
{
    string name;
    int price;
}f1, f2, f3;
struct cmp
{
    /* data */
    bool operator () (fruit f1, fruit f2)
    {
        return f1.price > f2.price;
    }
};
int main( )
{
    /* code */
    priority_queue<fruit, vector<fruit>, cmp> q;    //cmp后面没接什么东西，为什么？
    f1.name = "桃子";
    f1.price = 3;
    f2.name = "梨子";
    f2.price = 4;
    f3.name = "苹果";
    f3.price = 1;
    q.push(f1);
    q.push(f2);
    q.push(f3);
    cout << q.top().name << " " << q.top().price << endl;
    //cout << q.empty();
    cout << (1 == true) << endl;
    return 0;
}

