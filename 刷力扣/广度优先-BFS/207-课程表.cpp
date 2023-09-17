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
 * 代码中的思路主要是采用了BFS的策略，同时也会提供DFS的版本；
 * 
 * 拓扑排序的原则：对于每一条有向边(u, v)，节点u在节点v之前。
 * 拓扑排序主要用于描述任务之间的依赖关系，确保任务按照一定的顺序执行，以避免循环依赖和死锁等问题。
 * 
 * BFS版本的思路主要是通过一个队列来进行广度优先搜索，初始时，所有入度为0的结点都被放入队列中，他们可以作为拓扑排序中最前面的结点
 * 这些结点之间的顺序无所谓
 * 
 * 广度有线搜索的每一步过程中，将队首节点u取出：
 * - 将u放入答案中
 * - 移除u的所有出边(从这个点出去的边)，即将相邻节点的入度，如果入度能变为0，说明该点
 */
#include "../headfile/io_for_leetcode.h"
using namespace std;

vector<int> indegree;       // 存储每个节点的入度
vector<vector<int>> edges;  // 存储每条边

// 像是判死锁？
// 题目中给定的示例跟有向边所表示的方向正是相反的关系
// 因为会先将边处理成我们熟悉的图的格式
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    edges.resize(numCourses);
    indegree.resize(numCourses);

    // 边的信息记录了某个顶点所有出度所指向的结点
    for (auto&& info : prerequisites) {
        edges[info[1]].push_back(info[0]);
        ++indegree[info[0]];    // 将对应节点的入度加1
    }

    queue<int> q;
    for (int i = 0 ; i < numCourses; ++i) {
        if (!indegree[i])   q.push(i);  // 先将所有入度为0的节点添加进去
    }
    
    int visitedNum = 0;
    while (!q.empty()) {
        ++visitedNum;   // 每访问队列中的一个节点，就将计数加1
        int node = q.front();
        q.pop();
        for (auto&& v : edges[node]) {
            --indegree[v];
            if (indegree[v] == 0)   q.push(v);
        }
    }

    return visitedNum == numCourses;    // 如果每个节点都入过队(即入度都曾为过0)，则表明无环，否则有环
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