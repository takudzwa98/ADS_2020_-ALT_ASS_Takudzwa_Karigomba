#pragma once
#include <iostream>
#include <fstream>

struct SensorV1 { //32 bytes
	char ID;
	long Peakpower;
	double MachineTemp;
	double windspeed;
	char speedunits;
	double date;
	long time;
	char region;
	int hour;
	int min;
	bool isActive;
};
