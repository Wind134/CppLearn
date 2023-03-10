#include <cstdio>
#include <vector>
using namespace std;
int main() {
    vector<int> vi;     //这里就已经定义出来了数组
    for(int i = 1; i <=5; i++) {
        vi.push_back(i);
    }
    //常规通过下标访问的方法就不写了.
    //元素访问方法1：vi.begin()取vi的首元素地址，定义的it指向这个地址.
    /*
    vector<int>::iterator it = vi.begin();
    for(int i =0; i < 5; i++)
    {
        printf("%d \t", *(it +i));
    }
    return 0;
    */
    //元素访问方法2：通过自增方式访问，但是vector的迭代器不支持it < vi.end()的写法
    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        printf("%d ", *it);
    }
    return 0;
}