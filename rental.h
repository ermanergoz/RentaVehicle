#pragma once
#include "car.h"
#include "bus.h"
#include <vector>
#include <string>

class rental
{
private:

	int rentStartDate;
	int rentEndDate;
	car rentedCar;

public:

	rental();	//default constructor
	rental(int _rentStartDate, int _rentEndDate, car *_rentedCar);	//constructor with 3 parameters	
	rental(int _rentStartDate, int _rentEndDate, std::string _numberPlate, int _buildYear, std::string _fuelType, float _totalKm, int _rentalPricePerDay);	//constructor with many parameters

	void rentStartDateSetter(int _rentStartDate);	//to set the start date
	void rentEndDateSetter(int _rentEndDate);		//to set the end date

	int rentStartDateGetter();	//returns the start date
	int rentEndDateGetter();	//returns the end date

	std::string getNumberPlate() { return rentedCar.carNumberPlateGetter(); }

	int lengthOfRental();	//this functions returns the number of days car was rented
	int priceOfRent(rental rentedVehicle);	//returns the rental price of the vehicle from the length of rental and start and end date

	~rental();
};

