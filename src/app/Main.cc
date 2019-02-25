#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <assert.h>   

#include "analyzer/JobConfiguration.h"
#include "analyzer/MakeAnalyzer.h"

int main(int argc, char *argv[])
{
    std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();

    JobConfiguration conf(argc, argv);

    auto analyzer = MakeAnalyzer(conf);
    analyzer->Analyze();
    analyzer->Save();

    std::clock_t c_end = std::clock();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << std::fixed << std::setprecision(2) << "CPU time used: "
              << 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: "
              << std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms\n";

    return 0;
}
