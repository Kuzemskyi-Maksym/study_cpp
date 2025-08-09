#include <iostream>
#include <string>

class Car {
private:
	std::string brand;
	int year;
public:
	Car();
	Car(const std::string& brand, int year);
	~Car();

	void setBrand(const std::string& nbrand);
	void setYear(int nyear);

	std::string getBrand() const;
	int getYear() const;

	void displayInfo() const;
	void drive() const;

};