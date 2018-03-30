#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Pedro J. Navarrete
// V0.00

struct MinMax {
	int min;
	int max;
};

struct PlaneInfo {
	int landed;
	int departed;
	MinMax landingData;
};

const string MONTHS[] = { "January", "February", "March"};
// Given at  the Notes that the limit is 3 months
const int TLIMIT= 3;

int main() {
	cout << "Please enter the number of planes that landed in January:";
	cout << "Please enter the number of planes that departed in January:"
}