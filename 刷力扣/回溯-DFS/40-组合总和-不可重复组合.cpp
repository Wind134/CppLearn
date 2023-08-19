/*
题目：
- 给定一个候选人编号的集合candidates和一个目标数target；
- 找出candidates中所有可以使数字和为target的组合；
- candidates中的每个数字在每个组合中只能使用一次；
- 仍然全为正数；

注意：解集不能包含重复的组合。

思路：回溯
- 数组中的每个元素，都有可能是target目标值的一部分，对于数组中，每个元素而言，有选中与不选中的可能
- 选中这个元素a[index]，那么就相当于是接着针对目标值target-a[index]寻找满足条件的组合，这就形成了一个递归
- 递归需要有返回边界，当index遍历到数组a最后一个元素时，递归结束
- 当target变为0时，说明我们已经找到了集合，将该集合加入结果，同样也返回
- 需要考虑优化的一点是，如果数组中全是一样的数应该如何处理
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
    /* 
     * 每个回溯的函数都要走完这一遍循环，遇到的边界要么是到底了，要么是目标值没有可能了 
    */
    {
        // 去重的核心操作，理解起来很简单，除了第一个我push_back进去之后，后面的相同元素我没必要
        // 再去执行同样的操作，否则就得再次针对相同元素递归，而该递归是没有意义的
        // 这一步的思路是解决后面不少问题的关键(防重复答案)
        // 处理第一个重复元素时，就已经处理了后面那个重复元素会面对的所有可能的情况，因此不必再重复计算
        if (i > index && candidates[i] == candidates[i - 1])    continue;
        elem_of_result.push_back(candidates[i]);
        traceback(candidates, target - candidates[i], i + 1);
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
    input input40;
    int target;

    auto vec = input40.input_vector();

    cout << "Please input the target value: ";
    cin >> target;
    
    auto result = combinationSum(vec, target);
    
    output output40;

    output40.output_matrix(result);
    return 0;
}