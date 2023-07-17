#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();   //第一个元素
    while (iter != vi.end()) {        
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);  //insert插入的元素一般在前面，返回的也是插入元素位置的迭代器
            iter += 2;
        }
        else
        {
            iter = vi.erase(iter);     //返回最后一个被删元素之后位置的迭代器
        }    
    }
    auto it = vi.begin();
    while (it != vi.end())
        {
            std::cout << *it << " \n"[++it == vi.end()];
        }
    return 0;
}