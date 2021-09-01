#pragma once
#include <fstream>
#include <iostream>
using namespace std;

struct Wind {
public:
	char ID;
	long Peakpower;
	double MachineTemp;
	double windspeed;
	char speedunits;
	char date;
	char region;
	int hour;
	int min;
	int secs;
	bool isActive;

	Wind( char ID, long Peakpower, double MachineTemp, double windspeed, char speedunits, int hour, int min, int secs, char date, char region, bool isActive){
		this->ID - ID;
		this->Peakpower = Peakpower;
		this->MachineTemp = MachineTemp;
		this->windspeed = windspeed;
		this->speedunits = speedunits;
		this->hour - hour;
		this->min = min;
		this->secs = secs;
		this->date = date;
		this->region = region;
		this-> isActive = isActive;
	}

	
};
