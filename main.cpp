/* Main driver for the software */

#include <iostream>

#include "Profile.hpp"
#include "utility.hpp"
#include "search.h"
#include "recipeSearch.h"
#include "remove.h"
#include "TestCases.h"
#include "mealPlanAlgo.h"
#include "waterIntake.h"

#define QUIT_NUM 7
#define MIN_CHOICE 1
#define MAX_CHOICE 7

void usage()
{
    std::cout << "Please enter a number corresponding to a module:\n";
    std::cout << "1: Recipes\n";
    std::cout << "2: Searching\n";
    std::cout << "3: Meal Plan\n";
    std::cout << "4: Profile\n";
    std::cout << "5: Remove\n";
    std::cout << "6: Add Water\n";
    std::cout << "7: Quit\n";
    displayWater();
}

int main(int argc, char *argv[])
{
    int choice = 0;

    while (choice != QUIT_NUM)
    {
        do
        {
            usage(); 
            std::cin >> choice;
        } while (!intValidation(choice, MIN_CHOICE, MAX_CHOICE));
        
        std::cout << "Selected: " << choice << "\n";

        switch (choice)
        {
            case 1:
            {
                recipeTest();
                break;
            }
            case 2:
            {
                searchOption();
                break;
            }
            case 3:
            {
                activateTestCases();
                break;
            }
            case 4:
            {
                profileDriver();
                break;
            }
            case 5:
            {
                removeItem();
                break;
            }
            case 6:
            {
                addWater();
                break;
            }
            case 7:
                break;
            default:
                std::cout << "Something unexpected happened" << std::endl;
        }
    }

    return 0;
}
