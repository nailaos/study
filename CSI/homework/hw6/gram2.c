#include <fcntl.h>
#include <unistd.h>

int main() {
    char buf[2];
    read(STDIN_FILENO, buf, 2);
    write(STDOUT_FILENO, buf, 2);
}