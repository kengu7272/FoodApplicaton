#include <iostream>
#include "recipe.h"
#include <string>

using std::string;
using std::cout;

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
