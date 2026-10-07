#pragma once

#include <chrono>
#include <iostream>
#include <string>

class BenchmarkTimer {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::string testName;

public:
    BenchmarkTimer(const std::string& name) : testName(name) {
        startTime = std::chrono::high_resolution_clock::now();
    }

    ~BenchmarkTimer() {
        auto endTime = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTime).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTime).time_since_epoch().count();
        auto duration = end - start;
        
        std::cout << "[BENCHMARK] " << testName << " Execution Time: " 
                  << duration << " microseconds (us) [" 
                  << duration / 1000.0 << " ms]" << std::endl;
    }
};