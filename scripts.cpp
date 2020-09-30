#include <iostream>

int main() {
    std::system("g++ main.cpp src/*.cpp -o main");
    std::system("main.exe");
    return 0;
}