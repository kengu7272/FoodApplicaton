//IMPORTANT NOTE: This header file is made by Avery I think not me. I included this because it is needed for my code
//to run, compile, and have my test cases work because my code uses classes and methods from here. 
//I only modifyed it slightly to work with my code a little bit better so the original recipe.h 
//in the "sample code" folder will not work.
//So do NOTTTTTTTTTT peer review or grade this file because again, it is not made by me.
//Another note: I put some test cases here in this file.
#ifndef RECIPEH
#define RECIPEH
/*
    Sample code for user to select a meal from their meal plan
    and get a recipe with directions for making the meal
*/

#include <iostream>
#include <string>
#include <vector>

//#include "search.h"
//#include "MealPlan.h"
using std::vector;
using std::string;
using std::cout;

void testCasesRecipe();

class Recipe
{
private:
    std::string name;
    std::string* instructions;
    int instructionsNum;
    float calorie;

public:
    //should always be initialized with a food choice
    Recipe(std::string foodName)
    {
        name = foodName;

        /*
        TODO create search object using food name
        */
        vector<int> searchResults = { 1, 1, 1, 1, 1, 1, 1, 1 }; //Temp added to his code cause this vector was not defined before.
        instructionsNum = searchResults.size();
        instructions = new std::string[instructionsNum];

        for (auto i = 0; i < instructionsNum; ++i)
        {
            instructions[i] = searchResults[i];
        }
    }
    Recipe()
    {

    }

    ~Recipe()
    {
        delete[] instructions;
        instructions = NULL;
    }

    std::string* getRecipe();
    int getSize();

    std::string operator[] (int index)
    {
        if (index < instructionsNum)
            return instructions[index];
        else
            std::cerr << "Invalid Index!" << '\n';
    }
    float getCalorie()
    {
        return calorie;
    }
    void setCalorie(float a)
    {
        calorie = a;
    }
    void setName(string a)
    {
        name = a;
    }
    string getName()
    {
        return name;
    }
};

/*
void testCasesRecipe()
{
    Recipe pasta;
    pasta.setName("pasta");
    pasta.setCalorie(5);
    
    if (pasta.getName() == "pasta")
    {
        cout << "Test case 1 passed. Recipe name is expected value\n";
    }
    else
    {
        cout << "Test case 1 failed, name should be the same\n";
    }
    
    if (pasta.getCalorie() == 5)
    {
        cout << "Test case 2 passed. Recipe calorie is expected value\n";
    }
    else
    {
        cout << "Test case 2 failed, calories should be same amount\n";
    }
    
    if (pasta.getName() != "NotPasta")
    {
        cout << "Test case 3 passed. Recipe name did not match which is expected.\n";
    }
    else
    {
        cout << "Test case 3 failed, strings should be different values\n";
    }
}
*/
#endif
