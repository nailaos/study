#include <pthread.h>
#include <stdio.h>

int a = 0;
void* test(void* ptr) { a++;  return NULL; }

int main() {
    pthread_t pid1, pid2;
    pthread_create(&pid1, NULL, test, NULL);
    pthread_create(&pid2, NULL, test, NULL);
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    printf("a=%d\n", a);
    return 0;
}