#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


struct Wind {
public:

	float WindSpeed;
	float MachineTemp;
	int PeakPower;
	int Status;
	string ID;
	string Region;
	string TempUnits;
	string SpeedUnits;
	int year, month, day, hour, minute, second;
};


class groupByRegion {
public:
	string name;
	vector<Wind> data;
};
