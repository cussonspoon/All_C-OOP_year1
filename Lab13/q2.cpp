#include <iostream>
#include <vector>
class Building {
    public:
        virtual double calculate(){
            return 0;
        }
};

class Car {
    public:
        virtual double calculate(){
            return 0;
        }
};

class Bicycle {
    public:
        virtual double calculate(){ 
            return 0;
        }
};

class Factory : public Building{
    private:
        double productionHours;
        double energyperHours;
        double wasteperHours;
    public:
        Factory(double pph, double eph, double wph) : productionHours(pph), energyperHours(eph), wasteperHours(wph){}
        double getprodperhour(){
            return productionHours;
        }
        double getenergyperhour(){
            return energyperHours;
        }
        double getwasteperhour(){
            return wasteperHours;
        }
        double calculate(){
            return productionHours*energyperHours*wasteperHours;
        }

};

class ElectricCar : public Car{
    private:
        double batteryCapacity;
        double chargeEfficiency;
    public:
        ElectricCar (double batt, double chargeeff) : batteryCapacity(batt), chargeEfficiency(chargeeff){}
        double getbattcapacity(){
            return batteryCapacity;
        }
        double getchargeEff(){
            return chargeEfficiency;
        }
        double calculate(){
            return batteryCapacity*chargeEfficiency;
        }
};

class EnchancedBuilding : public Building{
    private:
        double energyPerPerson;
        double occupant;
    public:
        EnchancedBuilding(double epp, double occupant) : energyPerPerson(epp), occupant(occupant){}
        double getEnergyPerPerson(){
            return energyPerPerson;
        }
        double getOccupant(){
            return occupant;
        }
        double calculate(){
            return energyPerPerson*occupant;
        }
};

class ModifiedCar : public Car{
    private:
        double fuelConsumption;
        double fuelEfficiency;
    public:
        ModifiedCar(double fc, double feff) : fuelConsumption(fc), fuelEfficiency(feff){}
        double getfuelConsumption(){
            return fuelConsumption;
        }
        double getfuelEfficiency(){
            return fuelEfficiency;
        }
        double calculate(){
            return fuelConsumption*fuelEfficiency;
        }

};
class ComplexBicycle : public Bicycle{
    private:
        double Emissionperunit;
        double unit;
    public:
        ComplexBicycle(double Epu, double unit) : Emissionperunit(Epu), unit(unit){}
        double getEmissionperunit(){
            return Emissionperunit;
        }
        double getunit(){
            return unit;
        }
        double calculate(){
            return Emissionperunit*unit;
        }
};

int main() {
    double pph, eph, wph;
    std::cout << "Enter production hours, energy per hour, and waste per hour for the factory: ";
    std::cin >> pph >> eph >> wph;
    Factory factory(pph, eph, wph);

    double batt, chargeeff;
    std::cout << "Enter battery capacity and charge efficiency for the electric car: ";
    std::cin >> batt >> chargeeff;
    ElectricCar electricCar(batt, chargeeff);

    double epp, occupant;
    std::cout << "Enter energy per person and number of occupants for the enhanced building: ";
    std::cin >> epp >> occupant;
    EnchancedBuilding building(epp, occupant);

    double fc, feff;
    std::cout << "Enter fuel consumption and fuel efficiency for the modified car: ";
    std::cin >> fc >> feff;
    ModifiedCar modifiedCar(fc, feff);

    double Epu, unit;
    std::cout << "Enter emission per unit and number of units for the complex bicycle: ";
    std::cin >> Epu >> unit;
    ComplexBicycle bicycle(Epu, unit);

    Building* buildingPtr = &factory;
    Car* carPtr = &electricCar;
    Building* building2Ptr = &building;
    Car* car2Ptr = &modifiedCar;
    Bicycle* bicyclePtr = &bicycle;

    std::vector<Building*> all_building = {&factory, &building};
    std::vector<Car*> all_car = {&electricCar, &modifiedCar};
    std::vector<Bicycle*> all_bicycle = {&bicycle};

    double total_emission = 0;

    for (const auto& ptr : all_building){
        total_emission += ptr->calculate();
    }
    for (const auto& ptr : all_car){
        total_emission += ptr->calculate();
    }
    for (const auto& ptr : all_bicycle){
        total_emission += ptr->calculate();
    }

    std::cout << "Factory total waste production: " << buildingPtr->calculate() << " tons of C02" << std::endl;
    std::cout << "Electric Car total charging time: " << carPtr->calculate() << " tons of C02" << std::endl;
    std::cout << "Enhanced Building total energy consumption: " << building2Ptr->calculate() << " tons of C02" << std::endl;
    std::cout << "Modified Car total fuel consumption: " << car2Ptr->calculate() << " tons of C02" << std::endl;
    std::cout << "Complex Bicycle total emission: " << bicyclePtr->calculate() << " tons of C02" << std::endl;
    std::cout << "Total emission: " << total_emission << " tons of C02" << std::endl;
    return 0;
}
