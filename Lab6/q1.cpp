#include <iostream>
#include <list>

int main(){
    int n;
    while(true){
     std::cout << "Enter the number of integers: ";
     std::cin >> n;
     if(n > 0){
        break;
     }
     std::cout << "Invalid input, Try again" << "\n";
    }
    std::list<int> lst;
    int x;
    std::cout << "Enter integers: " << "\n";
    for(int i = 0; i < n ; i++){  
        std::cin >> x;
        lst.push_back(x);
    }
    int min;
    lst.sort();
    std::cout << "The smallest integer is : " << lst.front() << "\n";
    return 0;
}