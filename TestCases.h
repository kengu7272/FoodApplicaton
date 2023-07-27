#ifndef TESTCASESH
#define TESTCASESH
//This is my test case for mealPlanAlgo.h and its source file. I.E Requirenment 2
#include "mealPlanAlgo.h"
#include "recipe.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::cin;
using std::vector;
using std::stof;

//Activates test cases
void activateTestCases();
//Test case for getTargetWeight
void testCase1();
//Test case for getTime
void testCase2();
//Test case for mealPlanAlgo
void testCase3();
//Test case that imitates a scenario for all the functions.
void scenarioTestCase();

void activateTestCases()
{
    testCase1();
    testCase2();
    testCase3();
    scenarioTestCase();
    return;
}

//Test case for getTargetWeight
//No test case for failed because its messes with userinput which would result in a infinite error message.
void testCase1()
{
    //simulated user input
    string sampleInput = "120";

    std::istringstream cinStream(sampleInput);
    std::streambuf* backup = std::cin.rdbuf();
    std::cin.rdbuf(cinStream.rdbuf());

    float newInput = getTargetWeight();
    cout << sampleInput << endl;

    //If statements decide if results passed or failed
    if (newInput == std::stof(sampleInput))
    {
        cout << "Test Case 1 Passed, both values were same as expected.\n\n";
    }
    else
    {
        cout << "Test Case 1 failed." << endl;
    }

    std::cin.rdbuf(backup);

    return;
}

//Test case for getTime
//No test case for failed because its messes with userinput which would result in a infinite error message.
void testCase2()
{
    //simulated user inputs
    string sampleInput = "90";

    std::istringstream cinStream(sampleInput);
    std::streambuf* backup = std::cin.rdbuf();
    std::cin.rdbuf(cinStream.rdbuf());

    float newInput = getTime();
    cout << sampleInput << endl;

    //if statements decide if results passed or failed
    if (newInput == std::stof(sampleInput))
    {
        cout << "Test Case 2 Passed, both values were same as expected.\n\n";
    }
    else
    {
        cout << "Test Case 2 failed." << endl;
    }

    std::cin.rdbuf(backup);

    return;
}

//Test case for mealPlanAlgo
//No test case for failed because it relies on the database being empty which will never be the case.
void testCase3()
{
    //Making a small recipe database
    vector<Recipe> recipeDB;
    Recipe temp;
    temp.setCalorie(100);
    recipeDB.push_back(temp);
    temp.setCalorie(1000);
    recipeDB.push_back(temp);
    temp.setCalorie(200);
    recipeDB.push_back(temp);
    temp.setCalorie(500);
    recipeDB.push_back(temp);
    temp.setCalorie(340);
    recipeDB.push_back(temp);
    temp.setCalorie(110);
    recipeDB.push_back(temp);
    temp.setCalorie(930);
    recipeDB.push_back(temp);
    temp.setCalorie(9000);
    recipeDB.push_back(temp);
    temp.setCalorie(123);
    recipeDB.push_back(temp);
    temp.setCalorie(3245);
    recipeDB.push_back(temp);
    temp.setCalorie(933);
    recipeDB.push_back(temp);
    temp.setCalorie(324);
    recipeDB.push_back(temp);

    //Executing the function
    vector<singleFoodPlan> planDB;
    planDB = mealPlanAlgo(recipeDB, 150, 1, 150);
    //Deciding if results passed or failed test case.
    if (planDB.empty() == false)
    {
        cout << "Test case 3 Passed, database of plans has atleast 1 plan inside.\nDisplaying individual calorie count"
            << " of food in the first plan in the database: ";
        for (auto iter = planDB.front().recipeVec.begin(); iter != planDB.front().recipeVec.end(); ++iter)
        {
            cout << iter->getCalorie() << ", ";
        }
        cout << "\n\n";
    }
    else
    {
        cout << "Test case 3 failed." << endl;
    }
}

//Test case that imitates a scenario for all the functions.
void scenarioTestCase()
{
    cout << "------Initating Scenario Test Case------\n\n";
    //Part 1 -----------------

    //simulated user input
    string sampleInput = "160";

    istringstream cinStream(sampleInput);
    std::streambuf* backup = std::cin.rdbuf();
    cin.rdbuf(cinStream.rdbuf());

    float newInput = getTargetWeight();
    cout << sampleInput << endl;

    //If statements decide if results passed or failed
    if (newInput == stof(sampleInput))
    {
        cout << "Scenario test case part 1 passed for target weight.\n\n";
    }
    else
    {
        cout << "Scenario test case part 1 failed." << endl;
    }

    //Part 2 ---------------

    //simulated user inputs
    string sampleInput2 = "2";

    istringstream cinStream2(sampleInput2);
    cin.rdbuf(cinStream2.rdbuf());

    float newInput2 = getTime();
    cout << sampleInput2 << endl;

    //if statements decide if results passed or failed
    if (newInput2 == stof(sampleInput2))
    {
        cout << "Scenario test case part 2 passed for getting time.\n\n";
    }
    else
    {
        cout << "Scenario test case part 2 failed." << endl;
    }

    //Part 3 -----------------------------

    //Making a small recipe database
    vector<Recipe> recipeDB;
    Recipe temp;
    temp.setCalorie(100);
    recipeDB.push_back(temp);
    temp.setCalorie(1000);
    recipeDB.push_back(temp);
    temp.setCalorie(200);
    recipeDB.push_back(temp);
    temp.setCalorie(500);
    recipeDB.push_back(temp);
    temp.setCalorie(340);
    recipeDB.push_back(temp);
    temp.setCalorie(110);
    recipeDB.push_back(temp);
    temp.setCalorie(930);
    recipeDB.push_back(temp);
    temp.setCalorie(9000);
    recipeDB.push_back(temp);
    temp.setCalorie(123);
    recipeDB.push_back(temp);
    temp.setCalorie(3245);
    recipeDB.push_back(temp);
    temp.setCalorie(933);
    recipeDB.push_back(temp);
    temp.setCalorie(500);
    recipeDB.push_back(temp);
    temp.setCalorie(600);
    recipeDB.push_back(temp);
    temp.setCalorie(200);
    recipeDB.push_back(temp);

    //Executing the function
    vector<singleFoodPlan> planDB;
    planDB = mealPlanAlgo(recipeDB, stof(sampleInput), stof(sampleInput2), stof(sampleInput));
    //Deciding if results passed or failed test case.
    if (planDB.empty() == false)
    {
        cout << "Scenario test case final part passed, database of plans has atleast 1 plan inside.\nDisplaying individual calorie count"
            << " of food in the first plan in the database: ";
        for (auto iter = planDB.front().recipeVec.begin(); iter != planDB.front().recipeVec.end(); ++iter)
        {
            cout << iter->getCalorie() << ", ";
        }
        cout << endl;
    }
    else
    {
        cout << "Scenario test case final part failed." << endl;
    }

    std::cin.rdbuf(backup);

    return;
}
#endif
