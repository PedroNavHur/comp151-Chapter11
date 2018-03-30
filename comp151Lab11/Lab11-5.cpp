#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Pedro J. Navarrete
// V0.00

const string MONTHS[] = {
	"January", "February", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December" };

// Struct Airport
struct Airport {
	int landed;
	int departed;
	int maxLanDay;
	int minLanDay;
	void getMonthData(int month);
};

struct AirportData {
	float landingsAverage;
	float departuresAverage;
	int totalLandings;
	int totalDepartures;
	int maxLanding;
	int maxLandingMonth;
	int minLanding;
	int minLandingMonth;
	void getAirportData(const Airport airport[], int n);
	void showAirportData();
};

// Airport getMonth function
void Airport::getMonthData(int month) {
	cout << "Please enter the number of planes that landed in " << MONTHS[month] << ":\n";
	cin >> landed;
	cout << "Please enter the number of planes that departed in " << MONTHS[month] << ":\n";
	cin >> departed;
	cout << "Please enter the least number of planes that landed on a single day in " << MONTHS[month] << ":\n";
	cin >> maxLanDay;
	cout << "Please enter the least number of planes that landed on a single day in " << MONTHS[month] << ":\n";
	cin >> minLanDay;
}

void AirportData::getAirportData(const Airport airport[], int n){
	totalLandings = 0;
	totalDepartures = 0;
	maxLanding = airport[0].maxLanDay;
	minLanding = airport[0].minLanDay;
	maxLandingMonth = 0;
	minLandingMonth = 0;

	for (int i = 0; i < n; i++){
		// Get total landings & Departures
		totalLandings += airport[i].landed;
		totalDepartures += airport[i].departed;

		// Get Min Day Landing 
		if (airport[i].maxLanDay > maxLanding){
			maxLanding = airport[i].maxLanDay;
			maxLandingMonth = i;
		}

		// Get Max Day Landing
		if (airport[i].minLanDay < minLanding){
			minLanding = airport[i].minLanDay;
			minLandingMonth = i;
		}

	}

	// Get landing & departures averages
	landingsAverage = (float)totalLandings / n;
	departuresAverage = (float)totalDepartures / n;
}

void AirportData::showAirportData(void){
	cout << fixed << showpoint << setprecision(2); 
	cout << "The average monthly landings is " << landingsAverage << ".\n";
	cout << "The average monthly departures is " << departuresAverage << ".\n";
	cout << "The total landings is " << totalLandings << ".\n";
	cout << "The total departures is " << totalDepartures << ".\n";
	cout << "The greatest number of planes that landed in a single day is " << maxLanding
		 << " which occured in " << MONTHS[maxLandingMonth] << ".\n";
	cout << "The least number of planes that landed in a single day is " << minLanding
		 << " which occured in " << MONTHS[minLandingMonth] << ".\n";
}

// Given at the Notes that the limit is 3 months
const int MLIMIT = 3; // MAX 12 (because there are 12 months)

int main() {

	Airport airport[MLIMIT];
	AirportData data;

	// Get the Airport Data
	for (int i = 0; i < MLIMIT; i++){
		airport[i].getMonthData(i);
	}

	// Get the Airport Calculated Data
	data.getAirportData(airport,MLIMIT);

	// Show the Aiport Calculated Data
	data.showAirportData();





}