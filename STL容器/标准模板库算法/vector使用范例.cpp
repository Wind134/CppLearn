#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> sentence(0);
    std::string word;
    while (std::cin >> word)
    {
        sentence.push_back(word);
    }
    for (auto it = sentence.begin(); it != sentence.end(); it++)
        //std::cout << *it << " \n"[it==sentence.end()];
        std::cout << *it << " ";
    //std::cout << sentence << std::endl;
    return 0;
}