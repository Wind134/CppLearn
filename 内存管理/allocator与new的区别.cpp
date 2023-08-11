/*


- 下面这个例子很好的展示了allocator与new的区别：
    -- new与对象的构造绑定在了一起
    -- allocator只负责分配内存，对象的构造可以分开进行

- 同时也很好的展示了虚函数的使用，之所以采用这么一个案例是因为，下面两个类的大小，是一致的

    -- 但是并没有顺利体现出多态性，这是一个疑问
    -- 留坑，待后续
*/
#include <iostream>
#include <memory>


struct Circle {
    virtual void draw() {
        std::cout << "Drawing a circle." << std::endl;
    }
};

struct Rectangle : public Circle {
    void draw() override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

int main() {

    // 理论上这两个对象是一样大的
    Circle c1;
    Rectangle t1;
    std::cout << "The size of Circle object: " << sizeof(c1) << std::endl
              << "The size of Rectangle object: " << sizeof(t1) << std::endl;
    std::allocator<Circle> alloc; // 使用allocator分配Shape对象的内存

    // 分配2个Shape对象的内存
    Circle* shapes = alloc.allocate(2);

    // 在分配的内存块中构造 Circle 和 Rectangle 对象
    alloc.construct(shapes, Circle());
    alloc.construct(shapes + 1, Rectangle());

    // 调用对象的 draw() 方法
    shapes->draw();         // 调用 Circle 对象的 draw() 方法
    (shapes + 1)->draw();   // 调用 Rectangle 对象的 draw() 方法

    // 使用 allocator 销毁对象并释放内存
    alloc.destroy(shapes);
    alloc.destroy(shapes + 1);
    alloc.deallocate(shapes, 2);

    return 0;
}
