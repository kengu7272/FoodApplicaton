// @waterIntake.cpp
// definitions of functions declared in @waterIntake.h

#include "waterIntake.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <stdio.h>

void checkDate()
{
	std::ifstream file;
	file.open("waterIntake.txt");

	std::string currentDate;

	std::time_t t = std::time(0);
	char buffer[30];
	ctime_s(buffer, sizeof(buffer), &t);
	currentDate = buffer;
	currentDate = currentDate.substr(0, 3);


	std::string date; 
	file >> date;

	float water;	
	file >> water;

	if (currentDate != date)
	{
		water = 0;
		currentDate;

		file.close();

		remove("waterIntake.txt");

		std::ofstream out("waterIntake.txt");
		out << currentDate + "\n";
		out << water;

		out.close();

		return;
	}

	file.close();
	return;
}

void addWater()
{
	float ounces;
	// input validation not needed, if something other than a number is entered
	// it will simply just not add to the file
	std::cout << "How much water in ounces (must be a number!!): " << std::endl;
	std::cin >> ounces;

	std::string day;
	float water;

	std::ifstream file;
	file.open("waterIntake.txt");

	file >> day;
	file >> water;

	water += ounces;

	file.close();

	remove("waterIntake.txt");

	std::ofstream out("waterIntake.txt");
	out << day + "\n";
	out << water;

	out.close();
}

void displayWater()
{
	checkDate();

	std::ifstream file;
	file.open("waterIntake.txt");

	std::string water;
	file >> water;
	file >> water;

	std::cout << "Current water intake: " << water << "oz" << std::endl;
}