// Nathan VanOverbeke
// CS201
// 12/8/19
// Simulator handles the user interaction and sort of acts as a fancy main; it choreographs almost everything within the rest of the program

#include "simulator.hpp"

// this is a fancy main; it is the only thing called by main and it manages most of the program
void simulator::run() {
	std::cout << "Welcome home!\n";
	std::cout << "The temperature is currently: " << env.temperature << "   and the thermostat is set to: " << agent.tempSet << std::endl;
	askOwner();

	while (true) {
		if (count > 1)
		{ std::cout << "The temperature is currently: " << env.temperature << "   and the thermostat is set to: " << agent.tempSet << std::endl; }
		
		if (count % 10 == 0 && count > 1) {
			askOwner();
		}
		agent.perceive(env);
		agent.think();
		agent.act(env);
		env.iteration();
		count++;
	}
}

// this is where all interaction with the user takes place
void simulator::askOwner() {
	if (count > 2){
		std::cout << "would you like to exit? (enter 0 for no and 1 for yes):	";
		int yesNo;
		std::cin >> yesNo;
		if (yesNo == 1) { EXIT_SUCCESS; }
	}

	std::cout << "Would you like to change the thermostat? (if yes, \"Y\", or \"N\" for no): ";
	char yesNo;
	std::cin >> yesNo;
	if ((yesNo == 'y') || (yesNo == 'Y'))
	{	
		std::cout << "Please enter the temperature you would like to set the thermostat to:  ";
		std::cin >> agent.tempSet;
	}
}