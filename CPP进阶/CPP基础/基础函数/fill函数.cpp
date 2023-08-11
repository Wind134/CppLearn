#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n, k, a[100];
    scanf("%d%d", &n, &k);
    fill(a, a + n, k);  // 前n个填充k这个值
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}