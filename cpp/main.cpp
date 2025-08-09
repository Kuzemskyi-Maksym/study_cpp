#include <iostream>
#include "Car.h"
#include <memory>

std::unique_ptr<Car> createCar(const std::string& brand, int year);
void useCar(const std::unique_ptr<Car>& car);

int main() {

	auto car_ptr = createCar("Toyota", 2020);
	car_ptr->displayInfo();

    std::unique_ptr<Car[]> cars = std::make_unique<Car[]>(3);
    cars[0] = Car("BMW", 2018);
    cars[1] = Car("Audi", 2019);
    cars[2] = Car("Mercedes", 2021);
    
    std::cout << "\n--- Garage ---\n";
    for (int i = 0; i < 3; i++) {
        cars[i].displayInfo();
    }

    return 0;
}

std::unique_ptr<Car> createCar(const std::string& brand, int year) {
    return std::make_unique<Car>(brand, year);
}

void useCar(const std::unique_ptr<Car>& car) {
	std::cout << "Using car: ";
    car->drive();
}