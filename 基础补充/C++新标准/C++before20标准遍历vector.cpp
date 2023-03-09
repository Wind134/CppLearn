#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;        // 头文件就别乱用这种写法了

int main() {
    vector<int> vec {1, 2, 3};
    for_each(vec.rbegin(), vec.rend(), [] (const int& e) {std::cout << e << " ";});
}