#include <iostream>
#include <climits>
using namespace std;


int max(int *a, int n) {    // 该函数的功能是返回数组中的一个最大值
    int res = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (*a > res) res = *a;
        ++a;
    }
    return res;
}

int (*f1(int n))(int *, int) {
    cout << "f1 is called with n = " << n << endl;
    return max;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int (*pmax)(int *, int) = f1(5);
    cout << pmax(a, 5) << endl;
    return 0;
}
