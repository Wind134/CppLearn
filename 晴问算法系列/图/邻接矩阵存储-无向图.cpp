#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int VNums, ENums;   // 顶点数，边数
    cin >> VNums >> ENums;
    vector<vector<int>> undir_mapM(VNums, vector<int>(VNums)); // 定义这么一个二维数组存并默认初始化
    int startP, endP;
    for(int i = 0; i < ENums; i++)
    {
        cin >> startP >> endP;
        undir_mapM[startP][endP] = 1;
        undir_mapM[endP][startP] = 1;
    }
    for (const auto &row : undir_mapM)
    {
        bool tag = true;
        for(auto elem : row)
        {
            if (tag){ tag = false;   cout << elem;}
            else    cout << " " << elem;
        }
        cout << endl;
    }
    return 0;
}