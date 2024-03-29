/*
题目：
- 给你一个无重复元素的整数数组candidates和一个目标整数target
- 找出candidates中可以使数字和为目标数target的所有不同组合，
- 并以列表形式返回。你可以按任意顺序返回这些组合。

注意：
- candidates中的同一个数字可以无限制重复被选取。
- 但如果至少一个数字的被选数量不同，则两种组合是不同的。
- 1 <= candidates.length <= 30
- 2 <= candidates[i] <= 40

对于给定的输入，保证和为target的不同组合数少于150个。

做法：回溯
- 数组中的每个元素，都有可能是target目标值的一部分，对于数组中，每个元素而言，有选中与不选中的可能
- 选中这个元素a[index]，那么就相当于是接着针对目标值target-a[index]寻找满足条件的组合，这就形成了一个递归
- 递归需要有返回边界，当index遍历到数组a最后一个元素时，递归结束
- 当target变为0时，说明我们已经找到了集合，将该集合加入结果，同样也返回
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;

vector<vector<int>> result;
vector<int> elem_of_result;
void traceback(const vector<int>& candidates, int target, int index)
{
    if(target == 0)
    {
        result.push_back(elem_of_result);   // 加入result的二维数组即可
        return;
    }

    for (int i = index; i < candidates.size() && target - candidates[i] >= 0; i++)
    {
        elem_of_result.push_back(candidates[i]);
        traceback(candidates, target - candidates[i], i);   // index从i开始，也预示了可重复选取的情形
        elem_of_result.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    traceback(candidates, target, 0);
    return result;
}

int main()
{
    input input39;
    int target;

    auto vec = input39.input_vector();

    cout << "Please input the target value: ";
    cin >> target;
    
    auto result = combinationSum(vec, target);
    
    output output39;

    output39.output_matrix(result);
    return 0;
}