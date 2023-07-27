/*
    Sample code for user to select a meal from their meal plan
    and get a recipe with directions for making the meal
*/

#ifndef RECIPESEARCH_H
#define RECIPESEARCH_H

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>
#include <assert.h>

/*
Summary: Gets and validates user input
Pre: None
Post: Returns the validated user input
*/
std::string getInput();

/*
Summary: Takes a food name string variable and searches the database for a matching food and grabs the recipe instructions as an unformatted string
Pre: A string of the food that should be searched for
Post: Returns a string containing the unformatted recipe
*/
std::string findRecipe(std::string foodName);

/*
Summary: Takes the unformatted recipe that is passed and returns a vector containing the seperate steps
Pre: A string of the unformatted recipe with ; as the terminating character of the steps
Post: Returns a vector of strings each of which is a step in the recipe
*/
std::vector<std::string> processRecipe(std::string queryResponse);

/*
Summary: Displays the passed vector in parts as a recipe
Pre: A vector of strings each of which is a step in a recipe
Post: Displays the recipe
*/
void displayRecipe(std::vector<std::string> recipe);

/*
Summary: Checks if the function that takes user input is working correctly
Pre: None 
Post: Checks if the getInput function is working correctly
*/
void testInput();

/*
Summary:Checks if the function that searches for the recipe in the database is working correctly
Pre: None
Post:Checks if the findRecipe function is working correctly
*/
void testFindRecipe();

/*
Summary: Checks if the function that processes the recipe into a vector is working correctly
Pre: None
Post: Checks if the processRecipe function is working correctly
*/
void testProcessRecipe();

/*
Summary: Checks if all the functions in the recipe search file are working
Pre: None
Post: Runs all test functions
*/
void recipeTest();

#endif
