#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include "CreateFile.h"
#include "StraightSoirt.h"

int main()
{
	const int numbersCount = 15;
	const int maxNumberValue = 30;
	std::string fileName = "Z:\\fileSorts\\straightSort2.txt";
	std::string fileB = "Z:\\fileSorts\\fileB.txt";
	std::string fileC = "Z:\\fileSorts\\fileC.txt";


	//std::cout<< isempty(fileName) << " " << isFileContainsSortedArray(fileName);
	straightSort(fileName, numbersCount, maxNumberValue);


	return 0;
}