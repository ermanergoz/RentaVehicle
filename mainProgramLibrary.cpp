#include "stdafx.h"
#include "mainProgramLibrary.h"
#include "car.h"
#include "bus.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <exception>	//to throw standard exceptions
#include "rental.h"
#include <algorithm>    //to use std::sort
#include <sstream>



void readAvailableVehiclesFromFile(std::vector<car> &cars, std::vector<bus> &buses)	//to read all the available vehicles from the same file
{
	std::ifstream input;

	input.open("vehicleInput.txt");	//open the input file

	if (input.is_open())
	{

		std::string lineTemp;			//tempezrary string

		try
		{

			while (!input.eof())
			{
				std::getline(input, lineTemp);	//read the whole line and save it to the temperary string

				std::stringstream lineInput(lineTemp);
				int semicolonCount = std::count(lineTemp.begin(), lineTemp.end(), ';');	//count the semicolons to decide if the vehicle is car or a bus

				if (4 == semicolonCount) //it is a car
				{
					std::string tempNumberPlate;	//temperary string to store number plate
					std::string tempFuelType;		//temperary string to store fuel type

					std::getline(lineInput, tempNumberPlate, ';');

					int tempBuildYear;		//temp variable to store build year
					lineInput >> tempBuildYear;	//read it
					lineInput.ignore(5, ';');	//till the semicolon

					std::getline(lineInput, tempFuelType, ';');	//read the fuel type

					float tempTotalKm;
					lineInput >> tempTotalKm;
					lineInput.ignore(7, ';');
					//and so on
					int tempRentalPricePerDay;
					lineInput >> tempRentalPricePerDay;
					lineInput.ignore(6, '\n');

					car carToRead(tempNumberPlate, tempBuildYear, tempFuelType, tempTotalKm, tempRentalPricePerDay);	//create a car object by calling the constructor
																														//with the parameters we read from the file
					cars.push_back(carToRead);	//store the car object to the vector
				}
				else if (5 == semicolonCount) //it is a bus
				{
					std::string tempNumberPlate;
					std::string tempFuelType;
					std::string tempString;

					std::getline(lineInput, tempNumberPlate, ';');
					std::getline(lineInput, tempString, ';');
					int tempBuildYear = std::atoi(tempString.c_str());			//read data and store to temp variables
					std::getline(lineInput, tempFuelType, ';');
					std::getline(lineInput, tempString, ';');
					float tempTotalKm = std::atof(tempString.c_str());
					std::getline(lineInput, tempString, ';');
					int tempRentalPricePerDay = std::atoi(tempString.c_str());
					std::getline(lineInput, tempString);
					int tempCapacity = std::atoi(tempString.c_str());

					bus busToRead(tempNumberPlate, tempBuildYear, tempFuelType, tempTotalKm, tempRentalPricePerDay, tempCapacity);	//call bus constructor to create bus object

					buses.push_back(busToRead);	//store the object to the vector
				}
				else
				{
					throw std::invalid_argument("Some of the arguments are wrong in the file!");
				}

				lineTemp.clear();	//clear the string so it can be reused for the next line with better memory management
			}
			input.close();		//close the input file since we dont need it anymore
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Unable to open the file!" << std::endl;
}

void readRentalVehiclesFromFile(std::vector<rental> &rentalCars, std::vector<rental> &rentalBuses)
{
	std::ifstream input;

	input.open("rentalInput.txt");	//open the input file

	if (input.is_open())
	{

		std::string lineTemp;			//temperary string

		try
		{

			while (!input.eof())
			{
				std::getline(input, lineTemp, '\n');	//read the whole line and save it to the temperary string

				std::stringstream lineInput(lineTemp);
				int semicolonCount = std::count(lineTemp.begin(), lineTemp.end(), ';');


				if (6 == semicolonCount)	//everything is exactly same as previous function except we have 2 more parameters. (start and end dates)
				{
					std::string tempNumberPlate;
					std::string tempFuelType;
					std::string tempString;

					std::getline(lineInput, tempString, ';');
					int tempStartDate = std::atoi(tempString.c_str());
					std::getline(lineInput, tempString, ';');
					int tempEndDate = std::atoi(tempString.c_str());

					std::getline(lineInput, tempNumberPlate, ';');
					std::getline(lineInput, tempString, ';');
					int tempBuildYear = std::atoi(tempString.c_str());
					std::getline(lineInput, tempFuelType, ';');
					std::getline(lineInput, tempString, ';');
					float tempTotalKm = std::atof(tempString.c_str());
					std::getline(lineInput, tempString);
					int tempRentalPricePerDay = std::atoi(tempString.c_str());
					std::getline(lineInput, tempString);

					rental rentalToRead(tempStartDate, tempEndDate, tempNumberPlate, tempBuildYear, tempFuelType, tempTotalKm, tempRentalPricePerDay);

					rentalCars.push_back(rentalToRead);
				}

				else if (7 == semicolonCount)
				{
					std::string tempNumberPlate;
					std::string tempFuelType;
					std::string tempString;

					std::getline(lineInput, tempString, ';');
					int tempStartDate = std::atoi(tempString.c_str());
					std::getline(lineInput, tempString, ';');
					int tempEndDate = std::atoi(tempString.c_str());

					std::getline(lineInput, tempNumberPlate, ';');
					std::getline(lineInput, tempString, ';');
					int tempBuildYear = std::atoi(tempString.c_str());
					std::getline(lineInput, tempFuelType, ';');
					std::getline(lineInput, tempString, ';');
					float tempTotalKm = std::atof(tempString.c_str());
					std::getline(lineInput, tempString, ';');
					int tempRentalPricePerDay = std::atoi(tempString.c_str());
					std::getline(lineInput, tempString);
					int tempCapacity = std::atoi(tempString.c_str());

					//here, we have only car constructor in rental class. So i have to cast bus to car to rent a bus. I used parent class pointer and passed it to the constructor.				
					bus* rentalBusToRead = new bus(tempNumberPlate, tempBuildYear, tempFuelType, tempTotalKm, tempRentalPricePerDay, tempCapacity);
					car* busAsCarPtr = dynamic_cast<car*>(rentalBusToRead);

					rental rentalToRead(tempStartDate, tempEndDate, busAsCarPtr);	//i used 3 parameter constructor in rental class for it.

					rentalBuses.push_back(rentalToRead);	//store the created object to the vector
				}
				else
				{
					throw std::invalid_argument("Some of the arguments are wrong in the file!");
				}


			}
			input.close();
		}

		catch (std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Unable to open the file!" << std::endl;
	}
	


int amountOfIncome(std::vector<rental> rentalCars, std::vector<rental> rentalBuses)	//calculate total income
{
	int totalIncome=0;	

	for (auto& car : rentalCars)	//iterate through rentalCar vector
	{
		totalIncome=car.priceOfRent(car)+ totalIncome;	//I used priceOfRent function in the rental class for it.
	}
	
	for (auto& bus : rentalBuses)	//same for buses
	{
		totalIncome = bus.priceOfRent(bus) + totalIncome;	
	}
	
	return totalIncome;	//return the result
}


bool startDateCompare(rental& r1, rental& r2)	// comparison function for start date sorting
{
	return r1.rentStartDateGetter() < r2.rentStartDateGetter();
}

std::vector<rental>& sortRentals(std::vector<rental>& rentalCars)	//to sort the objects depending on the rental start dates
{
	std::sort(rentalCars.begin(), rentalCars.end(), startDateCompare);	//to sort the objects

	return rentalCars;	//and return it
}