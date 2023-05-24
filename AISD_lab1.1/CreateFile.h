#pragma once
#include<iostream>
#include<fstream>
#include<random>

bool createFileWithRandomNumbers(const std::string& fileName, const int numbersCount, const int maxNumberValue)
{
	std::ofstream file(fileName);
	if (!file.is_open())
		return false;

	std::random_device rd;
	std::uniform_int_distribution<int> distribution(-maxNumberValue, maxNumberValue);
	for (int i = 0; i < numbersCount; i++)
		file << distribution(rd) << " ";

	file.close();
	return true;
}

bool isFileContainsSortedArray(const std::string& fileName)
{
	std::ifstream file(fileName);
	int number1, number2;

	file >> number1;
	for (file >> number2; !file.eof(); file >> number2)
	{
		if (number2 < number1)
		{
			file.close();
			return false;
		}
		number1 = number2;
	}

	file.close();
	return true;
}



bool isempty(std::string fileName)
{
	std::ifstream file(fileName);

	if (file.peek() == EOF)
	{
		file.close();
		return true;
	}
	file.close();
	return false;
}