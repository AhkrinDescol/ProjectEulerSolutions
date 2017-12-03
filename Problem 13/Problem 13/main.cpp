#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

// TODO: Work of the first ten digits of the sum of the following
// 	 one-hundred 50-digit numbers.

std::vector<unsigned long long int> gatherAndTruncateValues(std::string fileName);


int main()
{
	
	
	return 0;
}

std::vector<unsigned long long int> gatherAndTruncateValues(std::string fileName)
{
	std::ifstream inputStream{fileName};
	std::vector<unsigned long long int> truncatedValues;
	std::string numberAsString;
	std::getline(inputStream, numberAsString);
}
