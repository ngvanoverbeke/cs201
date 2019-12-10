// Nathan VanOverbeke
// CS201
// 12/8/19
// this handles the header data of agent.cpp

#include "enviroment.hpp"

class agent {
	public:
		int tempSet = 71;
		int temp;
		bool turnOn = false;
		
		void perceive(enviroment&env);
		void think();
		void act(enviroment& env);
};