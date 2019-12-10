// Nathan VanOverbeke
// CS201
// 12/8/19
// this simply handles all the required header data of simulator.cpp

#include "enviroment.hpp"
#include "agent.hpp"

#include <iostream>

class simulator {
public:
	bool exit = false;
	int count = 0;
	void run();
	void askOwner();
	enviroment env;
	agent agent;
};