#pragma once
#include "car.h"

class bus : public car
{
private:
	int capacity;

public:
	bus();	//default constructor
	bus(std::string _numberPlate, int _buildYear, std::string _fuelType, float _totalKm, int _rentalPricePerDay, int _capacity);	//constructor with many parameters

	void busCapacitySetter(int _capacity);
	int busCapacityGetter();
	
	~bus();
};