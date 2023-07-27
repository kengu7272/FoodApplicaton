// @search.h
// functions and code related towards searching food database


// contains 2 functions, a driver function for those and a callback function
// process involves taking user input and converting it into a suitable query
// and access the database via its api using the query which returns a JSON
// formatted string which is parsed and the information is displayed to the user
// WriteCallback is used by cURL to write fetched data
// getUserInput is used to get an input to be used as a query from the user
// searchQuery uses cURL and the inputted query to search the food database and display results
// searchProcess is the driver function to allow searching

#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <iostream>
#include <json/json.h>

/// <summary>
/// callback function used by cURL to write data to a variable
/// inputs are automatically entered by the CURL_OPT_WRITEFUNCTION
/// </summary>
/// <param name="contents">Buffer</param>
/// <param name="size">Size of the members/items</param>
/// <param name="nmemb">Number of members/items</param>
/// <param name="userp">File stream</param>
/// <returns>Returns block size</returns>
static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp);

/// <summary>
/// gets user input
/// </summary>
/// <returns>returns inputted string</returns>
std::string getUserInput();

/// <summary>
/// takes the user input from getUserInput and converts it into
/// a suitable query to send to database api, and it accesses the api
/// using an api key and inputting the search query and it displays
/// ten results to the user
/// </summary>
/// <param name="query">string to be used to search for food</param>
Json::Value searchQuery(std::string query);

/// <summary>
/// prints out contents from search query of food databse
/// </summary>
/// <param name="foods">should be value returned from searchQuery function</param>
/// <returns>false if empty and true if otherwise</returns>
bool printFoodResults(Json::Value foods);

/// <summary>
/// Driver function to complete the searching process, it calls
/// getUserInput to get a string and calls searchQuery to use
/// the string to get desired results
/// </summary>
void searchProcess();

/// <summary>
/// gives users two choice
/// one: enter search query
/// two: run search tests
/// </summary>
void searchOption();

// below here
// are testing
// functions

/// <summary>
/// tests that getting user input works as intended
/// </summary>
void testUserInput();

/// <summary>
/// tests input with special characters
/// </summary>
void testUserInput2();

/// <summary>
/// tests empty input
/// </summary>
void testUserInput3();

/// <summary>
/// tests extremely large input
/// </summary>
void testUserInput4();

/// <summary>
/// user input of just a space
/// </summary>
void testUserInput5();

/// <summary>
/// tests that the writeCallback function successfully writes to a variable
/// </summary>
void testWriteCallback();

/// <summary>
/// test to ensure that passing the search query into the food database works
/// will be using a simple food that for sure exists (apple) to search for
/// 
/// note: no way to test fail cases of cURL unless code is refactored a lot
/// </summary>
void testSearch();

/// <summary>
/// special characters test
/// </summary>
void testSearch2();

/// <summary>
/// empty input test
/// </summary>
void testSearch3();

/// <summary>
/// large value test
/// </summary>
void testSearch4();

/// <summary>
/// input of just a space test
/// </summary>
void testSearch5();

/// <summary>
/// test normal input
/// </summary>
void testPrint();

/// <summary>
/// test empty input
/// </summary>
void testPrint2();

/// <summary>
/// scenario of user looking up their breakfast
/// </summary>
void testScenarioMealLookup();

/// <summary>
/// driver to run all tests
/// </summary>
void runTests();

#endif // SEARCH_H