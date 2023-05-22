#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include"CreateFile.h"
#include"StraightSort.h"
#include"NaturalSort.h"

int main()
{
	const int numbersCount = 110;
	const int maxNumberValue = 200;
	std::string fileName1 = "Z:\\fileSorts\\NaturaltSort.txt";
	std::string fileName2 = "Z:\\fileSorts\\StraightSort.txt";

	for (int i = 0; i < 10; i++) {
		switch (straightSort(fileName1, numbersCount, maxNumberValue)) {
		case 1:
			std::cout << "Test passed." << std::endl;
			break;

		case -1:
			std::cout << "Test failed: can't create file." << std::endl;
			break;

		case -2:
			std::cout << "Test failed: file isn't sorted." << std::endl;
			break;
		}
	}

	return 0;
}