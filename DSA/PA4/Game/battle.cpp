#include <cstdio>
#include <cstdlib>
#include <stdexcept>

int main() {
    system("g++ randin.cpp -o randin");
    system("g++ main.cpp -o main");
    system("g++ test.cpp -o test");
    int n = 1;
    while (true) {
        try {
            system("./randin > rand.in");
            system("./main < rand.in > 1.out");
            system("./test < rand.in > 2.out");

            if (system("diff 1.out 2.out") != 0) {
                printf("main and test are different output!\n");
                break;
            }

            printf("%d is ok\n", n);

            if (n > 999)
                break;

            n++;
        }
        catch (const std::exception& e) {
            printf("Exception caught: %s\n", e.what());
            break;
        }
        catch (...) {
            printf("An unknown exception occurred.\n");
            break;
        }
    }
    return 0;
}
