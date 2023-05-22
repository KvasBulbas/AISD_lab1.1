
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include "CreateFile.h"
#include "StraightSoirt.h"

int main()
{
	const int numbersCount = 10;
	const int maxNumberValue = 10;
	std::string fileName = "Z:\\fileSorts\\straightSort2.txt";
	std::string fileB = "Z:\\fileSorts\\fileB.txt";
	std::string fileC = "Z:\\fileSorts\\fileC.txt";
	createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue);

	//std::cout<< isempty(fileName) << " " << isFileContainsSortedArray(fileName);
	int p = 1;
	split(fileName, fileB, fileC, p);


	return 0;
}