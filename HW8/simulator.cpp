// Nathan VanOverbeke
// CS201
// 12/8/19
// Simulator handles the user interaction and sort of acts as a fancy main; it choreographs almost everything within the rest of the program

#include "simulator.hpp"

void simulator::run() {
	/*std::cout << "Welcome home! the temperature is currently " << env.temperature << "\nand the thermostat is set to: " << agent.tempSet << std::endl;
	std::cout << "Would you like to change the thermostat? (if yes, \"Y\", or \"N\" for no): ";
	char yesNo;
	std::cin >> yesNo;
	if (yesNo == 'y')
	{
		std::cout << "Please enter the temp. you would like to set the thermostat to:  ";
		std::cin >> agent.tempSet >> std::endl;
	}*/
	std::cout << "Welcome home!\n";
	askOwner();

	while (exit == false) {
		std::cout << "The temperature is: " << env.temperature << "		And the thermostat is set to: " << agent.tempSet << std::endl;
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

void simulator::askOwner() {
	if (count > 2){
		std::cout << "would you like to exit? (enter 0 for no and 1 for yes):	";
		int yesNo;
		std::cin >> yesNo;
		if (yesNo == 1) { exit = true; }
	}

	if (exit == false && count % 10 != 0) {
		std::cout << "The temperature is currently: "<< env.temperature << "\nand the thermostat is set to: " << agent.tempSet << std::endl;
	}
	std::cout << "Would you like to change the thermostat? (if yes, \"Y\", or \"N\" for no): ";
	char yesNo;
	std::cin >> yesNo;
	if ((yesNo == 'y') || (yesNo == 'Y'))
	{	
		std::cout << "Please enter the temp. you would like to set the thermostat to:  ";
		std::cin >> agent.tempSet;
	}
}