#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct StudentInfo
{
    string name;    // 学生名字
    int chinese, math;      // 学生语文数学成绩成绩
};

bool cmpChinese(const StudentInfo &student1, const StudentInfo &student2)
{
    if (student1.chinese != student2.chinese)    return student1.chinese > student2.chinese;
    else   return student1.name < student2.name;
}

bool cmpMath(const StudentInfo &student1, const StudentInfo &student2)
{
    if (student1.math != student2.math)    return student1.math > student2.math;
    else   return student1.name < student2.name;
}

int main ()
{
    vector<StudentInfo> nameGrade;  // 定义一个数组
    int n, i;      // 学生人数，排名方式
    cin >> n >> i;
    cin.get();  // 缓冲换行符
    StudentInfo data;
    for (int i = 0; i < n; i++)
    {
        if (cin >> data.name >> data.chinese >> data.math) nameGrade.push_back(data);
    }
    switch (i)
    {
    case 1:
        sort(nameGrade.begin(), nameGrade.end(), cmpChinese);
        break;
    case 2:
        sort(nameGrade.begin(), nameGrade.end(), cmpMath);
        break;
    default:
        cout << "不存在其余的排序方式！" << endl;
        break;
    }
    for (auto info : nameGrade)
    {
        cout << info.name << " " << info.chinese << " " << info.math << endl;
    }
    return 0;
}


