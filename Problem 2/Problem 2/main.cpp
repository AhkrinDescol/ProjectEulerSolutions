#include <iostream>
#include <vector>

// TASK: Find all even Fibonacci sequence values below 4,000,000 and sum them.

int main()
{
	std::vector<int> evenFibNumbers;
	int prevValue{1};
	int curValue{2};
	constexpr int limit{4000000};
	while (curValue < limit)
	{
		if ((curValue & 1) == 0)
		{
			evenFibNumbers.push_back(curValue);
		}
		int temp{prevValue};
		prevValue = curValue;
		curValue = prevValue + temp;
	}
	int sum{0};
	for (auto number : evenFibNumbers)
	{
		sum += number;
	}
	std::cout << sum << std::endl;
	
	return 0;
}