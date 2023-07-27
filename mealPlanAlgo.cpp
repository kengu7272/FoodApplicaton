//This source file and the corresponding header file
//is for making a plan that maintains the user's weight. I.E Requirenment 2
#include "mealPlanAlgo.h"
#include "recipe.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

//pre- no parameters
//post- returns user target weight
float getTargetWeight()
{
    /*
    These store user input, the reason why I have to have a stringand float
    is becasue that was the only way I could do the test cases. Bascally the program
    only allows me to pass strings to cin and not a float so I have to store it in string
    then convert it to float. 
    */
    float targetWeight = 0;
    string stringTargetWeight;

    cout << "Please enter your target weight: ";
    bool loopFlag1 = true;

    //data validation, keeps asking for user input if data validation fails
    do
    {
        cin >> stringTargetWeight;
        targetWeight = std::stof(stringTargetWeight);

        if ((stringTargetWeight.find_first_not_of("0123456789") == string::npos) == false)
        {
            cout << "Incorrect Input, please enter in a number: " << endl;
        }
        else
        {
            loopFlag1 = false;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (loopFlag1);
    return targetWeight;
}

//pre - no parameters
//post - returns user targert weight
float getTime()
{
    /*
    These store user input, the reason why I have to have a stringand float
    is becasue that was the only way I could do the test cases. Bascally the program
    only allows me to pass strings to cin and not a float so I have to store it in string
    then convert it to float.
    */
    float timeDays = 0;
    string stringTimeDays;

    cout << "Please enter in the time you want to take in days: ";
    bool loopFlag1 = true;

    //data validation, keeps asking for user input if data validation fails
    do
    {
        cin >> timeDays;
        if ((stringTimeDays.find_first_not_of("0123456789") == string::npos) == false)
        {
            cout << "Incorrect Input, please enter in a number: " << endl;
        }
        else
        {
            loopFlag1 = false;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (loopFlag1);
    return timeDays;
}

//Note that weight is stored in a class made by another team member so there is no getWeight function
//only a getTargetWeight.
//pre - vector of Reciple class, and 3 floats
//post - returns an vector of recipes
vector<singleFoodPlan> mealPlanAlgo(vector<Recipe> recipeDB, float weight, float timeDays, float targetWeight)
{
    //creates the foodplanDB to be returned.
    vector<singleFoodPlan> foodPlanDB = {};

    //Calorie counter for the loops
    float totalCalorie = 0;

    //This is the offset for the total calories cause getting an exact calorie count in a plan is almost impossible
    float calorieOffset = 300;

    /*
    Converts weight in pounds to calorie needed to maintain.
    Originally there should be an if statement deciding whether we're
    maintaining weight, adding weight or reducing weight and there
    respect operations, however since in this prototype we're only
    maintaining weight, we don't need an if statement. We can
    just go straight to the maintaining weight operation.
    */
    float calorieGoal = weight * 15 * timeDays;

    //creates the conidition for the while loop to execute
    bool allPossibleFoodPlan = true;

    /*
    This is a singleFoodPlan class that will hold a food plan that will be inserted to foodPlanDB.
    For a full implementation of the project this is needed but however for this minimal prototype,
    it is not required as I can just straight insert recipes into a vector to be returned. But I will
    still include it as middle man just in case if we ever decide to go for a full implementation of
    this project.
    */
    singleFoodPlan temp;

    //while loop executes until a plan is made.
    while (allPossibleFoodPlan)
    {
        //This for loop iterates through the recipe database
        for (auto iter = recipeDB.begin(); iter != recipeDB.end(); ++iter)
        {
            //If statement decided if there is still enough room for more food to be added into plan.
            if (totalCalorie < ((calorieGoal + calorieOffset)))
            {
                if ((iter->getCalorie() + totalCalorie) < (calorieGoal + calorieOffset))
                {
                    temp.recipeVec.push_back(*iter);
                    totalCalorie += iter->getCalorie();
                }
            }
        }
        /*
        In a full implementation of this project the outer while loop is needed to get all plans possible. But in a minimal
        prototype it is technically not needed as I will only focus on getting one plan anyway. But I will still include it
        so if we ever decide to do a full implementation, it will be easier to make it because all the foundation is layed down
        for it. So that is why there is no condition for allPossibleFoodPlan to turn false.
        */
        allPossibleFoodPlan = false;
        foodPlanDB.push_back(temp);
    }
    return foodPlanDB;
}