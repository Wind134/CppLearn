/* 给定n个考生的姓名、分数，将这些考生按分数从高到低进行排序,分数相同时
按姓名的字典序从小到大进行排序，输出排序后的结果。 */

/* 这玩意儿的新颖性在于，考虑到使用istringstream，但是成绩显然是int形式，string处理是不太方便
的办法，因此一个替代性比较好的方案就是使用结构体 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct StudentInfo
{
    string name;    // 学生名字
    int grade;      // 学生成绩
};

bool cmp(const StudentInfo &student1, const StudentInfo &student2)
{
    if (student1.grade != student2.grade)    return student1.grade > student2.grade;
    else   return student1.name < student2.name;
}

int main ()
{
    vector<StudentInfo> nameGrade;  // 定义一个数组
    int n;      // 学生人数
    cin >> n;
    cin.get();  // 缓冲换行符
    StudentInfo data;
    for (int i = 0; i < n; i++)
    {
        if (cin >> data.name >> data.grade) nameGrade.push_back(data);
    }
    sort(nameGrade.begin(), nameGrade.end(), cmp);
    for (auto info : nameGrade)
    {
        cout << info.name << " " << info.grade << endl;
    }
    return 0;
}


