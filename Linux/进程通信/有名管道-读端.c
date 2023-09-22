#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main() {
    // 定义有名管道的文件路径
    const char *fifo_path = "./my_fifo";
    
    // 打开有名管道以读取数据
    int fd = open(fifo_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    
    // 读取数据并显示
    char buffer[100];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }
    
    printf("Received data: %.*s\n", (int)bytes_read, buffer);
    
    // 关闭管道
    close(fd);
    
    return 0;
}

