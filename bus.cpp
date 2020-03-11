#include "stdafx.h"
#include "bus.h"
#include "car.h"


bus::bus()	//default constructor
{
	numberPlate = "";
	buildYear = 0;
	fuelType = "";
	totalKm = 0;
	rentalPricePerDay = 0;
	capacity = 0;
}

bus::bus(std::string _numberPlate, int _buildYear, std::string _fuelType, float _totalKm, int _rentalPricePerDay, int _capacity) : car(_numberPlate, _buildYear, _fuelType, _totalKm, _rentalPricePerDay)
{	//constructor with many parameters
	//this is how we call base class constructor. It can be done since C++ 11	
	capacity = _capacity;
}

void bus::busCapacitySetter(int _capacity)	//capacity setter
{
	capacity = _capacity;
}
int bus::busCapacityGetter()	//capacity getter
{
	return capacity;
}


bus::~bus()	//default destructor
{
}
