#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

// Prototype
std::pair<int, int> mystery3(const char *);

void reversestr(const char *s){
    size_t length = std::strlen(s);
    for (size_t i = length; i > 0; --i) {
        std::cout << s[i - 1];
    }

    std::cout << std::endl;
}

int main() {
    char string1[80];
    cout << "Enter a string: ";
    cin >> string1;
    if (std::strlen(string1) > 80){
        cout << "Error : Excess string size limit" << endl;
        return 0;
    }
    std::pair<int, int> result = mystery3(string1);

    cout << "Length of the string: " << result.first << endl;
    cout << "Vowels count: " << result.second << endl;
    cout << "Reverse : "; reversestr(string1);

    return 0;
}

std::pair<int, int> mystery3(const char *s) {
    int x = 0;
    int vowelCount = 0;

    for (x = 0; *s != '\0'; ++s) {
    
        ++x;

        // Check if the current character is a vowel
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' ||
            *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U') {
            ++vowelCount;
        }
    }

    return std::make_pair(x, vowelCount);
}



