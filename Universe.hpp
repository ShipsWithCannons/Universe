#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP

/*

Project	: Universe
By		: Mast
Date	: August '14

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct Planet
{
private:
	int x;
	int y;
	int z;
	int Mlvl;
	int Clvl;
	int Dlvl;
	int Mstor;
	int Cstor;
	int Dstor;

public:
	Planet(int x, int y, int z, int Mlvl, int Clvl, int Dlvl, int Mstor, int Cstor, int Dstor) : x(x), y(y), z(z), Mlvl(Mlvl), Clvl(Clvl), Dlvl(Dlvl), Mstor(Mstor), Cstor(Cstor), Dstor(Dstor) {}

	int get_x();
	int get_y();
	int get_z();
	int get_Mlvl();
	int get_Clvl();
	int get_Dlvl();
	int get_Mstor();
	int get_Cstor();
	int get_Dstor();

	int getPlanet();
	void printPlanet();
	int getMlvl();
	int getClvl();
	int getDlvl();
};

int Planet::getPlanet()
{
	return x, y, z, Mlvl, Clvl, Dlvl, Mstor, Cstor, Dstor;
}

void Planet::printPlanet()
{
	std::cout << x << ':'
		<< y << ':'
		<< z << ' '
		<< Mlvl << ' '
		<< Clvl << ' '
		<< Dlvl << ' '
		<< Mstor << ' '
		<< Cstor << ' '
		<< Dstor
		<< '\n';
}

int Planet::getMlvl()
{
	return Mlvl;
}

int Planet::getClvl()
{
	return Clvl;
}

int Planet::getDlvl()
{
	return Dlvl;
}

struct Universe
{
private:
	std::string sName;
	std::vector<Planet> Planets;

public:
	Universe(std::string sName) : sName(sName) {}

	std::vector<std::string> vsSanitizeData(std::vector<std::string>);

	void sort_x();
	void sort_y();
	void sort_z();
	void sort_Mlvl();
	void sort_Clvl();
	void sort_Dlvl();
	void readCSV();
	void addPlanet(Planet);
	int splitString(std::string);

	void getUniverse();
	void printUniverse();
};

int Planet::get_x()
{
	return x;
}
int Planet::get_y()
{
	return y;
}
int Planet::get_z()
{
	return z;
}
int Planet::get_Mlvl()
{
	return Mlvl;
}
int Planet::get_Clvl()
{
	return Clvl;
}
int Planet::get_Dlvl()
{
	return Dlvl;
}

struct compare_x
{
	inline bool operator() (Planet& left, Planet& right)
	{
		return (left.get_x() < right.get_x());
	}
};

struct compare_y
{
	inline bool operator() (Planet& left, Planet& right)
	{
		return (left.get_y() < right.get_y());
	}
};

struct compare_z
{
	inline bool operator() (Planet& left, Planet& right)
	{
		return (left.get_z() < right.get_z());
	}
};

struct compare_Mlvl
{
	inline bool operator() (Planet& left, Planet& right)
	{
		return (left.get_Mlvl() < right.get_Mlvl());
	}
};

struct compare_Clvl
{
	inline bool operator() (Planet& left, Planet& right)
	{
		return (left.get_Clvl() < right.get_Clvl());
	}
};

struct compare_Dlvl
{
	inline bool operator() (Planet& left, Planet& right)
	{
		return (left.get_Dlvl() < right.get_Dlvl());
	}
};

void Universe::sort_x()
{
	std::sort(Planets.begin(), Planets.end(), compare_x());
}

void Universe::sort_y()
{
	std::sort(Planets.begin(), Planets.end(), compare_y());
}

void Universe::sort_z()
{
	std::sort(Planets.begin(), Planets.end(), compare_z());
}

void Universe::sort_Mlvl()
{
	std::sort(Planets.begin(), Planets.end(), compare_Mlvl());
}

void Universe::sort_Clvl()
{
	std::sort(Planets.begin(), Planets.end(), compare_Clvl());
}

void Universe::sort_Dlvl()
{
	std::sort(Planets.begin(), Planets.end(), compare_Dlvl());
}

std::vector<std::string> Universe::vsSanitizeData(std::vector<std::string> Vec)
{
	std::vector<std::string>::iterator vI = Vec.begin();
	while (vI != Vec.end())
	{
		if (*vI == "")
		{
			vI = Vec.erase(vI);
		}
		else
		{
			vI++;
		}
	}

	return Vec;
};

void Universe::readCSV()
{
	std::ifstream input("Galaxy.txt", std::ios::in);
	std::string sRead;
	std::vector<std::string> sData;
	std::vector<std::string>::iterator itData;
	while (input.good())
	{
		getline(input, sRead);
		sData.push_back(sRead);
	}
	sData = vsSanitizeData(sData);
	for (itData = sData.begin(); itData != sData.end(); itData++)
	{
		splitString(*itData);
		std::cout << '\n';
	}

}

void Universe::addPlanet(Planet p)
{
	Planets.push_back(p);
}

void Universe::getUniverse()
{
	for (unsigned i = 0; i < Planets.size(); i++)
	{
		Planets[i].getPlanet();
	}
}

void Universe::printUniverse()
{
	std::cout << '\n';
	for (unsigned i = 0; i < Planets.size(); i++)
	{
		Planets[i].printPlanet();
	}
}

int Universe::splitString(std::string sSplitInp)
{
	char primaryLimiter = ';';
	char secondLimiter = ':';
	std::string sTemp;
	std::vector<int> vTemp;

	for (size_t p = 0, q = 0; p != sSplitInp.npos; p = q)
	{
		sTemp = sSplitInp.substr(p + (p != 0), (q = sSplitInp.find(primaryLimiter, p + 1)) - p - (p != 0));
		std::cout << sTemp << ' ';
		if (p == 0)
		{
			std::string sNew;
			size_t j = 0, k = 0;
			for (unsigned i = 0; i <= 2; i++)
			{
				sNew = sTemp.substr(j + (j != 0), (k = sTemp.find(secondLimiter, j + 1)) - j - (j != 0));
				vTemp.push_back(atoi(sNew.c_str()));
				j = k;
			}
		}
		else
		{
			vTemp.push_back(atoi(sTemp.c_str()));
		}
	}
	addPlanet(Planet(vTemp[0], vTemp[1], vTemp[2], vTemp[3], vTemp[4], vTemp[5], vTemp[6], vTemp[7], vTemp[8])); // ugly

	return 0;
}

#endif