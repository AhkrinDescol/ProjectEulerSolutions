#include <iostream>
#include <vector>

// TASK: Find the 10,001st prime number.

bool isPrime(int number);

int main()
{
	const long long int firstPrime{2};
	const int limitDesired{10001};
	std::vector<long long int> primes;
	primes.push_back(firstPrime);
	for (auto i{firstPrime + 1}; primes.size() < limitDesired; ++i)
	{
		if (isPrime(i))
		{
			primes.push_back(i);
		}
	}
	std::cout << primes.back() << std::endl;
	return 0;
}

bool isPrime(int number)
{
	for (int i{2}; i < number; ++i)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}
