#include <iostream>
#include <random>

class GuessingGame{
    private:
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distribution;
    int num;
    public:
        GuessingGame() : gen(rd()), distribution(1, 100), num(distribution(gen)){}
        void guess(){
            int count = 10;
            int x;
                std::cout << "Guess the number (between 0 and 100): ";
                while (count > 0){
                if (!(std::cin >> x) || x < 1 || x > 100) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
                    continue;
            }
                if (x == num){
                    std::cout << "Congratulation! You win." << std::endl;
                    return;
                }
                else if (x > num){
                    std::cout << "Lower than your number. Try again" << std::endl;
                    count--;
                    continue;
                }
                else if (x < num){
                    std::cout << "Higher than your number. Try again" << std::endl;
                    count--;
                    continue;
                }
            }
            std::cout << "You've lost, the number was " << num << std::endl;
        }
};

int main(){
    GuessingGame game;
    game.guess();
}