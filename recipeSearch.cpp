/*
    Sample code for user to select a meal from their meal plan
    and get a recipe with directions for making the meal
*/

#include "recipeSearch.h"

/*
Summary: Gets and validates user input
Pre: None
Post: Returns the validated user input
*/
std::string getInput()
{
    //String to hold user input
    std::string input;

    //Bool for loop to check if input passed validation
    bool inputCheck = false;

    do
    {
        std::cout << "Please choose a meal from your Meal Plan to view the recipe for: " << std::endl;

        //take input from user as a whole line as food can have multiple words
        std::getline(std::cin, input);

        if (std::cin.fail())
        {
            //If the input failed clear the fail and the in stream
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid Input!" << '\n';
            inputCheck = false;
        }
        else
        {
            //If the input passed set the loop bool to true
            inputCheck = true;
        }

    } while (!inputCheck);

    //Return the user input string
    return input;
}

/*
Summary: Takes a food name string variable and searches the database for a matching food and grabs the recipe instructions as an unformatted string
Pre: A string of the food that should be searched for
Post: Returns a string containing the unformatted recipe 
*/
std::string findRecipe(std::string foodName)
{
    //This function would normally call the search module
    //using the foodName passed and return an unformatted
    //version of the recipe but for the sake of the tests
    //it will just return a sample recipe

    //String to hold the unformatted recipe
    std::string queryResponse;
    if (foodName == "Broccoli and Bacon Salad")
    {
        //preset sample as a mock component as the searching is done in a different module
        queryResponse = "Place bacon in a large, deep skillet. Cook over medium-high heat until crisp and evenly browned, 8-10 minutes. "
            "Transfer to a paper towel-lined plate and crumble when cool enough to handle.;Combine bacon, broccoli, cheese, and onion in a large bowl.;"
            "Whisk mayonnaise, red wine vinegar, sugar, pepper, salt, and lemon juice together in a small bowl;Pour over salad and toss to combine. "
            "Cover and refrigerate until ready to serve.";
    }
    else
    {
        std::cout << "No recipe was found." << std::endl;
    }

    //Return the response whether that is the recipe or an empty string
    return queryResponse;
}

/*
Summary: Takes the unformatted recipe that is passed and returns a vector containing the seperate steps
Pre: A string of the unformatted recipe with ; as the terminating character of the steps
Post: Returns a vector of strings each of which is a step in the recipe
*/
std::vector<std::string> processRecipe(std::string queryResponse)
{
    //Vector of strings to hold the recipe
    std::vector<std::string> recipe;

    //Int to hold the index of the start of each direction
    int start = 0;

    //Loop through each character of the string to search for ; marking the end of a step
    for (auto i = 0; i < queryResponse.length(); ++i)
    {
        if (queryResponse[i] == ';')
        {
            //If the ; is found create a substring from the start index 
            //to the spot before the ;
            recipe.push_back(queryResponse.substr(start, (i - start)));
            start = i + 1;
        }
        else if (i == queryResponse.length() - 1)
        {
            //If the current index is the last character add it to the vector as there is no closing ;
            recipe.push_back(queryResponse.substr(start));
        }
    }
    //Return the vector of recipe steps
    return recipe;
}


/*
Summary: Displays the passed vector in parts as a recipe
Pre: A vector of strings each of which is a step in a recipe
Post: Displays the recipe
*/
void displayRecipe(std::vector<std::string> recipe)
{
    if (recipe.empty())
    {
        //If the vector is empty display an error and nothing else
        std::cout << "There are no recipe instructions." << std::endl;
    }
    else
    {
        for (auto i = 0; i < recipe.size(); ++i)
        {
            //For each step in the recipe display the step number and the direction itself
            std::cout << "Step " << i + 1 << ": " << recipe[i] << std::endl;
        }
    }
}

//Constant string of a sample recipe used for testing
const std::string sampleRecipe = "Place bacon in a large, deep skillet. Cook over medium-high heat until crisp and evenly browned, 8-10 minutes. "
	"Transfer to a paper towel-lined plate and crumble when cool enough to handle.;Combine bacon, broccoli, cheese, and onion in a large bowl.;"
	"Whisk mayonnaise, red wine vinegar, sugar, pepper, salt, and lemon juice together in a small bowl;Pour over salad and toss to combine. "
	"Cover and refrigerate until ready to serve.";

/*
Summary: Checks if the function that takes user input is working correctly
Pre: None 
Post: Checks if the getInput function is working correctly
*/
void testInput()
{
	//sample input of a common food
	std::string sampleInput = "Broccoli and Bacon Salad";

	std::istringstream cinStream(sampleInput);
    std::streambuf* backup = std::cin.rdbuf();

	std::cin.rdbuf(cinStream.rdbuf());

	std::string str = getInput();

	//checks to see if simulated input outputs the same
	assert(str == sampleInput);

	std::cout << "User input test case passed!" << std::endl;
    std::cin.rdbuf(backup);
}

/*
Summary:Checks if the function that searches for the recipe in the database is working correctly
Pre: None
Post:Checks if the findRecipe function is working correctly
*/
void testFindRecipe()
{
	std::string testResponse = sampleRecipe;

	std::string response = findRecipe("Broccoli and Bacon Salad");

	// code returns Json::objectValue if it runs into an error
	// it checks if an error is made, otherwise it returns results, empty or not
	assert(testResponse == response);
	std::cout << "Test case passed, search results were made!" << std::endl;
}

/*
Summary: Checks if the function that processes the recipe into a vector is working correctly
Pre: None
Post: Checks if the processRecipe function is working correctly
*/
void testProcessRecipe()
{
	std::vector<std::string> testRecipe = { "Place bacon in a large, deep skillet. Cook over medium-high heat until crisp and evenly browned, 8-10 minutes. "
	"Transfer to a paper towel-lined plate and crumble when cool enough to handle.", "Combine bacon, broccoli, cheese, and onion in a large bowl.", "Whisk mayonnaise, "
	"red wine vinegar, sugar, pepper, salt, and lemon juice together in a small bowl", "Pour over salad and toss to combine. Cover and refrigerate until ready to serve." };

	std::vector<std::string> recipe = processRecipe(sampleRecipe);

	bool recipeCheck = true;

	for (auto i = 0; i < testRecipe.size(); ++i)
	{
		if (testRecipe[i] != recipe[i])
		{
			std::cout << testRecipe[i] << std::endl;
			std::cout << recipe[i] << std::endl;
			recipeCheck = false;
		}
	}

	assert(recipeCheck);
	std::cout << "Scenario test passed! User successfully searched for their entire meal" << std::endl;
}

/*
Summary: Checks if all the functions in the recipe search file are working
Pre: None
Post: Runs all test functions
*/
void recipeTest()
{
    testInput();
	testFindRecipe();
	testProcessRecipe();

	std::cout << std::endl << "Congratulations, all test cases passed!" << std::endl;
}
