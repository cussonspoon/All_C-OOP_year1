#include <iostream>
#include <limits>
#include <random>
#include <algorithm>

int Rand() {
    int arr[10];
    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<int> distribution(0, 100);
    return distribution(generator);
}

int findMax(int *arr, int n) {
    if (n == 1) {
        return arr[0];
    }
    
    int rest = findMax(arr+1, n-1);
    
    return std::max(arr[0],rest);
}

int main() {
    int arr[10];
    for (int i=0; i < 10; i++) {
        arr[i] = Rand();
    }

    std::cout << "generated 10 random integers between 1-100: \n";

    for (int j=0; j<10; j++) {
        std::cout << arr[j] << ' ';
    }
    std::cout << "\n";
    std::cout << "The largest number in the array is: " << findMax(arr,10);
    return 0;
}