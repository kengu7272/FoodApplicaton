// @search.cpp
// definitions of functions declared in @search.h

#include "search.h"
#include <limits>
#include <sstream>
#include <assert.h>
#include <curl/curl.h>

#define CURL_STATICLIB

static size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string getUserInput()
{
	std::string input;
	std::cout << "Welcome to the search method!" << std::endl;
	std::cout << "Enter the search query: ";
	std::getline(std::cin, input);
	return input;
}

Json::Value searchQuery(std::string query)
{
	CURL* curl;
	CURLcode result;

	//string to write data to
	std::string read;

	// query will search the database for the user inputted string and returns 10 items
	query = "{\"query\": \"" + query + "\", \"pageSize\": 10}";

	curl = curl_easy_init();
	if (!curl)
	{
		std::cerr << "Error with cURL" << std::endl;
		return Json::objectValue;
	}

	struct curl_slist* header = nullptr;
	header = curl_slist_append(header, "Content-Type: application/json");

	// access to database api using api key
	curl_easy_setopt(curl, CURLOPT_URL,
		"https://api.nal.usda.gov/fdc/v1/foods/search?api_key=5sUh6DZiqjqdZ6meBbqLZfDn9vmEpzGzy96Bxlmt");
	// loads user inputted query into post fields
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, query.c_str());
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read);

	result = curl_easy_perform(curl);
	if (result != CURLE_OK)
	{
		std::cerr << "Error with cURL" << std::endl;
		return Json::objectValue;
	}

	curl_easy_cleanup(curl);

	// write function writes data to read string
	// json formatted data is stored as a string
	// below it will be parsed

	Json::Value root;
	Json::Reader reader;

	bool parsed = reader.parse(read, root);
	if (!parsed)
	{
		std::cerr << "String was not parsed" << std::endl;
	}

	// returns list of foods
	return root["foods"];
}

bool printFoodResults(Json::Value foods)
{
	//checks if empty
	if (foods.empty())
	{
		std::cout << "Empty food list" << std::endl;
		return false;
	}

	// this loops through foods list
	for (int i = 0; i < foods.size(); i++)
	{
		std::cout << "Search Result #" << i + 1 << std::endl;
		std::cout << "Food: " << foods[i]["description"] << std::endl;
		std::cout << "Category: " << foods[i]["foodCategory"] << std::endl;
		std::cout << "Serving Size: " << foods[i]["servingSize"];
		std::cout << " " << foods[i]["servingSizeUnit"] << std::endl;
		std::cout << "Ingredients: " << foods[i]["ingredients"] << std::endl;

		//this loops through foods nutrients list
		for (int j = 0; j < foods[i]["foodNutrients"].size(); j++)
		{
			std::cout << foods[i]["foodNutrients"][j]["nutrientName"] << ": " << foods[i]["foodNutrients"][j]["value"];
			std::cout << " " << foods[i]["foodNutrients"][j]["unitName"] << std::endl;
		}

		std::cout << std::endl;
	}

	return true;
}

void searchProcess()
{
	//clear buffer
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

	std::string input = getUserInput();
	printFoodResults(searchQuery(input));
}

void searchOption()
{
	std::string option = "0";

	do
	{
		std::cout << "Choose an option" << std::endl;
		std::cout << "1: Enter search query" << std::endl;
		std::cout << "2: Run searching tests" << std::endl;
		std::cout << "3: Back" << std::endl;

		std::cin >> option;
	} while (option != "1" && option != "2" && option != "3");

	switch (std::stoi(option))
	{
		case 1:
			searchProcess();
			break;
		case 2:
			runTests();
			break;
		case 3:
			break;
		default:
			std::cout << "Something unexpected happened" << std::endl;
			break;
	}
	
}

void testUserInput()
{
	//sample input of a common food
	std::string sampleInput = "caramel apple";

	std::istringstream cinStream(sampleInput);
	std::streambuf* backup = std::cin.rdbuf();

	std::cin.rdbuf(cinStream.rdbuf());

	std::string str = getUserInput();

	//checks to see if simulated input outputs the same
	assert(str == sampleInput);

	std::cout << "Test case passed, normal user input works as intended!" << std::endl;
	std::cin.rdbuf(backup);
}

void testUserInput2()
{
	//sample input of a common food
	std::string sampleInput = "$%^%'\"'~`";

	std::istringstream cinStream(sampleInput);
	std::streambuf* backup = std::cin.rdbuf();

	std::cin.rdbuf(cinStream.rdbuf());

	std::string str = getUserInput();

	//checks to see if simulated input outputs the same
	assert(str == sampleInput);

	std::cout << "Test case passed, special character user input works as intended!" << std::endl;
	std::cin.rdbuf(backup);
}

void testUserInput3()
{
	//sample input of a common food
	std::string sampleInput = "";

	std::istringstream cinStream(sampleInput);
	std::streambuf* backup = std::cin.rdbuf();

	std::cin.rdbuf(cinStream.rdbuf());

	std::string str = getUserInput();

	//checks to see if simulated input outputs the same
	assert(str == sampleInput);

	std::cout << "Test case passed, empty user input works as intended!" << std::endl;
	std::cin.rdbuf(backup);
}

void testUserInput4()
{
	//sample input of empty to add chars to
	std::string sampleInput = "";

	for (int i = 0; i < 10000; i++)
	{
		//sample char to be added
		sampleInput += "a";
	}

	std::istringstream cinStream(sampleInput);
	std::streambuf* backup = std::cin.rdbuf();

	std::cin.rdbuf(cinStream.rdbuf());

	std::string str = getUserInput();

	//checks to see if simulated input outputs the same
	assert(str == sampleInput);

	std::cout << "Test case passed, large user input works as intended!" << std::endl;
	std::cin.rdbuf(backup);
}

void testUserInput5()
{
	//sample input of just a space
	std::string sampleInput = " ";

	std::istringstream cinStream(sampleInput);
	std::streambuf* backup = std::cin.rdbuf();

	std::cin.rdbuf(cinStream.rdbuf());

	std::string str = getUserInput();

	//checks to see if simulated input outputs the same
	assert(str == sampleInput);

	std::cout << "Test case passed, space user input works as intended!" << std::endl;
	std::cin.rdbuf(backup);
}

void testWriteCallback()
{
	CURL* curl;
	CURLcode result;
	std::string read = "";

	//well known site to be used for testing
	char sampleSite[] = "https://google.com";

	curl = curl_easy_init();

	//checks if initializing curl works for a regular website
	assert(curl);

	curl_easy_setopt(curl, CURLOPT_URL, sampleSite);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read);

	result = curl_easy_perform(curl);

	//checks if executing curl works
	assert(result == CURLE_OK);

	curl_easy_cleanup(curl);

	//checks to see if anything was written to read variable
	assert(read != "");

	std::cout << "Test case passed, write function successfully writes to variable!" << std::endl;
}

void testSearch()
{
	std::string testQuery = "apple";
	Json::Value foodsList = searchQuery(testQuery);

	// code returns Json::objectValue if it runs into an error
	// it checks if an error is made, otherwise it returns results, empty or not
	assert(foodsList != Json::objectValue);
	std::cout << "Test case passed, search results were made!" << std::endl;
}

void testSearch2()
{
	std::string testQuery = "@#$%#$^'\"";
	Json::Value foodsList = searchQuery(testQuery);

	// code returns Json::objectValue if it runs into an error
	// it checks if an error is made, otherwise it returns results, empty or not
	assert(foodsList != Json::objectValue);
	std::cout << "Test case passed, search results were made!" << std::endl;
}

void testSearch3()
{
	std::string testQuery = "";
	Json::Value foodsList = searchQuery(testQuery);

	// code returns Json::objectValue if it runs into an error
	// it checks if an error is made, otherwise it returns results, empty or not
	assert(foodsList != Json::objectValue);
	std::cout << "Test case passed, search results were made!" << std::endl;
}

void testSearch4()
{
	std::string testQuery = "";

	for (int i = 0; i < 10000; i++)
	{
		testQuery += "a";
	}

	Json::Value foodsList = searchQuery(testQuery);

	// code returns Json::objectValue if it runs into an error
	// it checks if an error is made, otherwise it returns results, empty or not
	assert(foodsList != Json::objectValue);
	std::cout << "Test case passed, search results were made!" << std::endl;
}

void testSearch5()
{
	std::string testQuery = " ";
	Json::Value foodsList = searchQuery(testQuery);

	// code returns Json::objectValue if it runs into an error
	// it checks if an error is made, otherwise it returns results, empty or not
	assert(foodsList != Json::objectValue);
	std::cout << "Test case passed, search results were made!" << std::endl;
}

void testPrint()
{
	Json::Value foods = searchQuery("apple");
	assert(printFoodResults(foods));
}

void testPrint2()
{
	Json::Value foods = Json::arrayValue;
	assert(!printFoodResults(foods));
}

void testScenarioMealLookup()
{
	// scenario here is that a user has a simple meal
	// say its breakfast: contains eggs, waffles, and apples
	// user wants to get details of each component to learn about its macros

	std::string egg = "egg";
	std::string waffle = "waffle";
	std::string apple = "apple";

	// first search for egg
	Json::Value eggResults = searchQuery(egg);
	// check if error is made or if a simple common food returns empty for some reason
	assert(eggResults != Json::objectValue && !(eggResults.empty()));

	// second search for waffle
	Json::Value waffleResults = searchQuery(waffle);
	assert(waffleResults != Json::objectValue && !(waffleResults.empty()));

	// lastly search for apple
	Json::Value appleResults = searchQuery(apple);
	assert(appleResults != Json::objectValue && !(appleResults.empty()));

	std::cout << "Scenario test passed! User successfully searched for their entire meal" << std::endl;
}

/// <summary>
/// runs all tests
/// </summary>
void runTests()
{
	testUserInput();
	testUserInput2();
	testUserInput3();
	testUserInput4();
	testUserInput5();

	testWriteCallback();

	testSearch();
	testSearch2();
	testSearch3();
	testSearch4();
	testSearch5();

	testPrint();
	testPrint2();

	testScenarioMealLookup();

	std::cout << std::endl << "Congratulations, all test cases passed! (100% pass rate)" << std::endl;
}