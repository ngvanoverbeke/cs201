// Nathan VanOverbeke
// CS201
// 12/8/19
// the agent's job is to process information from the enviroment class and figure out how it should change the enviroment

#include "Agent.hpp"

// pulls the current tempurature down and stores it in the class locally (but globaly)
void agent::perceive(enviroment& env) {
	temp = env.temperature;
}

// uses the information pulled down by agent.percieve to find the correct course of action
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

// uses a boolean value decided by angent.think to decide what to do
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