#include "Car.h"

Car::Car() 
{
	std::cout << "Default constructor called" << std::endl;
}

Car::Car(const std::string& brand, int year)
	:brand(brand), year(year)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

Car::~Car()
{
	std::cout << "Destructor called" << std::endl;
}

void Car::setBrand(const std::string& nbrand)
{
	if (!nbrand.empty())
		this->brand = nbrand;
	else
		std::cout << "Brand cannot be empty." << std::endl;
}

void Car::setYear(int nyear)
{
	if (nyear > 1885) // The first car was invented in 1886
		this->year = nyear;
	else
		std::cout << "Year must be greater than 1885." << std::endl;
}

std::string Car::getBrand() const
{
	return this->brand;
}

int Car::getYear() const
{
	return this->year;
}

void Car::displayInfo() const
{
	std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
}

void Car::drive() const
{
	std::cout << "Brand is driving." << std::endl;
}

