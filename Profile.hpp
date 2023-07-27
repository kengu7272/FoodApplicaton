/*
	Profile.hpp
	Author: Matthew Dudek
    Profile class for user and setting user info
*/
#ifndef PROFILEHPP
#define PROFILEHPP

#include <iostream>
#include <string>
#include <map>

class Profile
{
    public:
        /**
         * @brief Construct a new Profile object
         * 
         * @param name 
         * @param password 
         */
        Profile(std::string name, std::string password);

        /**
         * @brief Construct a new Profile object
         */
        Profile();

        /**
         * @brief Get the Name of the User Profile
         * 
         * @return std::string 
         */
        std::string getName();

        /**
         * @brief Set the Name of the User Profile
         * 
         * @param new_name 
         */
        void setName(std::string new_name);

        /**
         * @brief Get the Weight of the User Profile
         * 
         * @return double 
         */
        double getWeight();

        /**
         * @brief Set the Weight of the User Profile
         * 
         * @param new_weight 
         */
        void setWeight(double new_weight);

        /**
         * @brief Get the Height in centimeters of the User Profile
         * 
         * @return int 
         */
        int getHeightCM();

        /**
         * @brief Set the Height in centimeters of the User Profile
         * 
         * @param new_height_cm 
         */
        void setHeightCM(int new_height_cm);

        /**
         * @brief Compare the entered password to the profile password without exposing the profile's password
         * 
         * @param entered_password password to check
         * @return true if passwords are the same and false otherwise
         */
        bool comparePassword(std::string entered_password);

        /**
         * @brief Print the name, height, and weight of the profile
         * 
         */
        void printProfileInfo();

        /* Testing Stuff */
        // Testing the get method for profile name
        friend bool testGetProfileName();

        // Testing the set method for profile name
        friend bool testSetProfileName();

        // Testing the get method for profile weight
        friend bool testGetProfileWeight();

        // Testing the set method for profile weight
        friend bool testSetProfileWeight();

        // Testing the get method for profile height
        friend bool testGetProfileCM();

        // Testing the set method for profile height
        friend bool testSetProfileCM();

        // Testing the get method for profile password
        friend bool testGetProfilePassword();

        // Testing the set method for profile password
        friend bool testSetProfilePassword();

        // Testing the compare method for profile password
        friend bool testComparePassword();

        // Testing the change profile function
        friend bool testChangeProfileByName();
        /* End Testing Stuff */
    private:
        std::string name;
        double weight;
        int height_cm;
        std::string password;

        /**
         * @brief Get the Password of the User Profile
         * 
         * @return std::string 
         */
        std::string getPassword();

        /**
         * @brief Set the Password of the User Profile
         * 
         * @param new_password 
         */
        void setPassword(std::string new_password);
        // goal user_goal;
        // mealPlan user_meal_plan;
};

void changeSelectedProfileByName(std::string name, std::string password);
void changeProfile();
void createNewProfile();
void editProfile();
void profileDriver();

/* Testing Stuff */
void callTestingFunctions();
/* End Testing Stuff */

#endif /*Profile.hpp*/