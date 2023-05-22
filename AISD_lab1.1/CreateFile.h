#pragma once
#include<iostream>
#include<iostream>
#include<fstream>
#include<ctime>
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
	std::fstream file(fileName);
	int number1, number2;
	file >> number1;
	for (file >> number2; !file.eof(); file >> number2)
	{
		if (number2 < number1) return false;
		number1 = number2;
	}
	return true;
}



bool isempty(std::string fileName)
{
	std::ifstream file(fileName);
	if (file.peek() == EOF) return true;
	else return false;
}