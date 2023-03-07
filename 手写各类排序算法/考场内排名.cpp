/* 给定n个考场中所有考生的姓名、分数，输出这些考生的考场内排名。

注：
排名 = 高于当前分数的考生个数 + 1
分数相同时排名相同 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct StudentInfo
{
    string name;    // 学生名字
    int score, rank;      // 学生分数，排名
};

// 处理姓名的字典序
bool cmpName(const StudentInfo &student1, const StudentInfo &student2)
{
    return student1.name < student2.name;

}

// 处理分数
bool cmpScore(const StudentInfo &student1, const StudentInfo &student2)
{   
    return student1.score > student2.score;
}

int main()
{
    int n;  // 考场的数目
    int studentNums = 0;    // 主要是为了控制接下来循环内的排序
    vector<StudentInfo> info;
    cin >> n;   // 输入
    getchar();  // 接换行缓冲
    StudentInfo data;
    for (int i = 0; i < n; i++) // 开始输入每个考场的人数及成绩信息
    {
        int personNums;
        cin >> personNums;
        for (int j = 0; j < personNums; j++)
        {
           if (cin >> data.name >> data.score)  info.push_back(data);
        }
        // 由于是考场内排名，我们需要在每个数据都输入好了之后进行排序处理
        sort(info.begin() + studentNums, info.begin() + studentNums + personNums, cmpScore);    // 控制循环内排序
        // 经过上面的处理，一个循环内的分数已经是有序的了，接下来应该处理分数排名的问题
        // 但这边有个细节是，我们必须要注意数组info的下标
        info[studentNums].rank = 1; // 先记下第一名
        for (int k = studentNums + 1; k < studentNums + personNums; k++)
        {
            /* 处理排名的问题 */
            if (info[k].score != info[k - 1].score) info[k].rank = k - studentNums + 1;
            else    info[k].rank = info[k - 1].rank;
        }
        studentNums += personNums;  // 记录几个考场的总人数        
    }
    sort(info.begin(), info.begin() + studentNums, cmpName);
    for ( auto data : info)
    {
        cout << data.name << " " << data.score << " " << data.rank << endl;
    }
}