#include <pthread.h>
#include <stdio.h>

int a = 0;
void* test(void* ptr) { a++;  return NULL; }

int main() {
    pthread_t pid;
    pthread_create(&pid, NULL, test, NULL);
    pthread_join(pid, NULL);
    printf("a=%d\n", a);
    return 0;
}