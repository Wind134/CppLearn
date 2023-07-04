/*
下面是一段生产者——消费者线程的演示：
- 生产的速度和消费的速度可能会不同，但由于互斥同步处理的存在
- 一定是先生产再消费，消费者只能消费已生产的

学习到的新知识点：
- condConsumer.notify_one()与condConsumer.wait(lock)配合使用
- condProducer.notify_one()与condConsumer.wait(lock)配合使用
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::mutex mtx;
std::condition_variable condConsumer;
std::condition_variable condProducer;
std::queue<int> dataQueue;
const int MAX_QUEUE_SIZE = 10;

void producer() {
    for (int i = 0; i < 20; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));    // 通过睡眠延迟
        std::unique_lock<std::mutex> lock(mtx); // 上锁

        // 如果队列已满，则等待消费者消费数据
        // [] { return dataQueue.size() < MAX_QUEUE_SIZE; }返回一个bool状态，如果为false会被阻塞
        condProducer.wait(lock, [] { return dataQueue.size() < MAX_QUEUE_SIZE; });

        // 生产数据并放入队列
        dataQueue.push(i);
        std::cout << "Produced: " << i << std::endl;

        // 通知消费者有新数据可用，每生产一个，就通知一下
        condConsumer.notify_one();
    }
}

void consumer() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::unique_lock<std::mutex> lock(mtx);

        // 如果队列为空，则等待生产者生产数据
        condConsumer.wait(lock, [] { return !dataQueue.empty(); });

        // 消费数据并从队列中移除
        int data = dataQueue.front();
        dataQueue.pop();
        std::cout << "Consumed: " << data << std::endl;

        // 通知生产者有空闲位置
        condProducer.notify_one();

        // 如果数据为特定值，表示结束消费
        if (data == 19) {
            break;
        }
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
