#include <iostream>

class TemperatureConverter{
    private:
        char c;
        double num;
    public:
        TemperatureConverter(char c, double num) : c(c), num(num) {}
        void convert(){
            if (c == 'c' || c == 'C'){
                double result = (num - 32.0) * 5.0 / 9.0;
                std::cout << num << " Fahrenheit is " << result << " Celsius." << std::endl; 

            }
            else if (c == 'f' || c == 'F'){
                double result = (num * 9.0 / 5.0) + 32.0;
                std::cout << num << " Celcius is " << result << " Fahrenheit." << std::endl; 
            }
            else{
                std::cout << "Invalid conversion type" << std::endl;
            }
        }
};

int main(){
    bool is_running = true;
    while (is_running){
        char c;
        double num;
        std::cout << "Enter the temperature: ";
        if (!(std::cin >> num)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Temperature should be double or int " << std::endl;
            continue;
        }
        std::cout << "Convert to (C)elsius or (F)ahrenheit? Enter C or F: ";
        if (!(std::cin >> c)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Type of conversion should only be C or F " << std::endl;
            continue;
        }
        TemperatureConverter converting(c, num);
        converting.convert();
        char yn;
        while (true){
        std::cout << "Do you want to perform another conversion (Y/N): ";
        std::cin >> yn;
        if (yn == 'Y' || yn == 'y'){
            break;
        }
        else if(yn == 'N' || yn =='n'){
            return 0;
        }
        else{
            std::cout << "Invalid input";
            continue;
        }
        }
    }
}