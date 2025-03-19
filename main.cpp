#include <iostream>
#include <thread>
#include <chrono>

void processo1() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << "Processo 1: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void processo2() {
    for (int i = 1; i <= 10; ++i) {
        std::cout << "Processo 2: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    std::thread t1(processo1);
    std::thread t2(processo2);

    t1.join();
    t2.join();

    std::cout << "Execução simulada de multiprogramação finalizada." << std::endl;

    return 0;
}
