/**
 * 智能指针shared_ptr的引用计数的操作已经是线程安全的；
 * 但是多个线程共享这个智能指针的时候，对智能指针的操作并不一定是线程安全的；
 * 下面这个例子就展示了这一点；
 */

#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

std::mutex mtx;

void threadFunction_1(std::shared_ptr<int> sharedPtr) {
    // 在多个线程中修改 sharedPtr 的引用计数
    for (int i = 0; i < 1000000; ++i) {
        (*sharedPtr)++; // 在多个线程中并发修改 sharedPtr 所指向的资源
    }
}

// 通过加互斥锁的手段实现了线程安全
void threadFunction_2(std::shared_ptr<int> sharedPtr) {
    std::lock_guard<std::mutex> lock(mtx);
    // 在多个线程中修改 sharedPtr 的引用计数
    for (int i = 0; i < 1000000; ++i) {
        (*sharedPtr)++; // 在多个线程中并发修改 sharedPtr 所指向的资源
    }
}

// // 将之设置为原子变量，同样是不错的解决方案
// void threadFunction_3(std::atomic<std::shared_ptr<int>> sharedPtr) {
//     // 在多个线程中修改 sharedPtr 的引用计数
//     for (int i = 0; i < 1000000; ++i) {
//         (*sharedPtr)++; // 在多个线程中并发修改 sharedPtr 所指向的资源
//     }
// }

int main() {
    std::shared_ptr<int> sharedInt_1 = std::make_shared<int>(0);
    std::shared_ptr<int> sharedInt_2 = std::make_shared<int>(0);
    // std::atomic<std::shared_ptr<int>> sharedInt_3(std::make_shared<int>(1));

    std::thread thread1(threadFunction_1, sharedInt_1);
    std::thread thread2(threadFunction_1, sharedInt_1);

    std::thread thread3(threadFunction_2, sharedInt_2);
    std::thread thread4(threadFunction_2, sharedInt_2);

    // std::thread thread5(threadFunction_3, sharedInt_3);
    // std::thread thread6(threadFunction_3, sharedInt_3);

    // 下面就体现了多线程，没错，主函数main是会被阻塞，但是并不意味着
    // thread2线程就一定在要等thread1线程执行完毕之后再执行
    // 验证很简单，只需要将线程函数循环中的值设大一点，就能发现每次运行都有不同的结果
    thread1.join();
    thread2.join();
    
    thread3.join();
    thread4.join();
    
    // thread5.join();
    // thread6.join();

    std::cout << "Final value: " << *sharedInt_1 << std::endl;
    std::cout << "Final value: " << *sharedInt_2 << std::endl;
    // std::cout << "Final value: " << *sharedInt_3 << std::endl;

    return 0;
}
