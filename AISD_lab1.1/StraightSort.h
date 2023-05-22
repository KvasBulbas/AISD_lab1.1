#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include "createFile.h"

void split(std::string fileName, std::string fileB, std::string fileC, int p)
{
	int x;
	std::ifstream A(fileName);
	std::ofstream B(fileB);
	std::ofstream C(fileC);
	A >> x;
	while (!A.eof())
	{
		for (int i = 0; !(A.eof()) && i < p; i++)
		{
			B << x << " ";
			A >> x;
		}

		for (int i = 0; !(A.eof()) && i < p; i++)
		{
			C << x << " ";
			A >> x;
		}
	}
	A.close(); B.close(); C.close();
}


void merge(std::string fileName, std::string fileB, std::string fileC, int p)
{

	int x, y;
	std::ofstream A(fileName);
	std::ifstream B(fileB);
	std::ifstream C(fileC);
	B >> x; C >> y;

	while (!(B.eof()) && !(C.eof()))
	{

		int i = 0, j = 0;

		while (!(B.eof()) && !(C.eof()) && i < p && j < p)
		{
			if (x < y)
			{
				A << x << " ";
				B >> x;
				i++;
			}
			else
			{
				A << y << " ";
				C >> y;
				j++;
			}
		}

		while (!(B.eof()) && i < p)
		{
			A << x << " ";
			B >> x;
			i++;
		}

		while (!(C.eof()) && j < p)
		{
			A << y << " ";
			C >> y;
			j++;
		}
	}


	while (!(B.eof()))
	{
		A << x << " ";
		B >> x;
	}

	while (!(C.eof()))
	{
		A << y << " ";
		C >> y;
	}

	A.close(); B.close(); C.close();

}


bool straightSort(std::string fileName, const int numbersCount, const int maxNumberValue)
{
	std::string fileB = "Z:\\fileSorts\\fileB.txt";
	std::string fileC = "Z:\\fileSorts\\fileC.txt";
	int p = 1;
	if (!(createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue))) return -1;
	split(fileName, fileB, fileC, p);
	while (!isempty(fileC))
	{
		merge(fileName, fileB, fileC, p);
		p *= 2;
		split(fileName, fileB, fileC, p);
	}

	if (isFileContainsSortedArray(fileName))
		return 1;
	else return -2;

}