#include <cstdio>
#include <cstring>


//两个int型变量
struct Point {
    int x, y;
    Point (){}          //下面因为已经定义了构造函数，因此这一默认构造会被覆盖
                             //为了享受初始化的便捷，同时也能进行不初始化定义结构体变量，这部分还是可以加上
    Point (int _x, int _y): x(_x), y(_y) {}         //_x是一种代表性的写法，一般用于初始化之中？主要是区分变量名！
};

//存储学生id与名字信息
struct Student 
{
    int id;
    char name[11];
    Student () {}           // 没有这行默认构造函数会报错？
    Student (int _id, char _name[])  {
        id= _id; 
        strcpy(name, _name);
    }
};

//存储树节点的信息
struct Node {
    int info;       //节点的data值；
    Node* left;     //左节点，指针类型
    Node* right;  //右节点，同样是指针类型
    Node () {}      //默认构造还是需要的(新版标准？)
    Node (int _info, Node* _left, Node* _right) : info(_info), left(_left), right(_right) {}
};


int main ()
{
    Point point;
    Student student;
    Node node1, node2, node3;
    int x, y, z;
    char name[11];
    scanf("%d %d %d %s", &x, &y, &z, name);
    point = Point(x, y);            // 这样就已经将point这个结构体初始化完成
    student = Student(z, name);
    node1 = Node(x, NULL, NULL);        //第一个节点将x进行构造
    node2 = Node(y, NULL, NULL);        //第二个节点将y进行构造
    node3 = Node(z, &node1, &node2);    //宏观上理解，这一节点左指针指向node1，右指针指向node2
    printf("%d %d\n", point.x, point.y);
    printf("%d %s\n", student.id, student.name);
    printf("%d %d", node3.left->info, node3.right->info);
    return 0;
}