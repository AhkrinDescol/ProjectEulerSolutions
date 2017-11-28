#include <iostream>

// TASK: Find the difference between the sum of the squares of the first one
// hundred natural numbers and the square of the sum.
//
// The sum of the squares of the first ten natural numbers is 
// 12 + 22 + ... + 102 = 385
//
// The square of the sum of the first ten natural numbers is
// (1 + 2 + ... + 10)^2 = 552 = 3025
//
// Hence the difference between the sum of the squares of the first ten natural
// numbers and the square of the sum is 3025 − 385 = 2640.

long long int sumSquaresUpToN(const int n);
long long int sumThenSquareUpToN(const int n);

int main()
{
	std::cout << "Enter the value of n: ";
	int n{0};
	std::cin >> n;
	auto summedSquares{sumSquaresUpToN(n)};
	auto sumSquared{sumThenSquareUpToN(n)};
	std::cout << "summedSquares: " << summedSquares << std::endl;
	std::cout << "sumSquared: " << sumSquared << std::endl;
	std::cout << "Difference: " << std::abs(summedSquares - sumSquared)
		<< std::endl;
	return 0;
}

long long int sumSquaresUpToN(const int n)
{
	const int startingValue{1};
	long long int summedSquares{0};
	for (int i{startingValue}; i <= n; ++i)
	{
		summedSquares += (i * i);
	}
	return summedSquares;
}

long long int sumThenSquareUpToN(const int n)
{
	const int startingValue{1};
	long long int sumSquared{0};
	for (int i{startingValue}; i <= n; ++i)
	{
		sumSquared += i;
	}
	sumSquared *= sumSquared;
	return sumSquared;
}
