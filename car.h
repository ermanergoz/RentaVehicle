#pragma once
#include <string>
#include <vector>

class car
{
protected:
	std::string numberPlate;
	int buildYear;
	std::string fuelType;
	float totalKm;
	int rentalPricePerDay;

public:
	car();	//Default constructor
	car(std::string _numberPlate, int _buildYear, std::string _fuelType, float _totalKm, int _rentalPricePerDay);	//constructor with 5 parameters

	void carNumberPlateSetter(std::string _numberPlate);
	void carBuildYearSetter(int _buildYear);
	void carFuelTypeSetter(std::string _fuelType);			//setters
	void carTotalKmSetter(float _totalKm);
	void carRentalPricePerDaySetter(int _rentalPricePerDay);

	std::vector<std::string> fuelDictionary = { "Gas", "Diesel", "Electric", "Hybrid" };

	std::string carNumberPlateGetter();
	int carBuildYearGetter();
	std::string carFuelTypeGetter();						//getters
	float carTotalKmGetter();
	int carRentalPricePerDayGetter();

	car& operator+(int kilometersToAdd);	//operator + 
																	
	~car();
};



