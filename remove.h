#ifndef remove
#define remove

#include <map>
#include <string>

//Placeholder class for testing remove and replace functions
class foods
{
public:

	foods()
	{
		foodItem = "None";
	}

	foods(std::string item)
	{
		foodItem = item;
	}

	friend std::ostream& operator << (std::ostream& output, foods data)
	{
		output << data.foodItem;
		return output;
	}

	//Function for removing food
	std::map<std::string, foods> remove_Food(std::map<std::string, foods> foodList, std::string foodName);

	//Function for replacing food
	void replace_Food(std::map<std::string, foods>& foodList, std::string foodName, std::map<std::string, foods>& bannedList);

	//Test Function
	void testCase();

private:

	std::string foodItem = "";
};

//Drives the main function
void removeItem();

#endif