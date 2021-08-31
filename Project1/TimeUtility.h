#pragma once
// @brief Provides useful time functions for the assignment
// @author NMCG
// @usage demoTimeFunctions() in this file for demo code
// @see http://www.cplusplus.com/reference/ctime/strftime/

#include <stdexcept>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <ctime>
#include <chrono>
#include <vector>
#include <string>
using namespace std;
using namespace chrono;

//constants
const int MIN_YEAR = 1970; //minimum year that we can use to create a time_t object
const int YEAR_OFFSET = 1900; //all tm structs automatically refer to years from 1900 e.g. 2018 is stored as 118

//declarations
string format(const time_t& theTime);
string format(const time_t& theTime, const string& strFormat);
struct tm to_tm(const time_t& theTime);
time_t getTimeNow();
time_t getTime(int hour, int min, int secs, int date, int month, int year);
int compare(const time_t& a, const time_t& b);
bool sort(const time_t& a, const time_t& b);

//definitions
// @brief converts time_t to a string
string format(const time_t& theTime)
{
	//convert from time_t to struct tm
	struct tm theTimeAsStruct = to_tm(theTime);

	string strTime;

	//time - we need to call to_string
	strTime.append(to_string(theTimeAsStruct.tm_hour) + ":");
	strTime.append(to_string(theTimeAsStruct.tm_min) + ":");

	//space
	strTime.append(to_string(theTimeAsStruct.tm_sec) + " ");

	//date
	strTime.append(to_string(theTimeAsStruct.tm_mday) + "/");
	strTime.append(to_string(theTimeAsStruct.tm_mon) + "/");
	strTime.append(to_string(theTimeAsStruct.tm_year));

	return strTime;
}

// @brief converts time_t to a friendly string using a format (see link for formats)
string format(const time_t& theTime, const string& strFormat)
{
	//convert from time_t to struct tm
	struct tm theTimeAsStruct = to_tm(theTime);

	char buffer[256];

	//See http://www.cplusplus.com/reference/ctime/strftime/ for formats
	strftime(buffer, 256, strFormat.c_str(), &theTimeAsStruct);

	return string(buffer);
}

// @brief converts time_t to a tm struct
struct tm to_tm(const time_t& theTime)
{
	//a structure to store the infor from time_t theTime
	struct tm theTimeAsStruct;

	//convert the time_t to a struct tm so we can access individual channels
	localtime_s(&theTimeAsStruct, &theTime);

	return theTimeAsStruct;
}

// @brief gets current time as a time_t
time_t getTimeNow()
{
	return system_clock::to_time_t(system_clock::now());
}

// @brief converts friendly h, m, s, d, m, y to a time_t
// @note month range is 1-12
time_t getTime(int hour, int min, int date, int month, int year)
{
	if (year < MIN_YEAR)
		throw invalid_argument("Value of year cannot be less than " + MIN_YEAR);

	struct tm timeStruct = { 0 };
	timeStruct.tm_hour = hour;
	timeStruct.tm_min = min;
	timeStruct.tm_sec = 0;
	timeStruct.tm_mday = date;
	timeStruct.tm_mon = month - 1;
	timeStruct.tm_year = year - YEAR_OFFSET; //1900
	time_t t = mktime(&timeStruct);
	return t;
}

// @brief compares two time_t objects and returns -1 if a < b, +1 if a > b, otherwise 0
int compare(const time_t& a, const time_t& b)
{
	double diff = difftime(a, b); //worried about a float-point cast to int where d < 1

	if (diff < 0) //difftime(a, b) when a < b => -1
		return -1;
	else if (diff > 0)
		return 1;
	else
		return 0;
}

// @brief comparator used by std::sort to compare two time_t objects
bool comparatorSort(const time_t& a, const time_t& b)
{
	return difftime(a, b) <= 0 ? true : false;
}

// @brief demo of the datetime functions in this header file
void demoTimeFunctions() {
	/*******************************************************************************************/

	cout << "instanciate some time_t objects using our utility functions..." << endl;

	//make a time_t object representing my birthday on 14th Feb 1990 at 11:30
	time_t myBirthday = getTime(11, 30, 14, 1, 1990);

	//make a time_t object representing my birthday on 25th Dec 1982 at 16:30
	time_t yourBirthday = getTime(16, 30, 25, 11, 1982);

	//convert to a string
	cout << "My birthday:\t" << format(myBirthday) << endl;
	cout << "Your birthday:\t" << format(yourBirthday) << endl;

	cout << endl;

	/*******************************************************************************************/
	cout << "use some more exotic output formats for time_t ..." << endl;

	string strFormat;

	strFormat = "%H:%M:%S";
	cout << format(yourBirthday, strFormat) << endl;

	strFormat = "%c";
	cout << format(yourBirthday, strFormat) << endl;

	strFormat = "%A, %d %b %Y at %H:%M %p";
	cout << format(yourBirthday, strFormat) << endl;

	strFormat = "%x";
	cout << format(yourBirthday, strFormat) << endl;

	strFormat = "%X";
	cout << format(yourBirthday, strFormat) << endl;

	strFormat = "%x at %X %Z";
	cout << format(yourBirthday, strFormat) << endl;

	cout << endl;

	/*******************************************************************************************/

	cout << "compare some time_t objects using our utility functions..." << endl;

	//compare
	int c = compare(myBirthday, yourBirthday);

	if (c < 0)
		cout << "I'm older than you!" << endl;
	else if (c > 0)
		cout << "You're older than me!" << endl;
	else
		cout << "We're the same age...exactly!" << endl;

	cout << endl;

	/*******************************************************************************************/

	cout << "sort a vector of time_t objects using our utility functions..." << endl;

	//sort
	//make a time_t object representing my birthday on 1st July Dec 1970 at 9:45am
	time_t hisBirthday = getTime(23, 45, 14, 2, 1980);

	//add some to a vector
	vector<time_t> birthdayVector = { myBirthday, hisBirthday, yourBirthday };

	//the sort will expect a sort that takes two time_t and returns an integer i.e. sort
	std::sort(birthdayVector.begin(), birthdayVector.end(), comparatorSort);

	//print them out
	for (time_t dateTime : birthdayVector)
	{
		cout << format(dateTime, "%A, %d %b %Y at %H:%M:%S") << endl;
	}
}
