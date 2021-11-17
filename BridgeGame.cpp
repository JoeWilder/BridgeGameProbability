#include <iostream>
#include <vector>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


/* Return true 1/2 of the time */
bool fiftyPercent() {
	if (rand() % 2 != 0) {
		return(true);
	}
	else {
		return(false);
	}
}


/* Return true 2/3 of the time */
bool twoThirds() {
	if (rand() % 3 != 0) {
		return(true);
	}
	else {
		return(false);
	}
}


/* Return true 1/3 of the time */
bool oneThird() {
	if (rand() % 3 == 0) {
		return(true);
	}
	else {
		return(false);
	}
}


/* Run simulation with a probability of 1/2 */
void runFirstSimulation() {
	vector<int> results; // Store the results of each simulation
	int trialNumber = 0; // What section (step) the simulation is on
	int totalSteps = 18; // How many steps are in the bridge
	int success = 0; // How many times a player steps on a green tile
	int failure = 0; // How many times a player steps on a red tile
	int repeat = 10000; // Run the simulation this many times
	for (int x = 0; x < repeat; x++) {
		while (trialNumber != totalSteps) {
			if (fiftyPercent()) {
				success = success + 1;
			}
			else {
				failure = failure + 1;
			}
			trialNumber++;
		}
		cout << "Total successes: " << success << endl;
		cout << "Total failures: " << failure << endl;
		results.push_back(failure);
		success = 0;
		failure = 0;
		trialNumber = 0;
	}
	float average = (float)(accumulate(results.begin(), results.end(), 0)) / (float)(repeat);
	cout << "Average number of players needed to get across: " << average << endl;
}

/* Run simulation with a probability of 2/3 */
void runSecondSimulation() {
	vector<int> results; // Store the results of each simulation
	int trialNumber = 0; // What section (step) the simulation is on
	int totalSteps = 18; // How many steps are in the bridge
	int success = 0; // How many times a player steps on a green tile
	int failure = 0; // How many times a player steps on a red tile
	int repeat = 10000; // Run the simulation this many times
	for (int x = 0; x < repeat; x++) {
		while (trialNumber != totalSteps) {
			if (twoThirds()) {
				success = success + 1;
			}
			else {
				failure = failure + 1;
			}
			trialNumber++;
		}
		cout << "Total successes: " << success << endl;
		cout << "Total failures: " << failure << endl;
		results.push_back(failure);
		success = 0;
		failure = 0;
		trialNumber = 0;
	}
	float average = (float)(accumulate(results.begin(), results.end(), 0)) / (float)(repeat);
	cout << "Average number of players needed to get across: " << average << endl;
}

/* Run simulation with a probability of 1/3 */
void runThirdSimulation() {
	vector<int> results; // Store the results of each simulation
	int trialNumber = 0; // What section (step) the simulation is on
	int totalSteps = 18; // How many steps are in the bridge
	int success = 0; // How many times a player steps on a green tile
	int failure = 0; // How many times a player steps on a red tile
	int repeat = 10000; // Run the simulation this many times
	for (int x = 0; x < repeat; x++) {
		while (trialNumber != totalSteps) {
			if (oneThird()) {
				success = success + 1;
			}
			else {
				failure = failure + 1;
			}
			trialNumber++;
		}
		cout << "Total successes: " << success << endl;
		cout << "Total failures: " << failure << endl;
		results.push_back(failure);
		success = 0;
		failure = 0;
		trialNumber = 0;
	}
	float average = (float)(accumulate(results.begin(), results.end(), 0)) / (float)(repeat);
	cout << "Average number of players needed to get across: " << average << endl;
}


/* Driver code */
int main() {
	srand(time(0));
	int userInput = 10;
	while (userInput != 4) {
		cout << "Choose an option: \n"
			<< "1 - Simulation 1\n"
			<< "2 - Simulation 2\n"
			<< "3 - Simulation 3\n"
			<< "4 - End program\n";
		cin >> userInput;
		while (!cin) { // Make sure the input is not a string
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid option, please enter an integer\n";
			cin >> userInput;
		}
		if (userInput == 1) {
			runFirstSimulation();
		}
		else if (userInput == 2) {
			runSecondSimulation();
		}
		else if (userInput == 3) {
			runThirdSimulation();
		}
		else if (userInput != 4) {
			cout << "Invalid option. Please enter an integer between 1 and 4\n";
		}
	}
}
