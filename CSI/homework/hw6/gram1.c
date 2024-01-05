#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char const* argv[]) {
    int pid, fdx, fdy, fdz;
    char buf[8];

    fdx = open("file1.txt", O_RDWR);
    fdy = open("file1.txt", O_RDWR);
    fdz = open("file1.txt", O_RDWR);

    read(fdx, buf, 2);
    read(fdy, buf + 2, 4);

    if ((pid = fork()) == 0) {
        dup2(fdx, STDOUT_FILENO);
        dup2(fdy, STDIN_FILENO);
        execl("gram2", "gram2", NULL);
    }

    wait(NULL);

    read(fdy, buf + 6, 2);
    write(fdz, buf + 6, 2);
    write(fdx, buf + 4, 2);
    write(fdx, buf + 2, 2);

    close(fdx);
    close(fdy);
    close(fdz);

    return 0;
}