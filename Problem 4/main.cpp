#include <iostream>
#include <string>

// TASK: Find the largest palindrome that can be made from the product of
//		 two three-digit numbers.

bool isPalindrome(int number);

int main()
{
	int largestPalindrome{0};
	int lhs{100}, rhs{100};
	for (int i{100}; i < 1000; ++i)
	{
		for (int j{100}; j < 1000; ++j)
		{
			int number{i*j};
			if (isPalindrome(number))
			{
				largestPalindrome = number;
				lhs = i;
				rhs = j;
			}
		}
	}
	std::cout << lhs << " * " << rhs << " gives " << largestPalindrome 
		<< std::endl;

	return 0;
}

bool isPalindrome(int number)
{
	std::string numAsString{std::to_string(number)};
	bool isPalindrome{true};
	for (size_t i{0}, j{numAsString.size() - 1}; i <= j; ++i, --j)
	{
		if (numAsString[i] != numAsString[j])
		{
			isPalindrome = false;
			break;
		}
	}

	return isPalindrome;
}
