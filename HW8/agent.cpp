// Nathan VanOverbeke
// CS201
// 12/8/19
// the agent's job is to process information from the enviroment class and figure out how it should change the enviroment

#include "Agent.hpp"

void agent::perceive(enviroment& env) {
	temp = env.temperature;
}

void agent::think() {
	if (temp >= tempSet)
	{
		turnOn = false;
	}
	else
	{
		turnOn = true;
	}
}

void agent::act(enviroment& env) {
	if (turnOn)
	{
		env.heater = true;
	}
	else
	{
		env.heater = false;
	}
}