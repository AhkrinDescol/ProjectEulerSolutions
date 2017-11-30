#include <iostream>
#include <vector>
#include <fstream>

std::vector<std::vector<int>> readValuesIntoGrid(std::ifstream& inputStream);
int findGreatestProductInGrid(const std::vector<std::vector<int>>& grid);
int greatestRowProduct(const std::vector<std::vector<int>>& grid);
int greatestColumnProduct(const std::vector<std::vector<int>>& grid);
int greatestDownRightDiagonalProduct(const std::vector<std::vector<int>>& grid);
int greatestDownLeftDiagonalProduct(const std::vector<std::vector<int>>& grid);

int main()
{
	const std::string fileName{"Grid Values.txt"};
	std::ifstream inputStream{fileName};
	if (!inputStream)
	{
		std::cout << "Error: File does not exist, exiting..." << std::endl;
		return 1;
	}
	const auto gridValues{readValuesIntoGrid(inputStream)};
	inputStream.close();
	std::cout << findGreatestProductInGrid(gridValues) << std::endl;
	return 0;
}

std::vector<std::vector<int>> readValuesIntoGrid(std::ifstream& inputStream)
{
	std::vector<std::vector<int>> gridValues;
	const size_t rowSize{20};
	const size_t columnSize{rowSize};
	for (int i{0}; i < rowSize; ++i)
	{
		std::vector<int> row;
		for (int j{0}; j < columnSize; ++j)
		{
			int value{0};
			inputStream >> value;
			row.push_back(value);
		}
		gridValues.push_back(row);
	}
	return gridValues;
}

int findGreatestProductInGrid(const std::vector<std::vector<int>>& grid)
{
	int greatestProduct{0};
	int temp{0};
	temp = greatestRowProduct(grid);
	if (temp > greatestProduct)
	{
		greatestProduct = temp;
	}
	temp = greatestColumnProduct(grid);
	if (temp > greatestProduct)
	{
		greatestProduct = temp;
	}
	temp = greatestDownRightDiagonalProduct(grid);
	if (temp > greatestProduct)
	{
		greatestProduct = temp;
	}
	temp = greatestDownLeftDiagonalProduct(grid);
	if (temp > greatestProduct)
	{
		greatestProduct = temp;
	}
	return greatestProduct;
}

int greatestRowProduct(const std::vector<std::vector<int>>& grid)
{
	int greatestRowProduct{0};
	const size_t valuesPerProduct{4};
	const size_t offset{valuesPerProduct - 1};
	for (auto row : grid)
	{
		for (size_t i{0}; i < row.size() - offset; ++i)
		{
			int product{1};
			for (size_t j{i}; j < i + valuesPerProduct; ++j)
			{
				product *= row[j];
			}
			if (product > greatestRowProduct)
			{
				greatestRowProduct = product;
			}
		}
	}
	return greatestRowProduct;
}

int greatestColumnProduct(const std::vector<std::vector<int>>& grid)
{
	int greatestColumnProduct{0};
	const size_t valuesPerProduct{4};
	const size_t offset{valuesPerProduct - 1};
	for (size_t x{0}; x < grid[0].size(); ++x)
	{
		for (size_t y{0}; y < grid.size() - offset; ++y)
		{
			int product{1};
			for (size_t i{0}; i < valuesPerProduct; ++i)
			{
				product *= grid[x][y + i];
			}
			if (product > greatestColumnProduct)
			{
				greatestColumnProduct = product;
			}
		}
	}
	return greatestColumnProduct;
}

int greatestDownRightDiagonalProduct(const std::vector<std::vector<int>>& grid)
{
	int greatestDiagonalProduct{0};
	const size_t valuesPerProduct{4};
	const size_t offset{valuesPerProduct - 1};
	for (size_t x{0}; x < grid[0].size() - offset; ++x)
	{
		for (size_t y{0}; y < grid.size() - offset; ++y)
		{
			int product{1};
			for (size_t i{0}; i < valuesPerProduct; ++i)
			{
				product *= grid[x + i][y + i];
			}
			if (product > greatestDiagonalProduct)
			{
				greatestDiagonalProduct = product;
			}
		}
	}
	return greatestDiagonalProduct;
}

int greatestDownLeftDiagonalProduct(const std::vector<std::vector<int>>& grid)
{
	int greatestDiagonalProduct{0};
	const size_t valuesPerProduct{4};
	const size_t offset{valuesPerProduct - 1};
	for (size_t x{offset}; x < grid[0].size(); ++x)
	{
		for (size_t y{0}; y < grid.size() - offset; ++)
	}
}
