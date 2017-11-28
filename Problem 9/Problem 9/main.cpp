#include <iostream>
#include <cmath>
#include <vector>

// TASK: A pythagoran triplet is a set of three natural numbers, a < b < c,
//		 for which a^2 + b^2 = c^2. There is exactly one Pythagoran triplet
//		 where a + b + c = 1000. Find the product of abc.

int getProduct(const std::vector<int>& numbers);
std::vector<int> findSpecialTriplet();

int main()
{
	const auto specialTripletProduct{getProduct(findSpecialTriplet())};
	std::cout << specialTripletProduct << std::endl;
	return 0;
}

int getProduct(const std::vector<int>& numbers)
{
	if (numbers.size() == 0)
	{
		std::cout << "Error: Vector of ints contains no values." << std::endl;
	}
	int product{1};
	for (auto number : numbers)
	{
		product *= number;
	}
	return product;
}

std::vector<int> findSpecialTriplet()
{
	const int sumLimit{1000};
	std::vector<int> tripletValues;
	for (int c{sumLimit}; c > 0; --c)
	{
		for (int b{sumLimit - c}; b > 0; --b)
		{
			for (int a{sumLimit - (c + b)}; a > 0; --a)
			{
				if (a + b + c == sumLimit)
				{
					if (std::pow(a, 2) + std::pow(b, 2) == std::pow(c, 2))
					{
						tripletValues.push_back(a);
						tripletValues.push_back(b);
						tripletValues.push_back(c);
						return tripletValues;
					}
				}
			}
		}
	}
}
