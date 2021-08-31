// @brief Demonstrates useful concepts for CA including data packing and alignment and use of smart pointers
// @author NMCG
// @see https://en.cppreference.com/w/cpp/language/types
// @seealso https://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
// @seealso https://www.cplusplus.com/doc/tutorial/files/

#include <iostream>
#include <fstream>
#include "TimeUtility.h"
using namespace std;

#pragma region Demo - Data Alignment & Packing

//bad!
struct SensorV1 { //32 bytes
	char type;
	int ID;
	int hour;
	int min;
	double voltage;
	bool isActive;
};

//bad!
struct SensorV2 { //32 bytes
	double voltage;
	char type;
	int ID;
	bool isActive;
	int hour;
	int min;
};

//bad!
struct SensorV3 { //32 bytes
	double voltage;
	char type;
	int ID;
	int hour;
	int min;
	bool isActive;
};

//better!
struct SensorV4 { //24 bytes
	double voltage;
	char type;
	bool isActive;
	int ID;
	int hour;
	int min;
};

//best!
//"@brief Using range appropriate and smaller data types (e.g. short vs int, float vs double)
struct SensorV5 { //12 bytes
	float voltage;
	short hour;
	short min;
	short ID;
	char type;
	bool isActive;
};

//"@brief Outputs the size in bytes of common C++ types
//"@see https://en.cppreference.com/w/cpp/language/types for an exhaustive list of all c++ types
//"@note The size of data types will be specific to YOUR platform (e.g. Solaris, AIX, HP-UX, Linux, macOS, BSD, and IBM)
void demoSizeOfTypes() {
	cout << typeid(bool).name() << " is " << sizeof(bool) << " bytes in size!" << endl;
	cout << typeid(char).name() << " is " << sizeof(char) << " bytes in size!" << endl;
	cout << typeid(short).name() << " is " << sizeof(short) << " bytes in size!" << endl;
	cout << typeid(int).name() << " is " << sizeof(int) << " bytes in size!" << endl;
	cout << typeid(int).name() << " is " << sizeof(int) << " bytes in size!" << endl;
	cout << typeid(long).name() << " is " << sizeof(long) << " bytes in size!" << endl;
	cout << typeid(float).name() << " is " << sizeof(float) << " bytes in size!" << endl;
	cout << typeid(double).name() << " is " << sizeof(double) << " bytes in size!" << endl;
}

//"@brief Demonstrates how your choice of data types and order of fields within a struct affect the size of the struct in memory
void demoStructAlignment() {
	//version 1
	SensorV1 s1;
	cout << typeid(s1).name() << " is" << sizeof(s1) << " bytes in size!" << endl;

	//version 2
	SensorV2 s2;
	cout << typeid(s2).name() << " is" << sizeof(s2) << " bytes in size!" << endl;

	//version 3
	SensorV3 s3;
	cout << typeid(s3).name() << " is" << sizeof(s3) << " bytes in size!" << endl;

	//version 4
	SensorV4 s4;
	cout << typeid(s4).name() << " is" << sizeof(s4) << " bytes in size!" << endl;

	//version 5
	SensorV5 s5;
	cout << typeid(s5).name() << " is" << sizeof(s5) << " bytes in size!" << endl;
}

#pragma endregion

int main()
{
	std::cout << endl << "************************* demoSizeOfTypes *************************" << endl;
	demoSizeOfTypes();

	std::cout << endl << "************************* demoStructAlignment *************************" << endl;
	demoStructAlignment();

	std::cout << endl << "************************* demoTimeFunctions *************************" << endl;
	demoTimeFunctions();
}