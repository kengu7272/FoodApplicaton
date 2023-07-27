#ifndef MEALPLANALGOH
#define MEALPLANALGOH

#include "recipe.h"
#include <vector>

//This is a class for food plan that holds a vector of recipes.
class singleFoodPlan
{
public:
    vector<Recipe> recipeVec;
};

//pre- no parameters
//post- returns user target weight
float getTargetWeight();

//pre - no parameters
//post - returns user targert weight
float getTime();

//pre - vector of Reciple class, and 3 floats
//post - returns an vector of recipes
vector<singleFoodPlan> mealPlanAlgo(vector<Recipe>, float, float, float);

#endif
