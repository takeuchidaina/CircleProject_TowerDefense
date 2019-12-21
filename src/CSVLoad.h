#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#ifndef _CSVLOAD_INCLUDE_
#define _CSVLOAD_INCLUDE_
using namespace std;

vector<vector<double>> CSVLoad(string& _fileName);
vector<string> split(string str, char del);

typedef struct
{
	int ID;
	int type;
	int HP;
	int ATK;
	double speed;
	int coolTime;
	int DEF;
	string unitPath;
	string effectPath;
}sUnitLoad;

vector<sUnitLoad> UnitLoad(string& _filePath);

#endif _CSVLOAD_INCLUDE_