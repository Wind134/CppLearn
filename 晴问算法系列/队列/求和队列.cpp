#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n, x;
    scanf("%d", &n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        q.push(x);
    }
    while (q.size() > 1) {
        int front1 = q.front();
        q.pop();
        int front2 = q.front();
        q.pop();
        q.push(front1 + front2);
    }
    printf("%d\n", q.front());
    return 0;
}