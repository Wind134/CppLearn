#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(const int& n) {
    if (n <= 1) {
        return false;
    }
    int sqr = (int)sqrt(n); // 到根号n即可
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int getTwinPrime(const int& n) {
    int k = 1;
    for (int i = 0; i < n; i++) {
        do {
            k += 2;
        } while (!isPrime(k) || !isPrime(k + 2));   // 这个思想还是很妙的
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    cout << getTwinPrime(n) << " " << getTwinPrime(n) + 2 << endl;
    return 0;
}