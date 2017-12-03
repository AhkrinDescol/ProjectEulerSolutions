#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// TODO: Work out the first ten digits of the sum of the following
// 		 one-hundred 50-digit numbers.

std::vector<std::string> gatherValuesAsStrings(std::string fileName);
std::string sumNumberStrings(const std::vector<std::string>& valuesAsStrings);
std::string sumTwoNumberStrings(std::string lhs, std::string rhs);

int main()
{
	const std::string fileName{"Values File.txt"};
	auto valuesAsStrings{gatherValuesAsStrings(fileName)};
	std::string summedStrings{sumNumberStrings(valuesAsStrings)};
	std::cout << "The first ten digits are: ";
	for (size_t i{0}; i < 10; ++i)
	{
		std::cout << summedStrings[i];
	}
	std::cout << std::endl;
	std::cout << "And the remainder are: ";
	for (size_t i{10}; i < summedStrings.size(); ++i)
	{
		std::cout << summedStrings[i];
	}
	return 0;
}

std::vector<std::string> gatherValuesAsStrings(std::string fileName)
{
	std::ifstream inputStream{fileName};
	std::vector<std::string> valuesAsStrings;
	std::string numberAsString;
	while (std::getline(inputStream, numberAsString))
	{
		valuesAsStrings.push_back(numberAsString);
	}
	return valuesAsStrings;
}

std::string sumNumberStrings(const std::vector<std::string>& valuesAsStrings)
{
	std::string sum;
	for (auto value : valuesAsStrings)
	{
		sum = sumTwoNumberStrings(sum, value);
	}
	return sum;
}

std::string sumTwoNumberStrings(std::string lhs, std::string rhs)
{
	if (lhs.size() < rhs.size())
	{
		std::swap(lhs, rhs);
	}
	for (int i(lhs.size() - 1), j(rhs.size() - 1); j >= 0; --i, --j)
	{
		lhs[i] += (rhs[j] - '0');
	}
	for (int i(lhs.size() - 1); i > 0; --i)
	{
		if (lhs[i] > '9')
		{
			int digit{lhs[i] - '0'};
			lhs[i - 1] = ((lhs[i - 1] - '0') + digit / 10) + '0';
			lhs[i] = (digit % 10) + '0';
		}
	}
	if (lhs[0] > '9')
	{
		std::string subLhs;
		subLhs += lhs[0];
		lhs[0] = ((lhs[0] - '0') % 10) + '0';
		subLhs[0] = ((subLhs[0] - '0') / 10) + '0';
		lhs = subLhs + lhs;
	}
	return lhs;
}
