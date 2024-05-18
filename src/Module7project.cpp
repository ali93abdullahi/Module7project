//============================================================================
// Name        : Module7project.cpp
// Author      : Ali Abdullahi
// Version     :
// Copyright   : Your copyright notice
// Description : Portfolio Project part 1
//============================================================================

#include <iostream>
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Count Up: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void countDown() {
    for (int i = 20; i >= 0; --i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Count Down: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::thread t1(countUp);
    t1.join(); // Wait for thread t1 to finish before starting thread t2

    std::thread t2(countDown);
    t2.join(); // Wait for thread t2 to finish

    return 0;
}
