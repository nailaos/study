#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int counter = 1;

int main() {
    if (fork() == 0) {
        counter--;
        exit(0);
    } else {
        wait(NULL);
        counter++;
        printf("counter = %d\n", counter);
    }
    exit(0);
}
