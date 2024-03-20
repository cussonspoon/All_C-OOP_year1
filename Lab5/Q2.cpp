#include <iostream>
#include <string>

class PopulationGrowth{
    public:
        int current_population;
        int next_year_population;
        double annual_increase_percent;
        PopulationGrowth(int current_population, double annual_increase_percent)
        : current_population(current_population), annual_increase_percent(annual_increase_percent){}
        void displayinformation(){
            int double_population = current_population*2;
            int current_temp = current_population;
            int next_temp;
            for (int i = 1 ; i <= 75 ; i++){
                next_temp = current_temp*annual_increase_percent;
                if (current_temp >= double_population){
                    std::cout << "The population will be doubled at year " << i << "\n";
                    break;
                }
                current_temp = next_temp;
            }
            std::cout << "Year   Projected Population   Annual increase" << "\n";
            for (int i = 1 ; i <= 75 ; i++){
                next_year_population = current_population*annual_increase_percent;
                int annual_increase = next_year_population - current_population;
                std::cout << i << "       " << current_population << "              " << annual_increase << "\n";
                current_population = next_year_population;
            }
        }
        
};

int main(){
    int world_population;
    double growth_rate;
    std::cout << "Enter the current world population: ";
    std::cin >> world_population;
    std::cout << "Enter the annual growth rate (percentage): ";
    std::cin >> growth_rate;
    PopulationGrowth pop1(world_population, growth_rate);
    pop1.displayinformation();
    return 0;
}