/*
题目：
- 给你一个整数n，请你生成并返回所有由n个节点组成且节点值从1到n互不相同的不同二叉搜索树。
- 可以按任意顺序返回答案。

思路：考虑回溯；
-我们先假设一个序列[1, n]，假设选根节点的val为i，那么根节点的左子树的节点值全为[1.....i - 1]，右子树的节点值为[i + 1...n]
- 而左子树又是一个可以去考虑的序列，右子树同样是一个可以去这么考虑的序列，一个大问题分成了两个同样的子问题：
- 假设两个子问题都生成了根节点的集合，也就是说左序列生成了左子树根节点的集合，右序列生成了右子树根节点的集合；
- 那么对于i节点而言，从左子树集合中选取一颗左子树，右子树集合中选择一颗右子树，拼接，就实现了一个节点的生成；
*/
#include "../headfile/io_for_leetcode.h"
using namespace std;


long long generateTrees(int start, int end, vector<vector<long long>>& map) // 参数处理为一个序列
{
    long long count = 0;
    if(start > end) return 1;   // 空也算一种类型
    for (int i = start; i <= end; i++)
    {
        if (map[start][i - 1] == 0)
            map[start][i - 1] = generateTrees(start, i - 1, map);
        
        if (map[i + 1][end] == 0)
            map[i + 1][end] = generateTrees(i + 1, end, map);

        count += map[start][i - 1] * map[i + 1][end]; 
    }
    
    return count;
}


int main()
{
    int input;
    cin >> input;
    vector<vector<long long>> interval_map(input + 2, vector<long long>(input + 2));    // 存储遍历过的区间节点，极大的剪枝
    auto output = generateTrees(1, input, interval_map);
    cout << output << endl;
    return 0;
}