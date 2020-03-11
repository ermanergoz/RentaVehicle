#include "stdafx.h"
#include "car.h"
#include <string>
#include <vector>
#include <iostream>


car::car()
{
	numberPlate = "";
	buildYear = 0;
	fuelType = "";
	totalKm = 0;
	rentalPricePerDay = 0;
}

car::car(std::string _numberPlate, int _buildYear, std::string _fuelType, float _totalKm, int _rentalPricePerDay)
{
	bool isWrong=true/*dont initialize it for for loop*/;
	int counter = 0;
	
	try
	{
		/*
		for(unsigned int i=0 ; i < car::fuelDictionary.size() ; ++i)
		{
			if (_fuelType == fuelDictionary[i])	//bunu while a cevir
			{
				isWrong = false;
				break;
			
			}
			else
				isWrong = true;
		}
		*/
		while (counter<car::fuelDictionary.size() && isWrong)	//go through the fuel dictionary vector until we have a matching fuel type
		{
			if (_fuelType == fuelDictionary[counter])	
			{
				isWrong = false;	//if it matches, it is not wrong
			}
				counter++;	//if it doesnt, increase counter to keep searching
		}
		
		if (isWrong == true)	//if we cant find any match, then it is wrong
		{
			throw std::logic_error("The given fuel type is wrong for some of the vehicles!");	//throw an exception
		}
		else
			fuelType = _fuelType;	//if there is no problem, initialize fuel type

		numberPlate = _numberPlate;
		buildYear = _buildYear;
		fuelType = _fuelType;				//and initialize the rest
		totalKm = _totalKm;
		rentalPricePerDay = _rentalPricePerDay;

	}
	catch (std::logic_error& error) {
		std::cout << error.what() << std::endl;
	}	
}

void car::carNumberPlateSetter(std::string _numberPlate)	//sets number plate
{
	numberPlate = _numberPlate;
}
void car::carBuildYearSetter(int _buildYear)	//sets build year
{
	buildYear = _buildYear;
}
void car::carFuelTypeSetter(std::string _fuelType)	//sets fuel type
{
	bool isWrong = true/*dont initialize it for for loop*/;
	int counter = 0;

	try
	{
		/*
		for (unsigned int i = 0; i < car::fuelDictionary.size(); ++i)
		{
			if (_fuelType == fuelDictionary[i])	//bunu while a cevir
			{
				isWrong = false;
				break;
			}
			else
				isWrong = true;
		}
		*/
		while (counter<car::fuelDictionary.size() && isWrong)	//go through the fuel dictionary vector until we have a matching fuel type
		{
			if (_fuelType == fuelDictionary[counter])
			{
				isWrong = false;	//if it matches, it is not wrong
			}
			counter++;	//if it doesnt, increase counter to keep searching
		}
		if (isWrong == true)	//if we cant find any match, then it is wrong
		{
			throw std::logic_error("The given fuel type is wrong for some of the vehicles!");	//throw an exception
		}
		else
			fuelType = _fuelType;
	}
	catch (std::logic_error& error) {
		std::cout << error.what() << std::endl;
	}
}
void car::carTotalKmSetter(float _totalKm)	//sets total km's
{
	totalKm = _totalKm;
}
void car::carRentalPricePerDaySetter(int _rentalPricePerDay)	//sets rental price
{
	rentalPricePerDay = _rentalPricePerDay;
}

std::string car::carNumberPlateGetter()	//to get number plate
{
	return numberPlate;
}
int car::carBuildYearGetter()	//to get build year
{
	return buildYear;
}
std::string car::carFuelTypeGetter()	//to get fuel type
{
	return fuelType;
}
float car::carTotalKmGetter()	//to get total km's
{
	return totalKm;
}
int car::carRentalPricePerDayGetter()	//to get daily price
{
	return rentalPricePerDay;
}

//void operator+(int kilometersToAdd, car &tempCarObj)	//operator + to increase total km of the car
//{
//	tempCarObj.totalKm = tempCarObj.totalKm + kilometersToAdd;
//}

car& car::operator+(int kilometersToAdd)	//operator + to increase total km of the car
{
	totalKm = totalKm + kilometersToAdd;
	return *this;	//dereferencing
}

car::~car()	//default destructor
{

}