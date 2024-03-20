#include <iostream>
#include <cstring>
using namespace std;

void mystery1(char *, const char *, size_t);
bool mystery2(const char *s1, const char *s2) {
    return (std::strstr(s1, s2) != nullptr);
}

int main()
{
    char string1[80];
    char string2[80];
    cout << "Case 1 Normal Concat : Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2, sizeof(string1));
    cout << string1 << endl;
    cout << "Case 2 Overflow : Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2, sizeof(string1));
    cout << "Case 3 substring : Enter two strings: ";
    cin >> string1 >> string2;
    if(mystery2(string1, string2)){
        cout << "Is substring? Yes" << "\n";
    }
    else{
        cout << "Is substring? No" << "\n";

    }
    cout << "Case 4 not substring : Enter two strings: ";
    cin >> string1 >> string2;
    if(mystery2(string1, string2)){
        cout << "Is substring? Yes" << "\n";
    }
    else{
        cout << "Is substring? No" << "\n";

    }
    return 0;
} // end main

void mystery1(char *s1, const char *s2, size_t size)
{

    while (*s1 != '\0' && size > 1)
        ++s1, --size;
    if (size <= 1)
    {
        cout << "Error: Insufficient size for concatenation." << "\n";
        return;
    }
    for (; (*s1 = *s2); ++s1, ++s2, --size);
    *s1 = '\0';
}

