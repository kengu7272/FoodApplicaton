//  Most Recent Change : 11/13/2022 (by Ja'Den)
//	
//	@Structure for the remove and replace functions for SWE_Project.
//
//	This program contains the remove and replace functions for the SWE Project,
//	The remove function iterates through the list of list of foods and remove it.
//	The replace function will call add the selected food to a list of restricted foods, call
//	the remove function, and will find a substitute for the removed item.
//	(This could be a new functionality or calling the function to make a meal plan with the new list.)

#include <iostream>
#include <string>
#include <map>
#include "remove.h"

// Function to remove food items
//
// @foodList contains all foods contained in the database, 
// @foodName is the target
//
// returns updated foodList
std::map<std::string, foods> foods::remove_Food(std::map<std::string, foods> foodList, std::string foodName)
{
	foodList.erase(foodName);
	return foodList;
}

// Function to replace food items
//
// @foodList contains all foods in the database
// @foodName is the target
// @bannedList contains all foods removed from database
void foods::replace_Food(std::map<std::string, foods>& foodList, std::string foodName, std::map<std::string, foods>& bannedList)
{
	std::map<std::string, foods>::const_iterator iter = foodList.begin();
	std::map<std::string, foods>::const_iterator iter_banned = bannedList.begin();
	
	for (; iter != foodList.end(); iter++)
	{
		if (foodName == iter->first)
		{
			std::cout << foodName << " will be removed and banned.\n\n";
			bannedList[foodName] = foodName; //Ban food
			foodList = remove_Food(foodList, foodName); //Remove food
			return;
		}
	}

	std::cout << foodName << " is not currently within the list.\n\n"; //Unsuccessful search
	return;
}

//Function to test remove and replace functions
void foods::testCase()
{
	//Test Array of Objects
	foods item[3] = { {"Peanut Butter"}, { "Milk" }, { "Salt" } };

	//Maps to store objects
	std::map <std::string, foods> foodList;
	std::map<std::string, foods> bannedList;

	//Test cases with temporary objects in item[].
	//utilizing only the names of foods.
	foodList["Peanut Butter"] = item[0];
	foodList["Milk"] = item[1];
	foodList["Salt"] = item[2];

	std::string foodName[2] = { "Peanut Butter", "Eggs" };

	//Shows the current list of foods
	std::cout << "List of Foods: ";
	for (int i = 0; i < foodList.size(); i++)
	{
		std::cout << item[i] << ",  ";
	}
	std::cout << std::endl << std::endl;

	//Successful case
	replace_Food(foodList, foodName[0], bannedList);
	
	//Unsuccessful case
	replace_Food(foodList, foodName[1], bannedList);


	//Shows that the selected item has been moved into the list of banned items.
	std::cout << "Banned Foods: ";
	for (std::map<std::string, foods>::const_iterator iter = bannedList.begin(); iter != bannedList.end(); iter++)
	{
		std::cout << bannedList[foodName[0]] << " is in the banned list.\n\n";
	}

	//Shows that food is banned
	std::cout << "Peanut Butter is no longer in the main food list and has value -> " << foodList[foodName[0]] << ".\n\n";
	
	//Shows that food is not banned.
	std::cout << "Milk has value -> " << bannedList["Milk"] << ". and has not been banned.\n";
}

//Drives the main function
void removeItem()
{	
	//The Test Case Function Uses a Preset of minimilized food objects to 
	//test the operations of the remove and replace function.
	foods testObj;
	testObj.testCase();
	return;
}