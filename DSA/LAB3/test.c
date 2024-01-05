#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int pid;

void handler(int sig) {
    if (sig == SIGINT && pid != 0) {
        printf("Killing Child process\n"); fflush(stdout); kill(pid, SIGKILL);
    }

    if (pid == 0) {
        printf("Child process receiving Kill\n"); fflush(stdout); exit(-1);
    }
}

int main() {
    pid = fork();
    signal(SIGINT, handler);
    signal(SIGKILL, handler);
    if (pid) {
        int status;
        waitpid(pid, &status, 0); int i = WEXITSTATUS(status);
        printf("child's exit status=%d\n", i);
    } else {
        while (1) {
            sleep(1);
            printf("Waiting...!\n"); fflush(stdout);
        }
    }
    return 0;
}