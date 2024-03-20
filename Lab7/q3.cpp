#include <iostream>
#include <string>


std::string reverse(const std::string& str, int index = 0) {
    if (index == str.length()) {
        return "";
    }
    return reverse(str, index + 1) + str[index];
}

int main() {
    std::string input;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "Reversed string: " << reverse(input) << std::endl;

    return 0;
}
