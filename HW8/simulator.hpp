// Nathan VanOverbeke
// CS201
// 12/8/19
// this simply handles all the required header data of simulator.cpp

#include "enviroment.hpp"
#include "agent.hpp"

#include <iostream>

class simulator {
public:
	int count = 0;

	void run();
	void askOwner();

	// these are local instances of the given classes so that they can be used/accessed
	enviroment env;
	agent agent;
};