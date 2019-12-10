// Nathan VanOverbeke
// CS201
// 12/8/19
// Simulator handles the user interaction and sort of acts as a fancy main; it choreographs almost everything within the rest of the program

#include "simulator.hpp"

// this is a fancy main; it is the only thing called by main and it manages most of the program
void simulator::run() {

	// initializes by welcoming the user and getting their starting preferences
	std::cout << "Welcome home!\n";
	std::cout << "The temperature is currently: " << env.temperature << "   and the thermostat is set to: " << agent.tempSet << std::endl;
	askOwner();

	while (true) {

		// prints the temps and thermostat data as long as this isn't the first run (as that was done in the init stage)
		if (count > 1)
		{ std::cout << "The temperature is currently: " << env.temperature << "   and the thermostat is set to: " << agent.tempSet << std::endl; }
		
		if (count % 10 == 0 && count > 1) {
			// checks in wither the user every 10 iterations
			askOwner();
		}

		// these pull the temp data, process it, and act on it respectively
		agent.perceive(env);
		agent.think();
		agent.act(env);

		// updates the room's temp(up if heater is on and down if it's off) and the counter
		env.iteration();
		count++;
	}
}

// this is where all interaction with the user takes place
void simulator::askOwner() {
	if (count > 2){
		std::cout << "would you like to exit? (if yes, \"y\", or \"n\" for no):	";
		char yesNo;
		std::cin >> yesNo;
		if ((yesNo == 'y') || (yesNo == 'Y')) { std::cout << "Goodbye!"; exit(0); }
	}

	std::cout << "Would you like to change the thermostat? (if yes, \"Y\", or \"N\" for no): ";
	char yesNo;
	std::cin >> yesNo;
	if ((yesNo == 'y') || (yesNo == 'Y')) {	
		std::cout << "Please enter the temperature you would like to set the thermostat to:  ";
		std::cin >> agent.tempSet;
	}
}