#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/**
 * @brief 展示一下有名管道的创建流程
 */
void createNamedPipes() {
    // 定义有名管道的文件路径
    const char *fifo_path = "./my_fifo";
    
    // 创建有名管道
    if (mkfifo(fifo_path, 0666) == -1) {
        perror("mkfifo");
        exit(1);
    }
    
    printf("Named pipe created successfully.\n");
}

int main() {
    createNamedPipes();
    const char* fifo_path = "./my_fifo";

    // 打开有名管道以写入数据
    int fd = open(fifo_path, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    
    // 写入数据到管道
    const char *message = "Hello, named pipe!";
    write(fd, message, strlen(message));
    
    // 关闭管道
    close(fd);
    
    return 0;
}

