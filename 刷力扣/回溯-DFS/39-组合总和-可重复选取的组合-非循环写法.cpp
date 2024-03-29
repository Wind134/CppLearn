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

思路：回溯
- 数组中的每个元素，都有可能是target目标值的一部分，对于数组中，每个元素而言，有选中与不选中的可能
- 选中这个元素a[index]，那么就相当于是接着针对目标值target-a[index]寻找满足条件的组合，这就形成了一个递归
- 递归需要有返回边界，当index遍历到数组a最后一个元素时，递归结束
- 当target变为0时，说明我们已经找到了集合，将该集合加入结果，同样也返回
- 需要考虑优化的一点是，如果数组中全是一样的数应该如何处理

- 上面的做法是放进一个循环处理，如果选择不放进循环处理，是否也能有一个正常的思路
- 一个做法是引入外部哈希表，以某某index为起始点，目标值为target的哈希表，如果已经求过，就不必再回溯，通过这种方式避免重复运算

- 暂时就不写了，思路应该是可行的
*/
#include "../headfile/io_for_leetcode.h"
#include <algorithm>
using namespace std;


vector<vector<int>> result;
vector<int> elem_of_result;

void traceback(const vector<int>& candidates, int index, int target) 
{
    if (target == 0)    // 这个最好写在前面
    {
        result.push_back(elem_of_result);
        return;
    }
    
    if (target < 0 || index == candidates.size())   return; // 注意这边右边的那个条件，一定要放在上面那块条件的下方，否则会出错


    elem_of_result.push_back(candidates[index]);
    traceback(candidates, index + 1, target - candidates[index]);
    elem_of_result.pop_back();
    
    traceback(candidates, index + 1, target);       // 选择不加入这个位置的元素
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end()); // 先从小到大排序
    traceback(candidates, 0, target);
    return result;
}

int main()
{
    input input40;
    int target;

    auto vec = input40.input_vector();

    cout << "Please input the target value: ";
    cin >> target;
    
    auto result = combinationSum2(vec, target);
    
    output output40;

    output40.output_matrix(result);
    return 0;
}