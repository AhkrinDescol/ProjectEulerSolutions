#include <iostream>

// TASK: Find the smallest number that is divisible by 1-20 with no remainder.
//
int main()
{
	const int lowestDivisor{2}, highestDivisor{20};
	unsigned long long int smallestDivisibleNumber{0};
	for (int i{highestDivisor}; smallestDivisibleNumber == 0; ++i)
	{
		bool isFullyDivisible{true};
		for (int j{lowestDivisor}; j <= highestDivisor; ++j)
		{
			if (i % j != 0)
			{
				isFullyDivisible = false;
				break;
			}
		}
		if (isFullyDivisible)
		{
			smallestDivisibleNumber = i;
		}
	}
	std::cout << "The smallest positive integer that is evenly divisible between "
		<< lowestDivisor << " and " << highestDivisor << " is "
		<< smallestDivisibleNumber << std::endl;

	return 0;
}
