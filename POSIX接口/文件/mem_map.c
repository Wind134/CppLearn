/*
展示了POSIX接口中内存映射的使用，同时展示了
lseek也属于POSIX中文件操作的函数
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    // 打开文件
    int fd = open("/home/ping/资料笔记/CppLearn/C语言/文件操作/data.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 获取文件大小，第二个参数是相对于第三个参数的偏移量
    off_t file_size = lseek(fd, 0, SEEK_END);

    // 将文件映射到内存，第一个参数代表映射的起始地址(为NULL则自动选择)，第二个参数代表映射的大小
    // 第三个参数是内存保护标志，表明可读取；第四个参数是映射的标志，指定映射类型和其他选项
    // 第五个参数是文件描述符，第六个参数文件的偏移量
    char* mapped_file = mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped_file == MAP_FAILED) {    // 如果失败
        perror("mmap");
        close(fd);
        return 1;
    }

    // 在内存中访问文件内容
    printf("File contents: %s\n", mapped_file);

    // 解除内存映射，通过munmap函数进行
    if (munmap(mapped_file, file_size) == -1) {
        perror("munmap");
        close(fd);
        return 1;
    }

    // 关闭文件
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}
