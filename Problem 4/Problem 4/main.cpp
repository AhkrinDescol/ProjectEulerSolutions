#include <iostream>
#include <string>

// TASK: Find the largest palindrome that can be made from the product of
//		 two three-digit numbers.

int findLargestPalindrome(const int min, const int max);
bool isPalindrome(int number);

int main()
{
	const int min{100}, max{1000};
	const int largestPalindrome{findLargestPalindrome(min, max)};
	std::cout << largestPalindrome << std::endl;
	return 0;
}

int findLargestPalindrome(const int min, const int max)
{
	int largestPalindrome{0};
	for (int i{min}; i < max; ++i)
	{
		for (int j{i}; j < max; ++j)
		{
			const int number{i*j};
			if (number > largestPalindrome && isPalindrome(number))
			{
				largestPalindrome = number;
			}
		}
	}
	return largestPalindrome;
}

bool isPalindrome(int number)
{
	std::string numAsString{std::to_string(number)};
	for (size_t i{0}, j{numAsString.size() - 1}; i <= j; ++i, --j)
	{
		if (numAsString[i] != numAsString[j])
		{
			return false;
		}
	}
	return true;
}
