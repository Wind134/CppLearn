/* lower_bound意为更低的那个边界，函数返回的是第一个大于等于指定元素的迭代器位置；
相似的还有：
upper_bound则是返回第一个大于指定元素的迭代器位置，注意区分两者的功能；
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10;
int a[MAXN];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int pos = lower_bound(a, a + n, k) - a; // lower_bound意为更低的那个边界，函数返回的是第一个大于等于指定元素的迭代器位置
    printf("%d\n", pos + 1);
    return 0;
}