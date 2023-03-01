
#include <iostream>
#include <list>
#include <algorithm>

int main ()
{
    std::list<int> lst = {1, 2, 3, 4};
    std::list<int> lst2 = {5, 6, 7 ,8};
    // lst.splice(lst.begin(), lst2);
    // lst.splice(std::find(lst.cbegin(), lst.cend(), 3), lst2);
    lst.splice(std::find(lst.cbegin(), lst.cend(), 3), lst2, lst2.begin(), std::find(lst2.cbegin(), lst2.cend(), 7));
    for (auto l : lst)  std::cout << l << " ";
    std::cout << std::endl;
}

