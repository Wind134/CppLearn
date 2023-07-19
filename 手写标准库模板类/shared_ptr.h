/*
尝试自行实现一个智能指针shared_ptr：成员变量主要包括两个：
    - 指向自身引用计数的指针
    - 指向对象的指针

- 同时也尝试模板类的写法，初始来看
*/
#include <cstddef>
#include <memory>

template<typename T>
class SharedPtr {
public:
    // 构造函数，先是参数为空的构造函数
    explicit SharedPtr(): obj_ptr(nullptr), count_ptr(new size_t(0)) {}
    explicit SharedPtr(T* ptr): obj_ptr(ptr), count_ptr(new size_t(1)) {}; 

    // 析构函数
    ~SharedPtr() {
        if (--(*count_ptr) == 0) {  // 当引用计数为0的时候
            delete obj_ptr;     // 删除那片空间
            delete count_ptrl;  // 不再需要存储引用计数
            obj_ptr = nullptr;  // 指针本身置空，以解决悬空指针的问题
            count_ptr = nullptr;  
        }
    }

    // 拷贝构造函数
    SharedPtr(const SharedPtr& s_ptr) {
        obj_ptr = s_ptr.obj_ptr;
        count_ptr = s_ptr.count_ptr;    // 复制指针值
        *(count_ptr)++; // 引用计数加1
    }

    // 拷贝赋值运算符
    SharedPtr& operator=(const SharedPtr& s_ptr) {
        if (this != &s_ptr) {   // 不一样才需要处理
            // 要先减少本对象的引用计数，如果处理之后为0，那么需要释放对象的空间
            if (--(*count_ptr) == 0) {
                delete obj_ptr;
                delete count_ptr;
            }

            obj_ptr = s_ptr.obj_ptr;
            count_ptr = s_ptr.count_ptr;
            *(count_ptr)++;
        }    

        return *this;
    }

    // 移动构造函数，没有释放右值的指针，个人感觉右值不是会自动回收的吗
    SharedPtr(SharedPtr&& s_ptr): obj_ptr(s_ptr.obj_ptr), count_ptr(s_ptr.count_ptr) {
        *(count_ptr)++;
    }

    // 移动赋值运算符
    SharedPtr& operator=(SharedPtr&& s_ptr) {
        // 应该是不需要判断相等吧，毕竟左值和右值(不一定正确)
        if (--(*count_ptr) == 0) {
            delete obj_ptr;
            delete count_ptr;
        }

        obj_ptr = s_ptr.obj_ptr;
        count_ptr = s_ptr.count_ptr;
        *(count_ptr)++;

        return *this;
    }

    T& operator*() const { return *obj_ptr; }   // 重载运算符*
    T* operator->() const { return &this->operator*(); }   // ->运算符左边跟的都是指针(*object).fun <=> object->fun

    T* get() const { return obj_ptr; }

    size_t use_count() const { return *count_ptr; }

    bool unique() const { return *count_ptr == 1; }
private:
    size_t* count_ptr;
    T* obj_ptr;
};