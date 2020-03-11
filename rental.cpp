#include "stdafx.h"
#include "rental.h"
#include "car.h"
#include <exception>
#include <iostream>
#include <fstream>


rental::rental()	//default consructor
{
	rentStartDate = 0;
	rentEndDate = 0;
	rentedCar = car();
}

rental::rental(int _rentStartDate, int _rentEndDate, car *_rentedCar)	//constructor with 3 parameters
{
	try
	{
		if (_rentEndDate <= _rentStartDate)	//throw an exception if start date is after end date
			throw std::logic_error("Some of the rental start and end dates are wrong!");

		rentStartDate = _rentStartDate;
		rentEndDate = _rentEndDate;	//if no problem, initialize 
		rentedCar = *_rentedCar;

	}
	catch (std::logic_error& error) 
	{
		std::cout << error.what() << std::endl;
	}
}

rental::rental(int _rentStartDate, int _rentEndDate, std::string _numberPlate, int _buildYear, std::string _fuelType, float _totalKm, int _rentalPricePerDay) //: rentStartDate(_rentStartDate), rentEndDate(_rentEndDate), rentedCar(_numberPlate, _buildYear, _fuelType, _totalKm, _rentalPricePerDay)//with 7 parameters
{	//constructor with many parameters
	try
	{
		if (_rentEndDate <= _rentStartDate)
			throw std::logic_error("Some of the rental start and end dates are wrong!");

		rentStartDate = _rentStartDate;
		rentEndDate = _rentEndDate;
		rentedCar = car(_numberPlate, _buildYear, _fuelType, _totalKm, _rentalPricePerDay);

	}
	catch (std::logic_error& error)
	{
		std::cout << error.what() << std::endl;
	}
	
}


void rental::rentStartDateSetter(int _rentStartDate)	//set the start date
{
	rentStartDate = _rentStartDate;
}
void rental::rentEndDateSetter(int _rentEndDate)	//set the end date
{
	rentEndDate = _rentEndDate;
}

int rental::rentStartDateGetter()	//return the start date
{
	return rentStartDate;
}
int rental::rentEndDateGetter()		//return the end date
{
	return rentEndDate;
}

int rental::lengthOfRental()	//calculate the length of the rental
{
	int length = rentEndDate - rentStartDate;

	return length;	//and return it
}
int rental::priceOfRent(rental rentedVehicle)	//return the rental price of the vehicle from the length of rental and start and end date
{
	int price = lengthOfRental()*rentedCar.carRentalPricePerDayGetter();	//I used carRentalPricePerDayGetter in car class

	return price;	//return the result
}




rental::~rental()
{
}
