#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int num_processes = 0;
    
    // 循环执行三次fork()函数
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        
        if (pid == 0) {
            // 子进程打印出自己所处的循环次数之后就不再继续fork了
            // 也就是说子进程不参与fork，只有父进程参与，也就是说，子进程进入不到下一个循环了
            // 同时在这里子进程继承的num_processes上次循环后num_processes的值
            printf("子进程 %d\n", i + 1);
            break;
        } else if (pid > 0) {
            // 父进程
            num_processes++;
        } else {
            // fork()函数调用失败
            printf("fork()函数调用失败\n");
            return 1;
        }
    }
    

    // 父进程打印子进程数量
    if (num_processes > 0) {
        printf("总共创建了%d个子进程\n", num_processes);
    }
    // while (1) {}
    
    return 0;
}
