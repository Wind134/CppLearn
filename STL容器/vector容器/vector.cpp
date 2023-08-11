#include <vector>
#include <iostream>
using namespace std;

int main ()
{
    vector<int> v1;      //创建一个新的vector容器。

    cout << "v1.capacity()= " << v1.capacity() << ", v1.size() = " << v1.size() <<endl;

     vector<int> v2(8);      //创建8个数组的vector容器

    cout << "v2.capacity()= " << v2.capacity() << ", v2.size() = " << v2.size() <<endl;

    return 0;
}