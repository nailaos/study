#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<double> mainDurations;
    std::vector<double> testDurations;

    int n = 1;
    int M = 3;
    if (argc == 2)
        M = atoi(argv[1]);
    double totalMainDuration = 0.0;
    double totalTestDuration = 0.0;

    system("g++ randin.cpp -o randin");
    system("g++ avltree.cpp -o main");
    system("g++ splay.cpp -o test");

    while (true) {
        try {
            system("./randin > rand.in");

            std::cout << "rand input is ok" << std::endl;

            auto mainStart = std::chrono::high_resolution_clock::now();
            system("./main < rand.in > 1.out");
            auto mainEnd = std::chrono::high_resolution_clock::now();
            double mainDuration = std::chrono::duration_cast<std::chrono::milliseconds>(mainEnd - mainStart).count();

            auto testStart = std::chrono::high_resolution_clock::now();
            system("./test < rand.in > 2.out");
            auto testEnd = std::chrono::high_resolution_clock::now();
            double testDuration = std::chrono::duration_cast<std::chrono::milliseconds>(testEnd - testStart).count();

            mainDurations.push_back(mainDuration);
            testDurations.push_back(testDuration);

            totalMainDuration += mainDuration;
            totalTestDuration += testDuration;

            if (system("diff 1.out 2.out") != 0) {
                printf("main and test are different output!\n");
                break;
            }

            printf("%d is ok\n", n);

            if (n >= M)
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

    // Open the file for writing timing information
    std::ofstream timingFile("timing_results.txt", std::ios::app);

    for (int i = 0; i < n; ++i) {
        timingFile << "Iteration " << i + 1 << ": AvlTree: " << mainDurations[i] << " ms, SplayTree: " << testDurations[i] << " ms" << std::endl;
    }

    timingFile << "AvlTree Average Duration: " << totalMainDuration / n << " ms" << std::endl;
    timingFile << "SplayTree Average Duration: " << totalTestDuration / n << " ms" << std::endl;

    // Close the file
    timingFile.close();

    std::cout << "AvlTree Average Duration: " << totalMainDuration / n << " ms" << std::endl;
    std::cout << "SplayTree Average Duration: " << totalTestDuration / n << " ms" << std::endl;

    return 0;
}
