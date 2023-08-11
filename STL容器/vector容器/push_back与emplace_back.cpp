/*
只为展示一下emplace_back与push_back两者区别；

看执行时间，emplace_back不一定就优于push_back
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

int main()
{
    vector<int> vec1;
    vector<int> vec2;
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; i++)
        vec1.push_back(i);

    auto end1 = chrono::high_resolution_clock::now();

    cout << "push_back时间: " << chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << " 毫秒" << endl;    
    
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; i++)
        vec2.emplace_back(i);

    auto end2 = chrono::high_resolution_clock::now();

    cout << "emplace_back时间: " << chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count() << " 毫秒" << endl;

    return 0;
}