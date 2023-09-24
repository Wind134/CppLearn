#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct Test
{
    int num;
    int age;
};

void* print(void* arg) {
    printf("This is thread %ld\n", pthread_self());

    struct Test* t = (struct Test*)arg;
    t->num = 100;
    t->age = 6;
    pthread_exit(t);
    return NULL;
}

int main() {
    pthread_t p_id;
    struct Test t;

    int res = pthread_create(&p_id, NULL, print, &t);

    printf("main thread %ld\n", pthread_self());

    void* ptr;
    pthread_join(p_id, &ptr);
    struct Test* pt = (struct Test*)ptr;

    printf("num: %d, age = %d\n", t.num, t.age);
    return 0;
}