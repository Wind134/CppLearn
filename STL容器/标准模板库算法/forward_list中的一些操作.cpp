#include <iostream>
#include <forward_list>

int main ()
{
    std::forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();    //表示flst的"首前元素"
    auto curr = flst.begin();   //第一个元素
    while (curr != flst.end()) {        //这个东西还是有点巧妙的
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }    
    }
    auto it = flst.begin();
    while (it != flst.end())
        {
            std::cout << *it << " \n"[++it == flst.end()];
        }
    return 0;
}