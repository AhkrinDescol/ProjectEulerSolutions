#include <iostream>
#include <cmath>

// TASK: Find the largest prime factor of 600851475143.

template <typename T>
bool isPrime(T value);

int main()
{
	const long long int subjectNumber{600851475143};
	const auto subNumRoot(static_cast<long long int>(std::ceil(std::sqrt(subjectNumber))));
	long int largestPrimeFactor{0};
	for (long long int i{2}; i < subNumRoot; ++i)
	{
		if (subjectNumber % i == 0 && isPrime(i))
		{
			largestPrimeFactor = i;
		}
	}
	std::cout << largestPrimeFactor << std::endl;

	return 0;
}

template <typename T>
bool isPrime(T value)
{
	T valueRoot(static_cast<T>(sqrt(value)));
	bool isPrime{true};
	for (int i{2}; i < valueRoot; ++i)
	{
		if (value % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
}
