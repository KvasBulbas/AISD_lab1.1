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