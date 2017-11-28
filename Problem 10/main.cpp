#include <iostream>
#include <vector>
#include <cmath>

// TASK: Find the sum of all primes below two-million.

std::vector<long long int> gatherPrimesToLimit(const int limit);
bool isPrime(long long int number);
long long int sumPrimes(std::vector<long long int> primes);

int main()
{
	const int limit{2000000};
	auto primes{gatherPrimesToLimit(limit)};
	std::cout << sumPrimes(primes) << std::endl;
	return 0;
}

std::vector<long long int> gatherPrimesToLimit(const int limit)
{
	std::vector<long long int> primes;
	const int startingPrime{2};
	for (int i{startingPrime}; i < limit; ++i)
	{
		if (isPrime(i))
		{
			primes.push_back(i);
		}
	}
	return primes;
}

bool isPrime(long long int number)
{
	for (long long int i{2}; i <= std::sqrt(number); ++i)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	return true;
}

long long int sumPrimes(std::vector<long long int> primes)
{
	long long int sum{0};
	for (auto prime : primes)
	{
		sum += prime;
	}
	return sum;
}
