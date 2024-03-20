#include <iostream>

int main(){
    std::cout << "Enter triangle size: " << std::endl;
    int n;
    std::cin >> n;
    for(int i = 0; i!=n; i++){
        for(int j = 0; j != i+1; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i!=n; i++){
        for(int j = 0; j != i+1; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for(int i = n; i>1; i--){
        for(int j = 0; j != i-1; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}