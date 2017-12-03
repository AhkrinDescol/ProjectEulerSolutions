#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// TODO: Work of the first ten digits of the sum of the following
// 		 one-hundred 50-digit numbers.

std::vector<std::string> gatherValuesAsStrings(std::string fileName);
std::string sumNumberStrings(const std::vector<std::string>& valuesAsStrings);
std::string sumTwoNumberStrings(const std::string& lhs, const std::string& rhs);

int main()
{
	const std::string fileName{"Values File.txt"};
	auto valuesAsStrings{gatherValuesAsStrings(fileName)};
	
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
	for (const auto value : valuesAsStrings)
	{
		sum = sumTwoNumberStrings(sum, value);
	}
	return sum;
}

std::string sumTwoNumberStrings(const std::string& lhs, const std::string& rhs)
{
	std::string sum;
	auto longerIndex{std::max(lhs.size(), rhs.size())};
	bool carryOne{false};
	for (int i{0}; i < longerIndex; ++i)
	{
		std::string singleAddition;
		if (i > lhs.size())
		{
			singleAddition = rhs[rhs.size() - i];
		}
		else if (i > rhs.size())
		{
			singleAddition = lhs[lhs.size() - i];
		}
		else
		{
			const int lhsAsInt{lhs[lhs.size() - i] - '0'};
			const int rhsAsInt{rhs[rhs.size() - i] - '0'};
			int sumAsInt{lhsAsInt + rhsAsInt};
			if (carryOne)
			{
				++sumAsInt;
				carryOne = false;
			}
			if (sumAsInt > 9)
			{
				carryOne = true;
			}
			singleAddition += std::to_string(sumAsInt);
		}
		sum.push_back(singleAddition.back());
	}
	
	return sum;
}
