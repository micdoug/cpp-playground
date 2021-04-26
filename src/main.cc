#include <iostream>
#include <string_view>

void printMessage(std::string_view message) {
    std::cout << message;
}


int main() {
    printMessage("Hello, world\n");
    return 0;
}