#include <cstdio>

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("%d", x + 1);
        if (i < n - 1) {
            printf(" ");
        }
    }
    return 0;
}