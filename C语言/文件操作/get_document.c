/*
getcwd返回的是路径信息，返回的是工作目录的路径，也就是说你在哪个目录下执行这段程序，就返回什么目录

与源码所在路径以及可执行程序所在路径无关
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    char* path;

    if ((path = getcwd(NULL, 256)) != NULL) {
        printf("Current working directory: %s\n", path);
    } else {
        perror("getcwd() error");
        return 1;
    }

    return 0;
}
