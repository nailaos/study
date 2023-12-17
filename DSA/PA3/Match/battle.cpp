#include <cstdio>
#include <cstdlib>
#include <stdexcept>

int main() {
    system("g++ randin.cpp -o randin");
    system("g++ match.cpp -o match");
    system("g++ common.cpp -o common");
    int n = 1;
    while (true) {
        try {
            system("./randin > rand.in");
            system("./match < rand.in > 1.out");
            system("./common < rand.in > 2.out");

            if (system("diff 1.out 2.out") != 0) {
                printf("match and common are different output!\n");
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
