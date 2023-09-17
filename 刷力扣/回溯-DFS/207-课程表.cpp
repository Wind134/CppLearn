/**
 * 题目：
 * 你这个学期必须选修numCourses门课程，记为0到numCourses - 1。
 * 在选修某些课程之前需要一些先修课程。
 * 先修课程按数组prerequisites给出，其中prerequisites[i] = [ai, bi]，表示如果要学习课程ai则必须先学习课程bi。
 * 
 * 例如：
 * 先修课程对[0, 1]表示：想要学习课程0，你需要先完成课程1。
 * 
 * 请你判断是否可能完成所有课程的学习？如果可以，返回true；否则，返回false。
 * 
 * 
 * 思路：本质上是判断有向图中是否存在环，存在环则表明死锁，应用了拓扑排序；
 * 代码中的思路主要是采用了dfs的策略，同时也会提供bfs的版本；
 * 
 * 拓扑排序的原则：对于每一条有向边(u, v)，节点u在节点v之前。
 * 拓扑排序主要用于描述任务之间的依赖关系，确保任务按照一定的顺序执行，以避免循环依赖和死锁等问题。
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> visited;
vector<vector<int>> edges;
bool valid = true;  // 初始化的状态是不存在死锁，当dfs搜回来了就表明有环

void dfs(int u) {   // u是顶点信息
    visited[u] = 1; // 搜索过的结点，因为dfs搜索的是下一条
    for (int v: edges[u])  // 搜索每一条边对应的另一个结点
    {
        if (!visited[v]) {
            dfs(v); // 没搜索过的结点，搜索！

            // 不管dfs到哪个结点，只要valid状态变了，代表寄了
            if (!valid) return; // dfs过后状态变了，也就是说成环了，那可以直接返回了
        }
        else if (visited[v] == 1) {
            valid = false;      // 搜啊搜，搜到曾到过的那个结点，寄
            return;
        }

        // 等于2的情况直接跳过，因为这个点已经在拓扑排序的范围内了
    }
    visited[u] = 2; // 经过了所有考验，搜索完毕后的结点位置，可以加入拓扑序列的结点
}

// 像是判死锁？
// 题目中给定的示例跟有向边所表示的方向正是相反的关系
// 因为会先将边处理成我们熟悉的图的格式
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);   // 边数
    visited.resize(numCourses); // 节点数

    // 边的信息记录了某个顶点所有出度所指向的结点
    for (auto&& info : prerequisites) {
        edges[info[1]].push_back(info[0]);
    }

    // 接下来就是使用dfs不断搜索，将正在搜索的结点标记为1，搜索完毕的结点记为2
    // 未搜索的结点默认是0
    // 针对每个结点做判断
    for (int i = 0; i < numCourses && valid; ++i) {
        if (!visited[i])    dfs(i);
    }
    return valid;
}

int main() {
    input input207;
    int nums;

    cin >> nums;
    cin.get();  // 接换行符
    auto pre = input207.input_matrix();

    cout << boolalpha << canFinish(nums, pre) << endl;

    return 0;
}