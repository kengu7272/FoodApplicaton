/*
	utility.hpp
    utility file to hold commonly used functions
*/

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <string>

/**
 * @brief Validate the user input string
 * 
 * @param str 
 * @return true if valid, false otherwise
 */
bool strValidation(std::string str);

/**
 * @brief Validate the user input int
 * 
 * @param num user input
 * @param min minimum the input can be
 * @param max maximum the input can be
 * @return true if valid, false otherwise
 */
bool intValidation(int num, int min, int max);

#endif // UTILITY_HPP
