#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "../headfile/TreeNode.h"
using namespace std;


vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> result;
    if (!root)  return result;

    queue<TreeNode*> treeNode_que;

    treeNode_que.push(root);

    while (!treeNode_que.empty())
    {
        vector<int> vec_of_result;
        int size = treeNode_que.size(); // 队列的长

        for (int i = 0; i < size; i++)
        {
            vec_of_result.push_back(treeNode_que.front()->val);

            if (treeNode_que.front()->left) treeNode_que.push(treeNode_que.front()->left);
            if (treeNode_que.front()->right) treeNode_que.push(treeNode_que.front()->right);

            treeNode_que.pop();
        }

        result.emplace_back(vec_of_result);
    }

    reverse(result.begin(), result.end());

    return result;

}

int main()
{
    cout << "Please input the value of every node(-1 represents null): ";
    vector<int> root_array;
    int input_data;
    while (cin >> input_data)
    {
        root_array.push_back(input_data);
        if(cin.get() == '\n')   break;
    }
    
    TreeNode* root = buildTreeWithVec(root_array);  // 默认参数是0，这里省略了没写

    auto result = levelOrderBottom(root);

    for(const auto& vec : result)
    {
        for(auto& elem : vec)   cout << elem << " ";
        cout << endl;
    }

    return 0;
}