/*
	Profile.cpp
	Author: Matthew Dudek
    Profile class for user and setting user info
*/
#include "Profile.hpp"
#include "utility.hpp"

#include <iostream>

#define QUIT_NUM 5
#define MIN_CHOICE 0
#define MAX_CHOICE 5

Profile selected_profile = Profile("John", "123");
std::map<std::string, Profile> profile_map;

Profile::Profile(std::string name, std::string password)
{
    this->name = name;
    this->password = password;
    this->weight = 0;
    this->height_cm = 0;
}

Profile::Profile()
{
    this->weight = 0;
    this->height_cm = 0;
}

std::string Profile::getName()
{
    return this->name;
}

void Profile::setName(std::string new_name)
{
    this->name = new_name;
}

double Profile::getWeight()
{
    return this->weight;
}

void Profile::setWeight(double new_weight)
{
    this->weight = new_weight;
}

int Profile::getHeightCM()
{
    return this->height_cm;
}

void Profile::setHeightCM(int new_height_cm)
{
    this->height_cm = new_height_cm;
}

bool Profile::comparePassword(std::string entered_password)
{
    return (this->password == entered_password);
}

void Profile::printProfileInfo()
{
    std::cout << "Profile parameters:\n";
    std::cout << "Name\t" << this->getName() << "\n";
    std::cout << "Height\t" << this->getHeightCM() << "cm\n";
    std::cout << "Weight\t" << this->getWeight() << "lb\n\n";
}

std::string Profile::getPassword()
{
    return this->password;
}

void Profile::setPassword(std::string new_password)
{
    this->password = new_password;
}

void changeSelectedProfileByName(std::string name, std::string password)
{
    Profile tempProf = profile_map[name];
    if (tempProf.comparePassword(password))
    {
        selected_profile = tempProf;
        std::cout << "Profile successfully changed\n";
    }
    else
    {
        std::cerr << "\nError! password incorrect, profile not changed!\n";
    }
}

void changeProfile()
{
    std::string name;
    std::string password;
    do
    {
        std::cout << "Please enter a profile name\n";
        std::cin >> name;
    } while (!strValidation(name));

    do
    {
        std::cout << "Please enter the password for the profile\n";
        std::cin >> password;
    } while (!strValidation(password));

    changeSelectedProfileByName(name, password);
}

void createNewProfile()
{
    std::string name;
    std::string password;
    std::string double_check_password;
    do
    {
        std::cout << "Please enter a valid name for the profile\n";
        std::cin >> name;
    } while (!strValidation(name));

    bool failed;
    do
    {
        failed = false;
        do
        {
            std::cout << "Please enter a valid password for the profile\n";
            std::cin >> password;
        } while (!strValidation(password));

        std::cout << "Please enter the same password\n";
        std::cin >> double_check_password;

        if (double_check_password.compare(password) != 0)
        {
            std::cout << "Passwords did not match\n";
            failed = true;
        }
    } while ((!strValidation(double_check_password)) || failed);

    Profile new_prof = Profile(name, password);
    profile_map[new_prof.getName()] = new_prof;
    std::cout << "Profile Created!\n\n";
}

void editProfile()
{
    int min = 1;
    int max = 4;
    int quit = 4;
    int choice = -1;
    std::string temp_str;
    int temp_int;

    while(choice != quit)
    {
        selected_profile.printProfileInfo();

        do
        {
            std::cout << "Please enter a number corresponding to a parameter:\n";
            std::cout << "1: Change Name\n";
            std::cout << "2: Change Height\n";
            std::cout << "3: Change Weight\n";
            std::cout << "4: Done\n";
            std::cin >> choice;
        } while(!intValidation(choice, min, max));

        switch(choice)
        {
            case 1:
            {
                do
                {
                    std::cout << "Please enter a new name for the Profile\n";
                    std::cin >> temp_str;
                } while (!strValidation(temp_str));
                profile_map.erase(selected_profile.getName());
                selected_profile.setName(temp_str);
                profile_map[selected_profile.getName()] = selected_profile;
                break;
            }
            case 2:
            {
                do
                {
                    std::cout << "Please enter a new height for the Profile\n";
                    std::cin >> temp_int;
                } while (!intValidation(temp_int, 0, 500));
                selected_profile.setHeightCM(temp_int);
                break;
            }
            case 3:
            {
                do
                {
                    std::cout << "Please enter a new weight for the Profile\n";
                    std::cin >> temp_int;
                } while (!intValidation(temp_int, 0, 500));
                selected_profile.setWeight(temp_int);
                break;
            }
            default:
            {
                std::cout << choice << "\n";
                break;
            }
        }
    }
}

static void usage()
{
    std::cout << "Please enter a number corresponding to an action:\n";
    std::cout << "1: Run all the tests\n";
    std::cout << "2: Add a new profile\n";
    std::cout << "3: Login to profile\n";
    std::cout << "4: Set Selected Profile parameters\n";
    std::cout << "5: Back\n\n";
}

void profileDriver()
{
    int choice = -1;
    while (choice != QUIT_NUM)
    {
        do
        {
            usage();
            std::cin >> choice;
        } while (!intValidation(choice, MIN_CHOICE, MAX_CHOICE));
        
        switch (choice)
        {
            case 1:
            {
                callTestingFunctions();
                break;
            }
            case 2:
            {
                createNewProfile();
                break;
            }
            case 3:
            {
                changeProfile();
                break;
            }
            case 4:
            {
                editProfile();
                break;
            }
            case 5:
            {
                break;
            }
        }
    }
}

// /* Run Tests */
// int main()
// {
//     callTestingFunctions();
// }

/* Testing Stuff */
bool testGetProfileName()
{
    std::string test_prof_name = "test_name_get";
    
    Profile test_prof = Profile();
    test_prof.name = test_prof_name;
    if (test_prof_name.compare(test_prof.getName()) == 0)
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_name << " != " << test_prof.getName() << "\n";

    return false;
}

bool testSetProfileName()
{
    std::string test_prof_name = "test_name_set";
    
    Profile test_prof = Profile();
    test_prof.setName(test_prof_name);
    if (test_prof_name.compare(test_prof.name) == 0)
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_name << " != " << test_prof.name << "\n";

    return false;
}

bool testGetProfileWeight()
{
    int test_prof_weight = 152;
    
    Profile test_prof = Profile();
    test_prof.weight = test_prof_weight;
    if (test_prof_weight == test_prof.getWeight())
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_weight << " != " << test_prof.getWeight() << "\n";

    return false;
}

bool testSetProfileWeight()
{
    int test_prof_weight = 215;
    
    Profile test_prof = Profile();
    test_prof.setWeight(test_prof_weight);
    if (test_prof_weight == test_prof.weight)
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_weight << " != " << test_prof.weight << "\n";

    return false;
}

bool testGetProfileCM()
{
    int test_prof_height = 67;
    
    Profile test_prof = Profile();
    test_prof.height_cm = test_prof_height;
    if (test_prof_height == test_prof.getHeightCM())
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_height << " != " << test_prof.getHeightCM() << "\n";

    return false;
}

bool testSetProfileCM()
{
    int test_prof_height = 76;
    
    Profile test_prof = Profile();
    test_prof.setHeightCM(test_prof_height);
    if (test_prof_height == test_prof.height_cm)
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_height << " != " << test_prof.height_cm << "\n";

    return false;
}

bool testGetProfilePassword()
{
    std::string test_prof_pass = "t3$tp@55w0rd";
    
    Profile test_prof = Profile();
    test_prof.password = test_prof_pass;
    if (test_prof_pass.compare(test_prof.getPassword()) == 0)
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_pass << " != " << test_prof.getPassword() << "\n";

    return false;
}

bool testSetProfilePassword()
{
    std::string test_prof_pass = "t3$tp@55w0rd";
    
    Profile test_prof = Profile();
    test_prof.setPassword(test_prof_pass);
    if (test_prof_pass.compare(test_prof.password) == 0)
    {
        std::cout << "[" << __func__ << " PASSED]\n";
        return true;
    }
    std::cerr << __func__ << "\n" << test_prof_pass << " != " << test_prof.password << "\n";

    return false;
}

bool testComparePassword()
{
    std::string test_prof_pass = "t3$tp@55w0rd";
    std::string test_prof_pass_fail = "d03sn0tm@tch";

    bool pass_flag = true;
    
    Profile test_prof = Profile();
    test_prof.password = test_prof_pass;
    if (!test_prof.comparePassword(test_prof_pass_fail))
    {
    }
    else
    {
        std::cerr << __func__ << "\n" << test_prof_pass << " == " << test_prof.password << "\n";
        pass_flag = false;
    }
    
    if (test_prof.comparePassword(test_prof_pass))
    {
    }
    else
    {
        std::cerr << __func__ << "\n" << test_prof_pass << " != " << test_prof.password << "\n";
        pass_flag = false;
    }

    std::cout << "[" << __func__ << " PASSED]\n";
    return pass_flag;
}

bool testChangeProfileByName()
{
    Profile prof1 = Profile();
    std::string prof1_name = "John";
    std::string prof1_pass = "password";
    prof1.setName(prof1_name);
    prof1.setPassword(prof1_pass);
    profile_map[prof1_name] = prof1;

    Profile prof2 = Profile();
    std::string prof2_name = "Jane";
    std::string prof2_pass = "other_password";
    prof2.setName(prof2_name);
    prof2.setPassword(prof2_pass);
    profile_map[prof2_name] = prof2;

    selected_profile = prof1;
    changeSelectedProfileByName(prof2_name, prof2_pass);
    if (selected_profile.name.compare(prof2.name) == 0)
    {
        std::cout << "[" << __func__ << " PASSED]\n";
    }
    else
    {
        std::cerr << __func__ << "\n" << selected_profile.name << " != " << prof2_name << "\n";
        return false;
    }

    selected_profile = prof1;
    changeSelectedProfileByName(prof2_name, prof1_pass);
    if (selected_profile.name.compare(prof2.name) != 0)
    {
        std::cout << "[" << __func__ << " PASSED](Error message ^ expected)\n";
    }
    else
    {
        std::cerr << __func__ << "\n" << selected_profile.name << " == " << prof2_name << "\n";
        return false;
    }
    return true;
}

void callTestingFunctions()
{
    testGetProfileName();
    testSetProfileName();
    testGetProfileWeight();
    testSetProfileWeight();
    testGetProfileCM();
    testSetProfileCM();
    testGetProfilePassword();
    testSetProfilePassword();
    testComparePassword();
    testChangeProfileByName();
    std::cout << "\n";
}
