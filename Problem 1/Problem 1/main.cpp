#include <iostream>
#include <set>

// TASK: Find the sum of all multiples of 3 and 5 that are less than 1000.

int main()
{
	constexpr unsigned int limit{1000};
	std::set<int> numbers;
	for (int i{3}; i < limit; i += 3)
	{
		numbers.insert(i);
	}
	for (int i{5}; i < limit; i += 5)
	{
		numbers.insert(i);
	}
	unsigned int sum{0};
	for (auto number : numbers)
	{
		sum += number;
	}
	std::cout << sum << std::endl;
	
	return 0;
}