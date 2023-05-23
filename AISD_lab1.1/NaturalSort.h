#pragma once

#include<iostream>
#include<fstream>
#include "createFile.h"

void split(std::string fileName, std::string fileB, std::string fileC)
{
	int x1 = 0, x2 = 0;
	std::ifstream A(fileName);
	std::ofstream B(fileB);
	std::ofstream C(fileC);

	A >> x1;
	while (!A.eof())
	{
		if (!A.eof())
		{
			B << x1 << " ";
			A >> x2;
			while (!(A.eof()) && x1 <= x2)
			{
				x1 = x2;
				B << x1 << " ";
				A >> x2;
			}
		}
		x1 = x2;

		if (!A.eof())
		{
			C << x1 << " ";
			A >> x2;
			while (!(A.eof()) && x1 <= x2)
			{
				x1 = x2;
				C << x1 << " ";
				A >> x2;
			}
		}
		x1 = x2;
	}

	
	A.close(); B.close(); C.close();
}


void merge(std::string fileName, std::string fileB, std::string fileC)
{
	int x1, x2, y1, y2;
	std::ifstream B(fileB);
	std::ifstream C(fileC);
	std::ofstream A(fileName);

	B >> x1;
	C >> y1;
	while (!(B.eof()) && !(C.eof()))
	{
		if (x1 < y1)
		{
			A << x1 << " ";
			B >> x2;
			if (!(B.eof()) && x1 > x2)
			{
				A << y1 << " ";
				C >> y2;
				while (!(C.eof()) && y1 <= y2)
				{
					y1 = y2;
					A << y1 << " ";
					C >> y2;
				}
				y1 = y2;
			}
			x1 = x2;
		}
		else
		{
			A << y1 << " ";
			C >> y2;
			if (!(C.eof()) && y1 > y2)
			{
				A << x1 << " ";
				B >> x2;
				while (!(B.eof()) && x1 <= x2)
				{
					x1 = x2;
					A << x1 << " ";
					B >> x2;
				}
				x1 = x2;
			}
			y1 = y2;
		}
	}

	while (!(B.eof()))
	{
		A << x1 << " ";
		B >> x1;
	}

	while (!(C.eof()))
	{
		A << y1 << " ";
		C >> y1;
	}

	A.close(); B.close(); C.close();
}





int naturalSort(std::string originFile, const int numberscount, const int maxnumbervalue)
{
	std::string fileB = "Z:\\fileSorts\\fileB.txt";
	std::string fileC = "Z:\\fileSorts\\fileC.txt";

	if (!(createFileWithRandomNumbers(originFile, numberscount, maxnumbervalue))) 
		return -1;

	while (true)
	{
		split(originFile, fileB, fileC);
		if (isempty(fileC)) 
			break;
		merge(originFile, fileB, fileC);
	}

	if (isFileContainsSortedArray(originFile)) 
		return 1;
	else 
		return -2;
}
