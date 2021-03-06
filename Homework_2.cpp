#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "mainProgramLibrary.h"
#include "car.h"
#include "bus.h"

// Yusuf Erman ERGOZ - TQIHXT
//I choosed task A and K


int main()
{
	std::vector<car> cars;	//to store available cars
	std::vector<bus> buses;	//to store available buses
	std::vector<rental> rentalCars;	//to store rental cars
	std::vector<rental> rentalBuses;	//to store rental buses

	readAvailableVehiclesFromFile(cars, buses);	//read available cars and buses from the same file. Function definition can be found in mainProgramLibrary.cpp

	readRentalVehiclesFromFile(rentalCars, rentalBuses);	//read rental cars and buses from the same file. Function definition can be found in mainProgramLibrary.cpp

	std::cout << "--------------------------------------------available cars---------------------------------------------" << std::endl << std::endl;

	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		std::cout << cars[i].carNumberPlateGetter() << "  ";
		std::cout << cars[i].carBuildYearGetter() << "  ";
		std::cout << cars[i].carFuelTypeGetter() << "  ";	//display available cars
		std::cout << cars[i].carTotalKmGetter() << "  ";
		std::cout << cars[i].carRentalPricePerDayGetter() << std::endl;
	}

	std::cout << std::endl << "Adding 1000 km's to all cars by using operator + function: " << std::endl << std::endl;
	for (unsigned int i = 0; i < cars.size(); ++i)
	{
		cars[i] + 1000;

		std::cout << cars[i].carNumberPlateGetter() << "  ";
		std::cout << cars[i].carBuildYearGetter() << "  ";
		std::cout << cars[i].carFuelTypeGetter() << "  ";	//demonstration of operator + function
		std::cout << cars[i].carTotalKmGetter() << "  ";
		std::cout << cars[i].carRentalPricePerDayGetter() << std::endl;
	}

	std::cout << std::endl << "--------------------------------------------available buses--------------------------------------------" << std::endl << std::endl;
																																	
	for (unsigned int i = 0; i < buses.size(); ++i)																						
	{																								
		std::cout << buses[i].carNumberPlateGetter() << "  ";
		std::cout << buses[i].carBuildYearGetter() << "  ";
		std::cout << buses[i].carFuelTypeGetter() << "  ";	//display available buses
		std::cout << buses[i].carTotalKmGetter() << "  ";
		std::cout << buses[i].carRentalPricePerDayGetter() << "  ";
		std::cout << buses[i].busCapacityGetter() << std::endl;
	}
	std::cout << std::endl << "-----------------------------------information about rental cars-----------------------------------" << std::endl << std::endl;
	for (unsigned int i = 0; i < rentalCars.size(); ++i)
	{
		std::cout << "Rental start date of "<<i+1<<". vehicle: "<< rentalCars[i].rentStartDateGetter() << "  ";
		std::cout << "Rental end date: " << rentalCars[i].rentEndDateGetter() << "  ";
		std::cout << "The length of rental for this vehicle is: "<< rentalCars[i].lengthOfRental() << std::endl;					//display start, end dates, length and price of the vehicle
		std::cout << "Rental price of that vehicle is: " << rentalCars[i].priceOfRent(rentalCars[i])<<std::endl<<std::endl;
	}
	std::cout << std::endl << "-----------------------------------information about rental buses-----------------------------------" << std::endl << std::endl;
	for (unsigned int i = 0; i < rentalBuses.size(); ++i)
	{
		std::cout << "Rental start date of " << i + 1 << ". vehicle: " << rentalBuses[i].rentStartDateGetter() << "  ";
		std::cout << "Rental end date: " << rentalBuses[i].rentEndDateGetter() << "  ";
		std::cout << "The length of rental for this vehicle is: " << rentalBuses[i].lengthOfRental() << std::endl;					//display start, end dates, length and price of the vehicle
		std::cout << "Rental price of that vehicle is: " << rentalBuses[i].priceOfRent(rentalCars[i]) << std::endl << std::endl;
	}

	
	std::cout <<std::endl<< "Income had by renting out the cars: " << amountOfIncome(rentalCars, rentalBuses) << std::endl<< std::endl;	//display total income

	sortRentals(rentalCars);	//call the function to list all the car rentals in increasing oreder of start dates
	
	std::cout << "List of all the car rentals in increasing order of start dates: "<<std::endl;
	
	for (auto& rentalVehicle : rentalCars)
	{
		std::cout << "Number Plate: " << rentalVehicle.getNumberPlate() << " | Rent Start Date: " << rentalVehicle.rentStartDateGetter() << std::endl;	// display all the car rentals in increasing oreder of start dates
	}
	
	std::cout<< std::endl;

	system("PAUSE");

	return 0;
}

