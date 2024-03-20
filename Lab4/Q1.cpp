#include <iostream>
#include <vector>
#include <list>

void lshift(std::list<int>& lst, int pos){
    for(int i = 0; i < pos; i++){
        lst.pop_front();
    }
}

void rshift(std::list<int>& lst, int pos){
    for(int i = 0; i < pos; i++){
        lst.push_front(0);
    }
}

int main(){
    std::list<int> lst = {1,2,3,4,5};
    std::cout << "Original sequence : ";
    for (int element : lst){
        std::cout << element << " ";
    }
    std::cout << "\n";
    lshift(lst, 2);
    std::cout << "After lshift by 2 : ";
    for (int element : lst){
        std::cout << element << " ";
    }
    std::cout << "\n";
    rshift(lst, 3);
    std::cout << "After rshift by 3 : ";
    for (int element : lst){
        std::cout << element << " ";
    }
    std::cout << "\n";
    return 0;
}