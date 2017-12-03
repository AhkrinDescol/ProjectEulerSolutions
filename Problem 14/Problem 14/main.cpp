#include <iostream>

int getLongestCollatzValue(int limit);
int getCollatzChainLength(unsigned long long int number);

int main()
{
	const int limit{1000000};
	std::cout << getLongestCollatzValue(limit) << std::endl;
	return 0;
}

int getLongestCollatzValue(int limit)
{
	int longestCollatzValue{1};
	int longestCollatzLength{0};
	for (int i{limit - 1}; i > 0; --i)
	{
		const int currentCollatzLength{getCollatzChainLength(i)};
		if (currentCollatzLength > longestCollatzLength)
		{
			longestCollatzLength = currentCollatzLength;
			longestCollatzValue = i;
		}
	}
	return longestCollatzValue;
}

int getCollatzChainLength(unsigned long long int number)
{
	int chainLength{0};
	while (number != 1)
	{
		if (number & 1)
		{
			number = number * 3 + 1;
		}
		else
		{
			number /= 2;
		}
		++chainLength;
	}
	return chainLength;
}