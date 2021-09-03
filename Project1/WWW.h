#pragma once
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
/// @brief this code taken from lecture video explaining variables
struct Wind {
public:

	float WindSpeed;
	float MachineTemp;
	int PeakPower;
	bool isActive;
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
//store region in data
};

class groupByRegionData {
public:
	void addData(groupByRegion& group)
	{
		data.push_back(group);
		// push elements into the back into vector
	}
	vector<groupByRegion> data;
	string src;
};
