#include<iostream>
#include "CreateFile.h"
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>


int main()
{
	const int numbersCount = 100;
	const int maxNumberValue = 100;
	std::string fileName = "Z:\\fileSorts\\straightSort2.txt";
	createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue);

	std::cout<< isempty(fileName) << " " << isFileContainsSortedArray(fileName);

	return 0;
}