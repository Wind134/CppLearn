#include <cstdio>
#include <set>
using namespace std;
int main() {
    set<int> st;     //这里就已经定义出来了集合,集合会自动按照递增顺序排序.
    st.insert(3), st.insert(5), st.insert(2), st.insert(3);

    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        printf("%d \t", *it);
    }
    return 0;
}