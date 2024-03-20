#include <iostream>
#include <string>

class HeartRateMoniter{
    public:
        std::string firstname;
        std::string lastname;
        int year;
        int month;
        int day;
        int age = 2023 - year;
        HeartRateMoniter( std::string firstname, std::string lastname, int year, int month, int day)
        : firstname(firstname), lastname(lastname), year(year), month(month), day(day){
            if (month > 12 || (month == 12 && day >= 28) ){
            age = age - 1;
        };
        }
        int maximum_hr = 220 - age;
        int target_hr_low = maximum_hr*0.5;
        int target_hr_high = maximum_hr*0.85;
        void displayinformation(){
            std::cout << "Hello, " << age << " years old " << firstname << " " << lastname << "." << "\n";
            std::cout << "Your maximum heart rate should be " << maximum_hr << " beats per minute." << "\n";
            std::cout << "Your target heart rate range is " << target_hr_low << " - " << target_hr_high << " beats per minute." << "\n";
        }
};

int main(){
    std::string fn;
    std::string ln;
    int y;
    int m;
    int d;
    std::cout << "Enter your first name: ";
    std::cin >> fn;
    std::cout << "Enter your last name: ";
    std::cin >> ln;
    std::cout << "Enter your birth year (YYYY): ";
    std::cin >> y;
    while(true){
    std::cout << "Enter your birth month (MM): ";
    std::cin >> m;
    if (1 <= m && m <= 12){
        break;
    }
    else{
        continue;
    }
    }
    std::cout << "Enter your birth day (DD): ";
    std::cin >> d;
    HeartRateMoniter hrm1(fn, ln, y, m , d);
    hrm1.displayinformation();
    return 0;
}