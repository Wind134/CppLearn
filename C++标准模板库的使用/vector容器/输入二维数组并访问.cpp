#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > data(n, vector<int> (m));      //定义了一个二维数组，有n个vector
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> data[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << data[i][j] << " \n"[j==m - 1];
        }
    }
    return 0;
}
