/*
这个例子展示了stat函数的使用，stat是POSIX接口中极其重要的一个函数
- 返回值为0表明成功获取了元数据信息
- 返回值为-1则表明信息获取失败，可以通过perror函数返回具体原因
*/
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>

int main() {
    const char* path = "/home/ping/资料笔记/CppLearn/POSIX接口/";
    struct stat fileStat;

    if (stat(path, &fileStat) == 0) {
        printf("File size: %ld bytes\n", fileStat.st_size);
        printf("Last modified time: %s", ctime(&fileStat.st_mtime));
        printf("File permissions: %o\n", fileStat.st_mode & 0777);
    } else {
        perror("stat");     // 输出错误信息
    }

    return 0;
}
