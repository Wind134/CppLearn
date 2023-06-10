/*
 * 给你一个无重复元素的整数数组candidates和一个目标整数target ，找出candidates中可以使数字和为目标数target的所有
 * 不同组合，并以列表形式返回。可以按任意顺序返回这些组合。candidates中的同一个数字可以无限制重复被选取。如果至少一个
 * 数字的被选数量不同，则两种组合是不同的.
 * 直觉思路：回溯策略，数组中的每个元素，都有可能是target目标值的一部分，对于数组中，每个元素而言，有选中与不选中的可能
 * 选中这个元素a[index]，那么就相当于是接着针对目标值target-a[index]寻找满足条件的组合，这就形成了一个递归
 * 递归需要有返回边界，当index遍历到数组a最后一个元素时，递归结束
 * 当target变为0时，说明我们已经找到了集合，将该集合加入结果，同样也返回
*/
#include <iostream>
#include <vector>
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
        traceback(candidates, target - candidates[i], i);
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
    vector<int> input;
    int target;

    int elem;
    while (cin >> elem)
    {
        input.push_back(elem);
        if (cin.get() == '\n')  break;
    }

    cin >> target;
    
    auto result = combinationSum(input, target);
    for (const auto& vector : result)
    {
        for (auto& num : vector)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}