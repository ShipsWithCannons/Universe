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
	int x;
	int y;
	int z;
	int Mlvl;
	int Clvl;
	int Dlvl;
	int Plvl;
	int Mstor;
	int Cstor;
	int Dstor;

	Planet(int x, int y, int z, int Mlvl, int Clvl, int Dlvl, int Plvl, int Mstor, int Cstor, int Dstor) : x(x), y(y), z(z), Mlvl(Mlvl), Clvl(Clvl), Dlvl(Dlvl), Plvl(Plvl), Mstor(Mstor), Cstor(Cstor), Dstor(Dstor) {}

	~Planet(){};

	int getPlanet();
	void printPlanet();
	int getMlvl();
	int getClvl();
	int getDlvl();
};

int Planet::getPlanet()
{
	return x, y, z, Mlvl, Clvl, Dlvl, Plvl, Mstor, Cstor, Dstor;
}

void Planet::printPlanet()
{
	std::cout << x << ':'
		<< y << ':'
		<< z << ' '
		<< Mlvl << ' '
		<< Clvl << ' '
		<< Dlvl << ' '
		<< Plvl << ' '
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
	std::string sName;
	std::vector<Planet> vPlanet;

	Universe(std::string sName) : sName(sName) {}

	~Universe(){};

	std::vector<std::string> vsSanitizeData(std::vector<std::string>);
	void sort_x();
	void sort_y();
	void sort_z();
	void sort_Mlvl();
	void sort_Clvl();
	void sort_Dlvl();
	void sort_Plvl();
	void readCSV();
	void addPlanet(Planet);
	int splitString(std::string);

	void getUniverse();
	void printUniverse();
};

struct compare_x
{
	inline bool operator() (const Planet& left, const Planet& right)
	{
		return (left.x < right.x);
	}
};

struct compare_y
{
	inline bool operator() (const Planet& left, const Planet& right)
	{
		return (left.y < right.y);
	}
};

struct compare_z
{
	inline bool operator() (const Planet& left, const Planet& right)
	{
		return (left.z < right.z);
	}
};

struct compare_Mlvl
{
	inline bool operator() (const Planet& left, const Planet& right)
	{
		return (left.Mlvl < right.Mlvl);
	}
};

struct compare_Clvl
{
	inline bool operator() (const Planet& left, const Planet& right)
	{
		return (left.Clvl < right.Clvl);
	}
};

struct compare_Dlvl
{
	inline bool operator() (const Planet& left, const Planet& right)
	{
		return (left.Dlvl < right.Dlvl);
	}
};

struct compare_Plvl
{
	inline bool operator() (const Planet& left, const Planet& right)
	{
		return (left.Plvl < right.Plvl);
	}
};

void Universe::sort_x()
{
	std::sort(vPlanet.begin(), vPlanet.end(), compare_x());
}

void Universe::sort_y()
{
	std::sort(vPlanet.begin(), vPlanet.end(), compare_y());
}

void Universe::sort_z()
{
	std::sort(vPlanet.begin(), vPlanet.end(), compare_z());
}

void Universe::sort_Mlvl()
{
	std::sort(vPlanet.begin(), vPlanet.end(), compare_Mlvl());
}

void Universe::sort_Clvl()
{
	std::sort(vPlanet.begin(), vPlanet.end(), compare_Clvl());
}

void Universe::sort_Dlvl()
{
	std::sort(vPlanet.begin(), vPlanet.end(), compare_Dlvl());
}

void Universe::sort_Plvl()
{
	std::sort(vPlanet.begin(), vPlanet.end(), compare_Plvl());
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
	vPlanet.push_back(p);
}

void Universe::getUniverse()
{
	for (unsigned i = 0; i < vPlanet.size(); i++)
	{
		vPlanet[i].getPlanet();
	}
}

void Universe::printUniverse()
{
	std::cout << '\n';
	for (unsigned i = 0; i < vPlanet.size(); i++)
	{
		vPlanet[i].printPlanet();
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
	addPlanet(Planet(vTemp[0], vTemp[1], vTemp[2], vTemp[3], vTemp[4], vTemp[5], vTemp[6], vTemp[7], vTemp[8], vTemp[9])); // ugly

	return 0;
}

#endif