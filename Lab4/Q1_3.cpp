#include <iostream>
#include <vector>
#include <list>

void remove_negative(std::list<double>& lst){
    lst.remove_if([](double n) {return n < 0;});
}

int main(){
    std::list lst = {0.8, -5.1, 1.6, -6.5, 10.5};
    std::cout << "Original vector: ";
    for (float element : lst){
        std::cout << element << " ";
    }
    std::cout << "\n";
    remove_negative(lst);
    std::cout << "Vector after removing negative numbers: ";
    for (float element : lst){
        std::cout << element << " ";
    }
    std::cout << "\n";
}