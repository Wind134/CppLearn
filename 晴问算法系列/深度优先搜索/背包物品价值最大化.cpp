/* 第i件物品重量为w[i]，价值为c[i]，选若干物品放入背包，
在重量不超过V的前提下，实现物品价值之和最大化 */
// 明确一个状态，放进去第index个物品，与不放进第index个物品的情况
#include <iostream>
#include <vector>
using namespace std;

int nums, weight;   // 物品的数目以及背包的最大重量
int maxValue = 0;   // 初始状态下的最大价值
vector<int> object_index; 

void DFS(const int& index, const vector<int>& v,
const vector<int>& w, const int& value, const int& tempWeight)
{
    if (index == nums)  // 在完成了对n个物品的处理之后
    {
        if(tempWeight <= weight)
        {    
            if(value > maxValue)
                {
                    maxValue = value;
                    object_index.push_back(index); 
                }
        }
        return;         // 退出函数执行
    }
    DFS(index+1, v, w, value, tempWeight);  // 不放第n个
    if (tempWeight + w[index] <= weight)
    {
        if(value + v[index] > maxValue)
        {
            
            maxValue = value + v[index]; 
        }
        object_index.push_back(index);      // 将当前物品的索引存入vector中
        DFS(index+1, v, w, value + v[index], tempWeight + w[index]);  // 放第n个
        object_index.pop_back();
    }
}

int main()
{
    
    cin >> nums >> weight;
    vector<int> wi(nums);
    vector<int> ci(nums);
    int w, c;
    for (int i = 0; i < nums; i++)
    {
        cin >> w;
        wi[i] = w;
    }
    for (int i = 0; i < nums; i++)
    {
        cin >> c;
        ci[i] = c;
    }
    DFS(0, ci, wi, 0, 0);
    cout << maxValue << endl;
    for (const auto& data : object_index)
    {
        cout << data << " ";
    }
}


