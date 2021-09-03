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
	//variables
};

//group region with vector 
class groupByRegion {
public:
	string name;
	vector<Wind> data;
};

class groupByRegionData {
public:
	void addData(groupByRegion& group)
	{
		data.push_back(group);
		// push elements into the back
	}
	vector<groupByRegion> data;
};
