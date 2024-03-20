#include <iostream>
#include <vector>
#include <list>

std::vector<double> remove_negative(std::vector<double>& vec){
    std::vector<double> result;
    for (double element : vec){
        if (element > 0){
            result.push_back(element);
        }
    }
    return result;
}

int main(){
    std::vector<double> vec = {0.8, -5.1, 1.6, -6.5, 10.5};
    std::cout << "Original vector: ";
    for (float element : vec){
        std::cout << element << " ";
    }
    std::cout << "\n";
    std::vector<double> result = remove_negative(vec);
    std::cout << "Vector after removing negative numbers: ";
    for (float element : result){
        std::cout << element << " ";
    }
    std::cout << "\n";
}