#include <iostream>
#include <cmath>

// TASK: Find the largest prime factor of 600851475143.

int main()
{
	constexpr long int subjectNumber{600851475143};
	constexpr long int subNumRoot{std::ceil(std::sqrt(subjectNumber))};

	std::cout << subjectNumber << std::endl;
	return 0;
}
