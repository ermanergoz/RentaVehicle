#pragma once
#include"car.h"
#include"bus.h"
#include"rental.h"
#include <vector>
#include <fstream>

void readAvailableVehiclesFromFile(std::vector<car> &cars, std::vector<bus> &buses);	//this function is to read available cars and buses from the same file
																						//vectors which contains cars and buses passed by referance

void readRentalVehiclesFromFile(std::vector<rental> &rentalCars, std::vector<rental> &rentalBuses);  	//this function is to read rental cars and buses from the same file
																										//vectors which contains rentals passed by referance

int amountOfIncome(std::vector<rental> rentalCars, std::vector<rental> rentalBuses);	//this function returns total income as integer. rental vector should be passed 
																						//so it can get price of the rent by passing object to priceOfRent function

std::vector<rental>& sortRentals(std::vector<rental>& rentalCars);						//to sort the rental car objects depending on the rent start dates