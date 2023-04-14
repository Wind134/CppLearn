#include <iostream>
using namespace std;

class Tree {
    int height;
public:
    Tree(int initialHeight);    //构造器
    ~Tree();    //析构器(带波浪线)
    void grow(int years);
    void printsize();
};

Tree::Tree(int initialHeight) {
    height = initialHeight;
    cout << "inside Tree::Tree()" << endl;
}

Tree::~Tree() {
    cout << "inside Tree destructor" << endl;
    printsize();
}

void Tree::grow(int years) {
    height += years;
}

void Tree::printsize() {
    cout << "Tree height is " << height << endl;
}
int main()
{
    cout << "before opening brace" << endl;
    {
        Tree t(12);
        cout << "after Tree creation" << endl;
        t.printsize();
        t.grow(4);
        cout << "before closing brace" << endl;     //这一句结束要出大括号回收内存。也就是进入析构器。
    }
    cout << "after closing brace" << endl;
}

