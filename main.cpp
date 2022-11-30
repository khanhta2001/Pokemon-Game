#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    // srand(time(0));
    int test1 = rand();
    std::cout << rand() << std::endl;
    std::cout << test1 << std::endl;
    std::cout << rand() << std::endl;
    return test1;
}
